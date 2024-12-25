import string

with open('./input_txt.txt', 'r') as file:
    input_txt = file.read().lower()
    char_freq_list = [(char, input_txt.count(char)) for char in string.ascii_lowercase]
    for c in char_freq_list:
        print(f"{c[0]}:"+"|"*c[1])

