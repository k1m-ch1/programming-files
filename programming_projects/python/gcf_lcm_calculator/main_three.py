import time

def find_lcm(list_of_args):
  counter, total_dict = 0, {}
  while True:
    counter += 1
    for i in list_of_args:
      total_dict[i*counter] = total_dict.get(i*counter, 0) + 1
      if total_dict[i*counter] >= len(list_of_args): return i*counter

prev_time = time.time()
print(find_lcm([10,10,10,10,10,10,10]))
print("[Program finished in {} seconds]".format(time.time()-prev_time))
    
