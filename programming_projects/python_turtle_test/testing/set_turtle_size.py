from turtle import Turtle

import time

t = Turtle()

t.width(10)


print('My shape size', t.shapesize())

t.forward(100)

time.sleep(1)

print('Increased my width')

t.shapesize(5, 1, 1)

t.forward(100)

time.sleep(1)

print('Increased my len')

t.shapesize(1, 5, 1)

t.forward(100)

time.sleep(1)


print('Increased my linewidth')

t.shapesize(1, 1, 10)

t.forward(100)

time.sleep(1)



t.screen.mainloop()