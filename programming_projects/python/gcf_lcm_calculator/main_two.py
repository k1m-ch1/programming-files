def check(max_num, list_to_compare):
  for i in list_to_compare:
    can_divide = [x for x in i if x >= max_num and x % max_num == 0]
      

def find_lcm(numbers):
  """Get a list of numbers to check for their lowerest common multiplier"""
  max_number, numbers, all_factor = max(numbers), set(numbers), list()
  numbers.remove(max_number)
  for i in numbers: all_factor.append((i, set()))
  while not check(max_number, all_factor):
    pass
  print(all_factor)
    