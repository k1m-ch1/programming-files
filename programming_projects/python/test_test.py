# cook your dish here
def evaluation(x, y):
    if(x%2==0 and y%2 == 0):
        return "Janmansh"
    elif(x%2==0 and y%2>0):
        return "Jay"
    elif(x%2>0 and y%2 == 0):
        return "Jay"
    else:
        return "Janmansh"

T = int(input())
for i in range(T):
    a = int(input())
    b = int(input())
    print(evaluation(a,b))