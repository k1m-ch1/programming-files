x = 1
y = 2
a = x
b = y
def enter_value(num_1, num_2):
    print(f"num_1 is at {id(num_1)}, num_2 is at {id(num_2)}")
enter_value(a, b)
print(f"a contains{id(a)}, b contains{id(b)}\nx contains{id(x)}, y contains{id(y)}")
