import string
input_str_rev = """
B'f lh rhngz tgw rhn'kx lh hew
Mabl, fr wtkebgz, B'ox uxxg mhew
B whg'm vtkx cnlm patm maxr ltr
'Vtnlx yhkxoxk B pbee iktr
Rhn tgw B pbee ux tl ykxx
Tl max ubkwl ni bg max mkxxl
Ha, iextlx lmtr ur fx, Wbtgt
"""
num_of_alphabet = len(string.ascii_lowercase)
key = len(input_str_rev.split()) % num_of_alphabet
l = [string.ascii_lowercase, string.ascii_uppercase]
output = ''.join([l[string.ascii_letters.index(char)//num_of_alphabet][(l[string.ascii_letters.index(char)//num_of_alphabet].index(char) - key)%num_of_alphabet]  if char in string.ascii_letters else char for char in input_str_rev])
print(output)