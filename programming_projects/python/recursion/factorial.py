def factorial_recursion(x):
  if x == 0 or type(x) != type(int()):
    return 0
  elif x == 1:
    return 1
  else:
    return x * factorial_recursion(x-1)

def print_right_triangles(x):
  if x <= 0:
    return None
  else:
    print_right_triangles(x-1)
  try:
    for i in range(int(x)):
      print("*", end="")
    print("")
  except:
    return None

print_right_triangles(10)