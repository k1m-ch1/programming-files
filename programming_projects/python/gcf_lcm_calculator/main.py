def check_list_in_list(list_of_tuple):
  total = list()
  for i in list_of_tuple:
    total.extend(i[1])
  total.sort()
  for i in range(len(total)-len(list_of_tuple)):
    for j in range(len(list_of_tuple)-1):
      if total[i+j] == total[i+j+1]:
        pass
      else:
        return False
  return True

def find_lcm(list_of_ints):
  if type(list_of_ints) != type([]):  return None
  all_factors = [x for x in list_of_ints]
  for i in range(len(all_factors)):
    all_factors[i] = (all_factors[i],set())
  #all_factors contains number name at index = 0 and multiplier at index = 1
  count = 0
  while not check_list_in_list(all_factors):
    count += 1
    for i in range(len(all_factors)):
        all_factors[i][1].add(all_factors[i][0]*count)
  return all_factors


print(find_lcm([10,20,30,40,50,60,70,80,90, 100]))
    
