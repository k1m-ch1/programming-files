from threading import Thread
from time import sleep

def my_func(my_list):
	sleep(1)
	print("hello, from thread")
	my_list.append("returned cool stuff")

returned_stuff = []

t = Thread(target=my_func, args=[returned_stuff])

t.start()

t.join()
print("hello, from main")
print(returned_stuff)