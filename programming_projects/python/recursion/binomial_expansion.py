import re, math
import string

def get_pascal(depth):
  """Find the base of a pascal triangle. Input an integer and get a list."""
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

def get_polynomial(a, b, power,operator='+'):
  if operator not in {'-', '+'}:  return None # Useless code
  pascal_triangle = get_pascal(power)
  ret_val, bigger_list = [], []
  for i in range(power+1):
    ret_val.append(f"{pascal_triangle[i]}({a}^{power-i})({b}^{i})")
  for i in ret_val:
    first_val = re.search(r'([0-9]+)\((.+)\)\((.+)\)', i)
    temp_list = list()
    for j in first_val.groups():
      if re.search(r'^[-0-9]+$', j) != None:
        thing = (re.search(r'(^[-0-9]+$)', j)).group(1)
        temp_list.append(thing)
      else:
        first_number = re.search(r'([0-9-]+)', j).group(1)
        power_of = re.search(r'\^([0-9-]+)', j).group(1)
        temp_list.append(math.pow(int(first_number), int(power_of)))
    sum = 1
    for stuff in temp_list:
      sum *= int(stuff)
    bigger_list.append(sum)
  return list(zip(ret_val, bigger_list))

def get_user_input_variable():
  first_variable, second_variable, power_of = None, None, None
  while None in (first_variable, second_variable, power_of):
    if "help" in (first_variable, second_variable, power_of):
      print("\nFor example if you want to input (2+x)^6, You input 2 as first, 1x as second and 6 as power.\nIf you want to input (2-x)^6, you input 2 then -1x then 6")
      print("Resetting inputs...\n-----------------\n\n")
      first_variable, second_variable, power_of = None, None, None
    if first_variable in (None, ''):
      first_variable = input("Enter your first variable: ").lower()
    elif second_variable in (None, ''):
      second_variable = input("Enter your second variable: ").lower()
    else:
      power_of = input("Your binomial raised to the power of: ").lower()
  return (first_variable, second_variable, int(power_of))

user_input = get_user_input_variable()
print(f"Your result for the binomial (({user_input[0]})+({user_input[1]}))^{user_input[2]} is:\n")
for i in get_polynomial(user_input[0], user_input[1], user_input[2]):
  print(i)
      

