import string
with open('./input_txt.txt', 'r') as file:
    input_str = file.read()
num_of_alphabet = len(string.ascii_lowercase)
key = len(input_str.split()) % num_of_alphabet
l = [string.ascii_lowercase, string.ascii_uppercase]
output = ''.join([l[string.ascii_letters.index(char)//num_of_alphabet][(l[string.ascii_letters.index(char)//num_of_alphabet].index(char) + key)%num_of_alphabet]  if char in string.ascii_letters else char for char in input_str])
print(output)