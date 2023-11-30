import time

def fibonnaci_sequence(x):
  if x == 0:
    return 0
  elif x == 1:
    return 1
  elif type(x) != type(1):
    return None
  else:
    return fibonnaci_sequence(x-2) + fibonnaci_sequence(x-1)
all_fib = {}
def fibonacci_sequence_faster(x):
  global all_fib
  if x == 0:
    return 0
  elif x == 1:
    return 1
  elif type(x) != type(1):
    return None
  else:
    term_before_x = all_fib.get(x-1)
    if term_before_x == None: all_fib[x-1] = fibonacci_sequence_faster(x-1)
    term_before_before_x = all_fib.get(x-2)
    if term_before_before_x == None: all_fib[x-2] = fibonacci_sequence_faster(x-2)
    term_before_x, term_before_before_x = all_fib[x-1], all_fib[x-2]
    return term_before_x + term_before_before_x

prev_time = time.time()
print(fibonacci_sequence_faster(990))
# print(fibonnaci_sequence(35))
print("[Finished in {}]".format(time.time()-prev_time))