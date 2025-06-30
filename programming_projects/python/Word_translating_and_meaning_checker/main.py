from PyDictionary import PyDictionary
import googletrans as translator

def check_meaning(word):
  """Checks the meaning of a word.

  Args:
      word (String): word to check for meaning
  Returns:
      (Dictionary): the definition of a word
  """
  result = PyDictionary(word).getMeanings()
  return result

def format_definition(definition):
  """
  Will group the definition data a list of into (Name, Data)
  Args:
      definition (Dict): A dictionary with format from PyDictionary.getmeanings() method
  """
  if list(definition.values())[0] == None:
    return
  else:
    ret_list = [tuple(definition.keys())[0]+'\n']
    for part_of_speech in tuple(definition.values())[0].items():
      parsed_string = f"{part_of_speech[0]}:\n"
      for i in part_of_speech[1]:
        parsed_string += f"- {i}\n"
      ret_list.append(parsed_string)
    return ret_list

def fr2en_translate(word):
  """Translate a french word to english. Will return a french word or the same word if it's not in french.

  Args:
      word (String): A word you want to translate.

  Returns:
      String: A translated version of the word.
  """
  temp_translate = translator.Translator()
  translated_object = temp_translate.translate(word, dest='en', src='fr')
  return translated_object.text

def get_meaning_or_translate(word):
  """Tries to work out whether we should get the definition for the word or translate it.
    String -> String
  """
  if (temp:=format_definition(check_meaning(word))) != None:
    ret_str = ""
    for i in temp:
      ret_str += i
    return ret_str + "\n"
  else:
    return f"{word} -> {fr2en_translate(word)}\n\n"

def seperate_chapter(raw_str):
  """raw_str uses ---*Number\n word \n ... format. Will return a dictionary with chapter num as key and words as value

  Args:
      raw_str (string): _description_
  Returns:
      (Dictionary)
  """
  ret_dict = dict()
  chapters = raw_str.split('---')
  for i in chapters:
    i = i.split('\n')
    ret_dict[f"Chapter {i[0].strip()}"] = i[1:]
  return ret_dict

def format_and_apply_chapter(chapter, all_words):
  """Translate or get meaning on each word and format it into a string.

  Args:
      chapter (_type_): The chapter name.
      all_words (_type_): All of the words in the chapter

  Returns:
      (string): _description_
  """
  ret_str = f"{chapter}\n\n"
  for i in all_words:
    ret_str += get_meaning_or_translate(i)
  return ret_str+"\n----------------------------------------\n"

PATH = r'C:\Users\Kimchour\Documents\programming_projects\python\Word_translating_and_meaning_checker\input.txt'
PATH_OUTPUT = r'C:\Users\Kimchour\Documents\programming_projects\python\Word_translating_and_meaning_checker\output.txt'
file_handle = open(PATH, 'r', encoding='utf-8')
file_handle_output = open(PATH_OUTPUT, 'a', encoding='utf-8')
input_string = file_handle.read()
result = seperate_chapter(input_string)
passed_str = ""
for key, value in result.items():
  passed_str += format_and_apply_chapter(key, value)
file_handle_output.write(passed_str)




