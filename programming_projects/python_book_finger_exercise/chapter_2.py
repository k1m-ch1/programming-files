x,y,z = 3,12,91
if x%2 == 0 and y%2==0 and z%2==0:
  print("None of them are odd")
elif x%2 != 0:
  if y%2 == 0 and z%2 == 0:
    print("X is the greatest odd")
  elif y%2 != 0 and y > x and y > z:
    print("Y is the greatest odd")
  elif z%2 != 0 and z > x and z > y:
    print("Z is the greatest odd")
  elif z > x:
    print("Z is the greatest odd")
  else:
    print("X is the greatest odd")
elif y%2 != 0:
  if z%2 == 0:
    print("Y is the greatest odd")
  elif y > z:
    print("Y is the greatest")
  else:
    print("Z is the greatest")
else:
  print("Z is the greatest")
    