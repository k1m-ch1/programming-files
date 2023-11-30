from turtle import Turtle

import math

def auto_degrees(x_axis, y_axis):
	ret_degree = int()
	if x_axis == 0 and y_axis > 0:
		ret_degree = 90
	elif x_axis == 0 and y_axis < 0:
		ret_degree = 270
	else:
		abs_degree = (math.atan(abs(y_axis)/abs(x_axis))/math.pi) * 180

		dict_of_func = {
			(True, True) : lambda theta: theta,
			(False, True) : lambda theta: 180 - theta,
			(False, False) : lambda theta: 180 + theta,
			(True, False) : lambda theta: 360 -theta
		}

		ret_degree = dict_of_func[x_axis >= 0, y_axis >= 0](abs_degree)

	return ret_degree

def auto_magnitude_and_deg(x_axis, y_axis, current_deg):
	deg_on_cartesian_plane = auto_degrees(x_axis, y_axis)
	turning_deg_ccw = deg_on_cartesian_plane - current_deg
	magnitude = math.hypot(x_axis, y_axis)
	return (turning_deg_ccw, magnitude)

ACCUM_DEG = 0
UNIT = 20

def turn_ccw_and_turn(turtle_obj, x_axis, y_axis):
	global UNIT
	global ACCUM_DEG
	turning_deg_ccw, magnitude = auto_magnitude_and_deg(x_axis, y_axis, ACCUM_DEG)
	ACCUM_DEG += turning_deg_ccw
	ACCUM_DEG = ACCUM_DEG % 360
	if turning_deg_ccw < 0:
		turning_deg_ccw = 360 + turning_deg_ccw
		# print(ACCUM_DEG, turning_deg_ccw, sep=", ")


	if turning_deg_ccw > 180:
		turtle_obj.right(360 - turning_deg_ccw)
		# print(ACCUM_DEG, 360 - turning_deg_ccw, sep=", ")
		
	else:
		turtle_obj.left(turning_deg_ccw)
	turtle_obj.forward(magnitude*UNIT)


t = Turtle()

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
	turn_ccw_and_turn(t, *instruction)


t.penup()
t.setpos((-4.5*UNIT, -5.5*UNIT))
t.pendown()


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
	turn_ccw_and_turn(t, *instruction)

t.penup()
t.setpos((1*UNIT, -5*UNIT))
t.pendown()

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
	turn_ccw_and_turn(t, *instruction)

t.screen.mainloop()
