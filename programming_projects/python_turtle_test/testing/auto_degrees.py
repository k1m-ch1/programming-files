import math

def auto_degrees(x_axis, y_axis):
	if x_axis == 0 and y_axis > 0:
		# going straight up
		return 90
	elif x_axis == 0 and y_axis < 0:
		# going straight down
		return 270
	elif y_axis == 0 and x_axis > 0:
		# going straight right
		return 0
	elif y_axis == 0 and x_axis < 0:
		# going straight left
		return 180
	elif x_axis == 0 and y_axis == 0:
		# not moving at all

		return 0
	else:
		# otherwise
		additional_terms = {
			(True, True) : 0,
			(False, True) : 90,
			(False, False) : 180,
			(True, False) : 270
		}
		abs_degree = (math.atan(abs(y_axis)/abs(x_axis))/math.pi) * 180
		return abs_degree + additional_terms[x_axis > 0, y_axis > 0]

for x in linspace(-1, 1, 20):
	for y in linspace(-1, 1, 20):
		x = round(x, 1)
		y = round(y, 1)
		print(f"x: {x}, y: {y}, deg: {auto_degrees(x, y)}")


