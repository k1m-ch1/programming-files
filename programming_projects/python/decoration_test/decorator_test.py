def wrapper_func(func):
  def ret_func(*args, **kwargs):
    print("This is the beginning of the wrapper")
    func(*args, **kwargs)
    print("This is the end of the wrapper")
  return ret_func



@wrapper_func
def print_with_wrapper(my_str):
  print(my_str)

print_with_wrapper("Kinda nervous rn ngl")