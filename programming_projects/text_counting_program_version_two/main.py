import re
import os

def evaluate_file(PATH, PARTITION_AT):
  """Returns a dictionary containing a list of text that has been filtered. 
  The first argument contains a text file to read and the last argument 
  contains a regular expression to seperate the dictionary.
  """
  with open(PATH, 'r') as file:
    filtered_characters = ['(', ')', '|', ',', '"', '\'', '*', '#', "\t", " ", ";", '?', '.', '!', ':', '/', '>', '< ', '-', '_', '+', '=', '`', '~', '@', '%', '$', '&']
    prev_key = "NOTHING"
    temp_list = list()
    return_dict = dict()
    for line in file:
      if re.search(PARTITION_AT, line) != None:
        if prev_key == "NOTHING":
          prev_key = re.search(PARTITION_AT, line).group().rstrip()
        else:
          return_dict[prev_key] = temp_list
          prev_key = re.search(PARTITION_AT, line).group().rstrip()
          temp_list = []
      else:
        line = line.lower().split()
        for i in range(len(line)):
          while len(line[i]) > 0 and line[i][0] in filtered_characters:
            line[i] = line[i][1:]
          while len(line[i]) > 0 and line[i][-1] in filtered_characters:
            line[i] = line[i][:-1]
        offset = 0
        for i in range(len(line)):
          i = i - offset
          if len(line[i]) <= 0:
            try: 
              line = line[:i] + line[i+1:]
            except:
              line = line[:i]
            finally:
              offset += 1
        temp_list.extend(line)
    return_dict[prev_key] = temp_list
    return return_dict

def frequency_detector(input_list):
  ret_dict = dict()
  for i in input_list:
    ret_dict[i] = ret_dict.get(i, 0) + 1
  return ret_dict

def write_to_file(key_at_top, file_handle, dict_to_evaluate, sortbyfrequency=True, ascending=True):
  """Args one needs a file handle and it needs to be in append mode.
  Args two needs a dictionary to sort by.
  Args three specify whether you want to sort by frequency or alphabetical order. Sort by frequency is default.
  """
  file_handle.write("\n" + key_at_top + "\n\n")
  list_of_stuff = list()
  if sortbyfrequency:
    thing = 0
  else:
    thing = 1
  for key, value in dict_to_evaluate.items():
    list_of_stuff.append((value, key))
  list_of_stuff = sorted(list_of_stuff, key=lambda x: x[thing], reverse=not ascending)
  for value, key in list_of_stuff:
    spaces = " "
    len_of_spaces = 20 - len(key)
    spaces = spaces * len_of_spaces
    file_handle.write(str(key) + spaces + ": " + str(value) + "\n")
    
if __name__ == '__main__':
  path = r'C:\Users\Kimchour\Documents\programming_projects\text_counting_program_version_two\dummy_text.txt'
  dictionary_of_chapters = evaluate_file(path, r'Chapter\s[0-9]+')
  output_path = r'C:\Users\Kimchour\Documents\programming_projects\text_counting_program_version_two\output_text_file.txt'
  if os.path.exists(output_path):
    file_handle = open(output_path, 'a')
  else:
    file_handle = open(output_path, 'w')
    file_handle.close()
    file_handle = open(output_path, 'a')
  for key in dictionary_of_chapters.keys():
    ret_dict = frequency_detector(dictionary_of_chapters[key])
    write_to_file(key, file_handle, ret_dict, ascending=True)
  
  