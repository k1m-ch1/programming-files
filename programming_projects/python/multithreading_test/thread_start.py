from threading import Thread
import time

def my_func():
	time.sleep(1)
	print("hello from thread!")
	return 'something to return'

t = Thread(target=my_func)

t.start()


print("Hello, world from main thread")


