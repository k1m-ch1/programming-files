from concurrent.futures import ThreadPoolExecutor
import math



list_of_numbers = [x**2 for x in range(100000)]

with ThreadPoolExecutor() as e:
	tmp = e.map(math.sqrt, list_of_numbers)
	print(list(tmp))