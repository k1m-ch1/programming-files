from turtle import Turtle

t = Turtle()

t.forward(100)

t.left(90)

t.forward(100)

t.left(90)

t.forward(100)

my_pos = t.pos()

print(my_pos, "Type of pos: ",type(my_pos))

t.home()

t.backward(100)

t.right(90)

t.backward(100)

t.right(90)

t.backward(100)

t.forward(100)

t.left(90)

t.forward(100)

t.left(90)

t.forward(100)



t.screen.mainloop()