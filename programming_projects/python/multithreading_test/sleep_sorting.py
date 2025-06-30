from threading import Thread
import time
from numpy.random import randint

def wait_then_append(t, my_list):
	time.sleep(t/2)
	my_list.append(t)

random_list = list(randint(0, 10, 1000))
threads = []
sorted_list = []

for n in random_list:
	threads.append(Thread(target=wait_then_append, args=[n, sorted_list]))

for thread in threads:	
	thread.start()

for thread in threads:
	thread.join()

print(sorted_list)	