move_tower = lambda fr, to: print("Move from {} to {}".format(fr, to))

write_tower = lambda fr, to: str("Move from {} to {}\n".format(fr, to))

def solve_hanoi_tower(n, fr,other,to):
  if n == 0:
    return
  if n == 1:
    move_tower(fr, to)
  else:
    solve_hanoi_tower(n-1, fr, to, other)
    move_tower(fr, to)
    solve_hanoi_tower(n-1, other, fr, to)

def hanoi_towers_to_file(n, fr, other, to, file_handle):
  if n == 0:
    return
  if n == 1:
    file_handle.write(write_tower(fr, to))
  else:
    hanoi_towers_to_file(n-1, fr, to, other, file_handle)
    file_handle.write(write_tower(fr, to))
    hanoi_towers_to_file(n-1, other, fr, to, file_handle)

path = 'hanoi_towers_text.txt'
# open(path, 'a').write(hanoi_towers_to_file(3, 1, 2, 3))
# temp_string = ""
# for i in range(10):
#   temp_string += "Hello, world!\n"

# open(path, 'a').write(temp_string)
file_handle = open(path, 'a')
for i in range(1,10):
  file_handle.write("n = {}\n".format(i))
  hanoi_towers_to_file(i, 1, 2, 3, file_handle)
file_handle.close()


    

