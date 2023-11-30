def apply_func(subject, *args):
  if len(args) == 1:
    args = args[0]
  if len(args) == 1:
    return args[0](subject)
  else:
    new_stuff = apply_func(subject, args[1:])
    new_stuff = args[0](new_stuff)
    return new_stuff
  
def add_three(x):
  return x + 3

def add_four(x):
  return x + 4

def add_five(x):
  return x + 5

def add_two(x):
  return x + 2

new_function = apply_func(1, add_two, add_three, add_four, add_five)
print(new_function)
