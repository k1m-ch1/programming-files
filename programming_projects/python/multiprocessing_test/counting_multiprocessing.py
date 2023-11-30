from multiprocessing import Process, cpu_count

def count(n):
	for i in range(n):
		pass

def count_multiprocessing(n):
	individual = n // cpu_count()
	processes = []
	for i in range(cpu_count()):
		processes.append(p:=Process(target=count, args=[individual]))
	processes.append(Process(target=count, args=[(t:=individual+ (n%cpu_count()))]))

	for p in processes:
		 p.start()

	for p in processes:
		p.join()

	print(f"Dividided to {cpu_count()}, processes. {individual}, {t}")

if __name__ == '__main__':
	count_multiprocessing(1_000_000_000)