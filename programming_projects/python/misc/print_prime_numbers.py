import time

def isPrime(x):
  """Check whether this number is prime or not.
  
  >>> isPrime(5)
  True"""
  x = abs(x)
  if x == 0 or x == 1:
    return False
  for i in range(x):
    if i == 0 or i == 1:
      continue
    elif x % i == 0:
      return False
  else:
    return True

start_time = time.time()  
list_of_prime_numbers = list()
num_to_input = 100000
for i in range(num_to_input):
  is_prime_var = isPrime(i)
  if is_prime_var:
    list_of_prime_numbers.append(i)
result_as_string = ""
for i in range(len(list_of_prime_numbers)):
  result_as_string = f"{result_as_string}{str(list_of_prime_numbers[i])}, "
  if (i+1)%15 == 0:
    result_as_string = result_as_string + "\n" 
PATH = 'C:\\Users\\Kimchour\\Documents\\programming_projects\\python\\misc\\prime_numbers.txt'
with open(PATH, 'w') as file:
  file.write("The list of prime numbers until {} contains \n".format(num_to_input) + result_as_string)
end_time = time.time()
print(f"\nThe time taken to run this program is {end_time-start_time}")

with open(PATH, 'a') as file:
  file.write(f"\nThe time taken to run this program is {end_time-start_time}")





    