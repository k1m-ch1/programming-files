import time

start_time = time.time()
def isPrimeFast(check, check_on):
  if check == 1 or check == 0:
    return False
  for i in check_on:
    if i == 1 or i == 0:
      continue
    elif check % i == 0:
      return False
  return True

def primeUpTo(check):
  input_list = list()
  for i in range(check):
    if isPrimeFast(i, input_list) == True:
      input_list.append(i)
  return input_list
num_to_input = 200000
new_list = primeUpTo(num_to_input)
result = ""
counter = 0
for i in new_list:
  counter += 1
  result = f"{result}{i}, "
  if counter % 15 == 0:
    result = result + "\n"

with open('C:\\Users\\Kimchour\\Documents\\programming_projects\\python\\misc\\prime_nums_faster.txt', 'w') as file:
  file.write("The list of prime numbers until {} contains \n {}".format(num_to_input, result))

end_time = time.time()
print("\nThis program took a total of {} seconds to run".format(end_time-start_time))

with open('C:\\Users\\Kimchour\\Documents\\programming_projects\\python\\misc\\prime_nums_faster.txt', 'a') as file:
  file.write("\nThis program took a total of {} seconds to run".format(end_time-start_time))
