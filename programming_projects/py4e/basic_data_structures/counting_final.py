import counting
import random

my_list = counting.create_rand_list(10, 0, 5)

print(my_list)
my_dict = dict()
for i in my_list:
  if (i in my_dict) == False:
    my_dict[i] = 1
  else:
    my_dict[i] = my_dict[i] + 1

for key, value in my_dict.items():
  print(key, ": ", end="")
  for i in range(value):
    print("|", end="")
  print("")