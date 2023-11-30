from multiprocessing import Process
import time
from multiprocessing import cpu_count


def counting(num_of_cores, process_num):
    #1 000 000 000
    print(f"This is process number {process_num}")
    one_bil = 1000000000
    a = 0
    while a < (one_bil/num_of_cores):
        a = a + 1
    
def main():
    prev_time = time.perf_counter()
    num_of_cores = cpu_count()
    a = list()
    for i in range(num_of_cores):
        a.append(Process(target=counting, args=(num_of_cores, i+1, )))
    for i in range(num_of_cores):
        a[i].start()
    for i in range(num_of_cores):
        a[i].join()

    print("This program ran for {} s".format(time.perf_counter()-prev_time))

if __name__ == '__main__':
    main()