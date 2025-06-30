import re

def simplify(my_raw_string, my_string):
  temp_obj = re.compile(my_raw_string)
  iter_obj = temp_obj.finditer(my_string)
  for i in iter_obj:
    print(i.group())


def print_phone_number(my_string):
  simplify(r'\d{3}.\d{3}.\d{4}', my_string)
def print_email(my_string):
  simplify(r'[\w]+@[\w]+', my_string)
def print_address(my_string):
  simplify(r'[\d]+\s[\w]+\s[\w]+\.,\s[\w-]+\s[A-Z]{2}\s[\d]+', my_string)

file_handle = open('email.txt', 'r')
# print_email(file_handle.read())
print_address(file_handle.read().rstrip())