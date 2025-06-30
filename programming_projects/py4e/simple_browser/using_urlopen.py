from urllib import request

ret_val = request.urlopen('https://ocw.mit.edu/ans7870/6/6.006/s08/lecturenotes/files/t8.shakespeare.txt')
with open(r'.\shakesphere.txt', 'w') as file:
  file.write(ret_val.read().decode())