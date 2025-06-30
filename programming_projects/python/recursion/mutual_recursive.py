def is_odd(n):
  """Check whether a number is odd or not.

  Args:
      n (Integer): A discrete number.
  Return:
      (Boolean): The answer to whether it is odd or not.
  """
  if n == 0: return False # The base case. 0 is not an odd number.
  return is_even(n-1) # Uses the condition that n is odd if n-1 is even.

def is_even(n):
  """Check whether a number is even or not.

  Args:
      n (Integer): A discrete number.
  Return:
      (Boolean): The answer to whether it is even or not.
  """
  if n == 0: return True # The base case. 0 is an even number.
  return is_odd(n-1) # Uses the condition that n is even if n-1 is odd.

my_num = 20
match my_num:
  case 10:
    print("Ten")
  case 1:
    print("ONe")
  case 20:
    print("Twenty")