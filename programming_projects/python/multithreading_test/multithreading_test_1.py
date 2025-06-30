from threading import Thread

def count_and_print(n):
	for i in range(1, n+1):
		pass
	return n

num = 1_000_000_000

t1 = Thread(target=count_and_print, args = [round(num/2)])
t2 = Thread(target=count_and_print, args = [round(num/2)])

t1.start()
t2.start()


t1.join() 
t2.join()