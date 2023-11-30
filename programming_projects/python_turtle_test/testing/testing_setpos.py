from turtle import Turtle

t = Turtle()


t.forward(100)

f_pos = t.pos()

t.right(90)

t.forward(100)

t.setpos(f_pos)

t.right(90)

t.backward(100)

t.setx(50)

t.left(120)

t.forward(100)

t.setheading(180)

t.forward(100)

t.screen.mainloop()