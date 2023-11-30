from turtle import Turtle
import math


t = Turtle()

# one unit is equals to 100 pixels
UNIT = 20

def auto_set_direction_and_movement(turtle_obj, x_units, y_units):
	plus_k_180 = 0
	if (x_units < 0 and y_units >= 0) or (x_units <= 0 and y_units <= 0):
		plus_k_180 = 180
	x_units, y_units = x_units*UNIT, y_units*UNIT
	if x_units != 0:
		turtle_obj.setheading((math.atan((y_units/x_units))/math.pi) *  180 + plus_k_180)
	else:
		turtle_obj.setheading(90 + plus_k_180)

	turtle_obj.forward(math.hypot(x_units, y_units))




t.width(2)

# outline of the flower

instruction_set = [
	(-2, 0), # C
	(-0.5, -0.5),
	(0, -1),
	(0.5, -0.5),
	(0.5, 0),

	(0.5, 1),
	(1, 1), 

	(1, -1),
	(1, -2),

	(1, -1), # this start of right eye
	(-1, -1),
	(-1, 1),
	(1, 1), # end of right eye

	(2, -1),
	(1, -1),
	(-1, -1),
	(-2, -1),
	(-1, -2),
	(-1, -1),
	(-1, 1),
	(-1, 2),
	(-2, 1),
	(-1, 1),
	(1, 1),
	(2, 1),

	(1, -1), # this start of right eye
	(-1, -1),
	(-1, 1),
	(1, 1), # end of right eye

	(1, 2),
	(1, 1),

	(1, -1),
	(0, 1),
	(1, -1),
	(1, 1),
	(0, -2),
	(-1.5, 0)

]

for instruction in instruction_set:
	auto_set_direction_and_movement(t, *instruction)


# t.setpos((-1*UNIT, 10*UNIT))

# # t.forward(100)


# cam_instruction_set = [
# 	(-1, 0),
# 	(-0.5, -0.5),
# 	(0, -1),
# 	(0.5, -0.5),
# 	(1, 0), # C

# 	(1, 2),
# 	(1, -2), # A
	
# 	(0, 2),
# 	(1, -1),
# 	(1, 1),
# 	(0, -2)# M
# ]

# for instruction in cam_instruction_set:
# 	auto_set_direction_and_movement(t, *instruction) 

t.setpos((-4.5*UNIT, -5.5*UNIT))


angkor_wat_instruction_set = [
	(0.5, 0.5),
	(1, -0.5),
	(0, 1.5),
	(1, 1),
	(1, -1),
	(0, 2),
	(1, 1),
	(1, -1),
	(0, -2),
	(1, 1),
	(1, -1),
	(0, -1.5),
	(1, 0.5),
	(0.5, -0.5)
]

for instruction in angkor_wat_instruction_set:
	auto_set_direction_and_movement(t, *instruction)


t.setpos((1*UNIT, -5*UNIT))

t.width(5)


dt_logo_instruction_set = [
	(-2, 0),
	(0, -1),
	(0.5, -0.5),
	(-0.5, -0.5),
	(0, -1),
	(2, 0)
]

for instruction in dt_logo_instruction_set:
	auto_set_direction_and_movement(t, *instruction)

# t.setpos(())

d_instruction = [

]

t.screen.mainloop()

