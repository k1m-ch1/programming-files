from turtle import Turtle


t_1 = Turtle()
t_2 = Turtle()
t_1.speed(1)
t_2.speed(1)


t_1.left(45)
for i in range(100):
	t_1.forward(1)
	t_2.forward(1)