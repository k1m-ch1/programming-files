
convert_b10_2_b2 = lambda n: '' if n == 0 else convert_b10_2_b2(n//2) + str(n%2)
print(convert_b10_2_b2(2**996))