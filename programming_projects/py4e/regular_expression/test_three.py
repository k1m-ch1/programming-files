import re

with open("email.txt", 'r') as file:
  my_string = file.read()
  my_obj = re.compile(r'[A-Za-z]{3,10}\s[A-Za-z]{5,10}')
  my_other_obj = my_obj.finditer(my_string)
  for i in my_other_obj:
    print(i)