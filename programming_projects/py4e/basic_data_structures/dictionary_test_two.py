import counting
import random

new_list = counting.create_rand_list(10, 0, 10)

my_dictionary = {"beat": 12, "chemical": 21, "moment": 90}

print("beat" in my_dictionary)
print(my_dictionary["beat"])
my_dictionary["beat"] = my_dictionary["beat"] + 1
print(my_dictionary["beat"])

my_dictionary["medical"] = 32

print(my_dictionary["medical"])
print(len(my_dictionary))

for key, value in my_dictionary.items():
  print(key, value)