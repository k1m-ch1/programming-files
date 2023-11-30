import time
import threading
def counting(seconds):
  count = 0
  while(count < seconds):
    time.sleep(1)
    print(f"{count} seconds has passed")
    count += 1


new_thread = threading.Thread(target=counting, args=(10,))
new_new_thread = threading.Thread(target=counting, args=(20,))
new_thread.start()
new_new_thread.start()
new_thread.join()
new_new_thread.join()