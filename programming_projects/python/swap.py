x = 1
y = 2
def swap( a, b):
    print ("a contain the value {} and b contains the value {}".format(a,b))
    temp = a
    a = b
    b = temp
    print ("a contain the value {} and b contains the value {}".format(a,b))
swap( x, y)
print("x contains the value {} and y contains the value{}".format(x, y))