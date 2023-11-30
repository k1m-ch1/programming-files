import math
def find(low, high, find_num):
  def find_util(low, high, count):
    count += 1
    mean = (low+high)/2
    if round(mean, 100) == find_num:
      return mean, count
    if mean > find_num:
      return find_util(low,mean, count)
    elif mean < find_num:
      return find_util(mean, high, count)
  return find_util(low, high, 0)

my_result = find(0, 1000000000, 52340)
print(my_result)