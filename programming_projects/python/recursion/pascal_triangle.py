import re, math
def get_pascal(depth):
  if depth == 0:
    return [1]
  elif depth == 1:
    return [1,1]
  prev_pascal = get_pascal(depth-1)
  ret_list = [1]
  for index in range(1, len(prev_pascal)):
    ret_list.append(prev_pascal[index-1]+prev_pascal[index])
  ret_list.append(1)
  return ret_list

def get_polynomial(a, operator, b, power):
  if operator not in {'-', '+'}:  return None
  pascal_triangle = get_pascal(power)
  ret_val, bigger_list = [], []
  for i in range(power+1):
    ret_val.append(f"{pascal_triangle[i]}({a}^{power-i})({b}^{i})")
  for i in ret_val:
    first_val = re.search(r'([0-9]+)\((.+)\)\((.+)\)', i)
    temp_list = list()
    for j in first_val.groups():
      if re.search(r'^[0-9]+$', j) != None:
        thing = (re.search(r'(^[0-9]+$)', j)).group(1)
        temp_list.append(thing)
      elif re.search(r'[0-9]+\^[0-9]+$', j) != None:
        thing_one = re.search(r'([0-9]+)\^([0-9]+$)', j)
        temp_list.append(math.pow(int(thing_one.group(1)), int(thing_one.group(2))))
    sum = 1
    for stuff in temp_list:
      sum *= int(stuff)
    bigger_list.append(sum)
  return list(zip(ret_val, bigger_list))

result= get_polynomial('-3', '+' , '-x', 8)
for i in result:
  print(i)
