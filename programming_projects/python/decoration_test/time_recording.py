import time
import math

def record_time(func):
  def ret_func(*args, **kwargs):
    start = time.time()
    ret_val = func(*args, **kwargs)
    end=time.time()
    print(f"The function finished in {end-start} seconds")
    return ret_val
  return ret_func

def wrapper_with_args(func, starting_str, ending_str):
  def ret_func(*args, **kwargs):
    print(starting_str)
    ret_val = func(*args, **kwargs)
    print(ending_str)
    return ret_val
  return ret_func
  

@record_time
def count_to(to_number):
  print(f"Counting to {to_number}")
  for i in range(to_number):
    pass

my_newest_str = wrapper_with_args(count_to, "Initialting func", "Ending of func")

record_time(count_to)(9_999_999)
my_newest_str(9999999)

