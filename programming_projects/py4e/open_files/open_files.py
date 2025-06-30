
PATH = 'C:\\Users\\Kimchour\\Documents\\programming_projects\\py4e\\open_files\\files_to_open\\file_to_read.txt'
try:
  file_handle = open(PATH, 'r')
  counter = 0
  for i in file_handle:
    i = i.rstrip()
    print(i)

except FileNotFoundError:
  print("File to {} not found...".format(PATH))
  quit()
except:
  print("Something went wrong...")
  quit()