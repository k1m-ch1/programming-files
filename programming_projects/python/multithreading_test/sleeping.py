import time
from threading import Thread

def wait_seconds_parallel(t, n):
	per_thread = t/n
	print(f"Sleeping for {t} seconds by splitting into {n} threads. {per_thread} seconds per thread.")
	threads = []
	for _ in range(n):
		threads.append(Thread(target=time.sleep, args=[per_thread]))

	for t in threads:
		t.start()

	for t in threads:
		t.join()


wait_seconds_parallel(120, 60)