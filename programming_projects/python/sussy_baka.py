
alphabets = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 
            'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 
            'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']
alphabets_string = "abcdefghijklmnopqrstuvwxyz"
word_input = input("Input word without spaces and with all lowercase: ")
word_input = word_input.lower()
input_len = len(word_input)
sum = 0
for i in range(input_len):
    current_char = word_input[i]
    power_of = input_len - i - 1
    sum = pow(26, power_of) * (alphabets_string.find(current_char)+1) + sum

print(sum)

