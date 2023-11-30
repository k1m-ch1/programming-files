import time

str_of_alphabet = "A B C D E F G H I J K L M N O P Q R S T U V W X Y Z a b c d e f g h i j k l m n o p q r s t u v w x y z" 
list_of_alphabet = str_of_alphabet.split()

start_time = time.time()
def ret_text(PATH):
  try:
      file_handle = open(PATH, 'r')
      return str(file_handle.read())
  except:
    print("Something happened after trying to open file")
    quit()

def split_text_lower(my_string):
  new_list = my_string.split()
  for i in range(len(new_list)):
    new_list[i] = new_list[i].lower()
  return new_list

def count_list(my_list):
  return_dict = dict()
  for i in my_list:
    return_dict[i] = return_dict.get(i, 0) + 1
  return return_dict

def format_beginning_and_end(new_list):
  for i in range(len(new_list)):
    while (new_list[i][-1:] not in list_of_alphabet):
      new_list[i] = new_list[i][:-1]
    while (new_list[i][0] not in list_of_alphabet):
      new_list[i] = new_list[i][1:]
  return new_list

def save_file(FROM_PATH, PATH, str_to_save):
  str_to_save = "Read from {} \n".format(FROM_PATH) + str_to_save
  file_handle = open(PATH, 'w')
  file_handle.write(str_to_save)
  
    

if __name__ == '__main__':
  PATH_TO_READ = str("C:\Users\Kimchour\Documents\programming_projects\py4e\\another_program\\dummy_text.txt")
  PATH_TO_WRITE = str("C:\\User\\Kimchour\\Documents\\programming_projects\\py4e\\counting_text_program\\text_frequency.txt")
  PATH_TO_WRITE = "text_frequency.txt"
  new_text = ret_text(PATH_TO_READ)
  new_list = split_text_lower(new_text)
  formatted_list = format_beginning_and_end(new_list)
  new_dict = count_list(new_list)
  sorted_list_keys = list()
  for i in new_dict:
    sorted_list_keys.append(i)
  sorted_list_keys.sort(key= lambda x: x[0], reverse=False)
  value2save = str()
  for i in sorted_list_keys:
    value2print = i
    for j in range(20 - len(i)):
      value2print += " "
    value2print += ": {}\n".format(new_dict[i])
    value2save += value2print
  save_file(PATH_TO_READ, PATH_TO_WRITE, value2save)
  

print("Program ended in {} seconds".format(time.time() - start_time))