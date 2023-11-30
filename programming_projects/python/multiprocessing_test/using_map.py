from concurrent.futures import ProcessPoolExecutor
import math

list_of_numbers = [x**2 for x in range(4)]

with ProcessPoolExecutor() as e:
	tmp = [e.submit(math.sqrt, x) for x in list_of_numbers]
	print([x.result() for x in tmp])