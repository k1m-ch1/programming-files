def fibonacci(term):
  list_of_fib_sequence = [0,1]
  if term == 1:
    return list_of_fib_sequence[:1]
  elif term == 2:
    return list_of_fib_sequence
  for i in list(range(term))[2:]:
    list_of_fib_sequence.append(list_of_fib_sequence[-1] + list_of_fib_sequence[-2])
  
  return list_of_fib_sequence

def printFiboTerm(term):
  if term % 10 == 1:
    ordinal = 'st'
  elif term % 10 == 2:
    ordinal = 'nd'
  elif term % 10 == 3:
    ordinal = 'rd'
  else:
    ordinal = 'th'
  result = fibonacci(term)
  print("The {}{} term of the fibonacci sequence is {}".format(term, ordinal, result[-1]))
  return result

result_string = ""
list_temp = printFiboTerm(1001)
for i in range(len(list_temp)):
  i = i + 1
  if (i) % 10 == 1:
    ordinal = 'st'
  elif (i) % 10 == 2:
    ordinal = 'nd'
  elif (i) % 10 == 3:
    ordinal = 'rd'
  else:
    ordinal = 'th'
  result_string = result_string + "\nThe {}{} term of the fibonacci sequence is {}".format(i, ordinal, list_temp[i-1])

with open('.//python//misc//fibonacci_sequence.txt', 'w') as file:
  file.write(result_string)