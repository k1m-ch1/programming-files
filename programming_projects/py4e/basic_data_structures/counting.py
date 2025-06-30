import random

def create_rand_list(size, lowest, highest):
  """Returns a list of randomly generated integers. Args (size, low, high)
  """
  return_list = []
  for i in range(size):
    return_list.append(random.randint(lowest, highest))
  
  return return_list


if __name__ == '__main__':
  my_list = create_rand_list(20, 0, 20)
  print(f"This list is of size {len(my_list)} and contains \n {my_list}")
