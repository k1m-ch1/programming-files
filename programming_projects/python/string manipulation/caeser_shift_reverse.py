import string
input_str_rev = """
E swjp ywhhejc/pwhgejc sepd ukq ok iqyd. Xqp e zkjp gjks sdwp pk pwhg wxkqp
"""
num_of_alphabet = len(string.ascii_lowercase)
for i in range(27):
    key = i
    l = [string.ascii_lowercase, string.ascii_uppercase]
    output = ''.join([l[string.ascii_letters.index(char)//num_of_alphabet][(l[string.ascii_letters.index(char)//num_of_alphabet].index(char) - key)%num_of_alphabet]  if char in string.ascii_letters else char for char in input_str_rev])
    print(f"key: {i}", output)