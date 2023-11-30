def addition(array):
    total = 0
    for i in array:
        total = total + i
    return total

def isOdd(x):
  x = abs(x)
  if x%2 == 0:
    return False
  else:
    return True

def solve(arr):
    result_arr = list()
    temp_arr = list()
    temp_num = 0
    for i in range(len(arr)):
        difference = abs(len(arr) - i)
        for j in range(i+1):
            temp_arr = arr[j:(difference+j)]
            temp_num = addition(temp_arr)
            if isOdd(temp_num):
              result_arr.append(temp_arr)
    return result_arr
