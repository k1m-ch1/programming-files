import math
array = []
n = int(input(": "))
first_num = 1/(math.sqrt(5))
second_num = first_num * (math.pow((1+math.sqrt(5))/2, n) - first_num*math.pow((1-math.sqrt(5))/2, n))               

print(f"The {n} of the fibonacci sequence is {second_num}")
