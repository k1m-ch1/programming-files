from concurrent.futures import ThreadPoolExecutor
import math


list_to_sqrt = [x**2 for x in range(100)]


with ThreadPoolExecutor() as t:
	list_of_futures = [t.submit(math.sqrt, n) for n in list_to_sqrt]
	print([x.result() for x in list_of_futures])