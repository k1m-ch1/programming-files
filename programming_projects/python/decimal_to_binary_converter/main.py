import math
import sys
def convert(decimal_number):
  final_string = []
  decimal_number = int(abs(decimal_number))
  while not (decimal_number <= 1):
    final_string.append(decimal_number % 2)
    decimal_number = decimal_number// 2
  final_string.append(decimal_number)
  final_string.reverse()
  return convert_list_to_string(final_string)

def convert_list_to_string(my_list):
  return_string = ""
  for i in my_list:
    return_string = return_string + str(i)
  return return_string

input_data = int(sys.argv[1])
print(convert(input_data))
try:
  print(math.log(input_data, 2))
except:
  print("can't log zero")  
    
