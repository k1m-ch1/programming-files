import random

numbers = list()

for i in range(1000):
    numbers.append(i+1)

random.shuffle(numbers)
threashold = 15
j = 0
for i in numbers:
    j = j+1
    print(str(i) + ", ", end="")
    if  j >= threashold:
        threashold = threashold + 15
        print("\n", end="")
