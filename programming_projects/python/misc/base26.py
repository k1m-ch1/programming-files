from string import ascii_letters
from functools import reduce
from operator import add
BASE26 = ascii_letters[26:]
convert_to_base_10 = lambda base_26_number: reduce(add, [BASE26.index(j)*(26**(i)) for i, j in enumerate(base_26_number[::-1])])
print("Convert base 26 to base 10 (base 26 is represented as the characters of the english alphabet)")
print(f"\nResult: {convert_to_base_10(input('Enter your number: ').upper())}")


