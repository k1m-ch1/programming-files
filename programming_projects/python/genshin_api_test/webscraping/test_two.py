import requests
from bs4 import *
import json

CHARACTERS_URL = 'https://genshin-impact.fandom.com/wiki/Character/List'
WEAPONS_URL = 'https://genshin-impact.fandom.com/wiki/Weapon' 
REGION_URL = 'https://genshin-impact.fandom.com/wiki/Teyvat'

ALL_URLS = {"characters":(CHARACTERS_URL, ['article-table', 'sortable', 'alternating-colors-table', 'jquery-tablesorter']), 
            "weapons": (WEAPONS_URL, ['article-table', 'sortable', 'jquery-tablesorter']), 
            "regions": (REGION_URL, ['wikitable'])
}

def scrape_table_data(formatted_dict):
  """
  formatted_dict has this format: 
  {"table1":('https://www.sitetoscrape.com', ['some', 'of', 'the', 'table', 'class', 'names']),
   ...}
  returns a dict of the table rows of the following format
  {
    "table1":
    [{"column_1":html_tag, "column_2":html_tag, ...},...],
    ...
  }
  
  """
  ret_dict = dict()
  for k, v in ALL_URLS.items():
    
    # requests for the table
    table = BeautifulSoup(requests.get(v[0], timeout=(3.05, 27)).text, 'lxml').find('table', class_=v[1])
    
    # template_headers is a list that contains the name of the column
    # template_table_row is a dictionary that has the template for each row where the keys represent the name of the column (given in the header row)
    # table_rows is a list that contains the a row of a table represented by a template_table_row dictionary format
    template_headers, table_rows, template_table_row = list(), list(), dict()
    for tr in table.find_all('tr'):
      # looping all of the tr
      temp_template_table_row = template_table_row.copy() # resets the temp_template_table_row
      if tr.th is not None:
        # searching for the header row (first row)
        for th in tr.find_all('th'):
          # set template_headers and template_table_row
          template_headers.append(th)
          template_table_row[th.text.strip()] = None
      else:
        for i, td in enumerate(tr.find_all('td')):
          # filling in the information into a temp_template_table_row
          temp_template_table_row[template_headers[i].text.strip()] = td
        table_rows.append(temp_template_table_row)
    ret_dict[k] = table_rows
  return ret_dict

SCRAPPED_TABLES_DATA = scrape_table_data(ALL_URLS)

def is_lazyload(html_element):
  return 'lazyload' in html_element.get('class', [])

def get_img_src(html_element):
  if is_lazyload(html_element):
    return html_element['data-src']
  return html_element['src']

def write_data_as_str_to_txt_file(table, path='results.txt'):
  with open(path, 'w') as file:
    str_to_write = str()
    
    for tr in table:
      for k, v in tr.items():
        if v.img is not None:
          str_to_write += f"{k}: {v.text.strip()}, Url: {get_img_src(v.img)}\n"
        else:
          str_to_write += f"{k}: {v.text.strip()}\n"
      str_to_write += '\n\t\t----------------------------------------\t\t\n' 

    file.write(f'{str_to_write}')

def format_table(table):
  """
    extracts the name and the url and parse it into a list
  """
  ret_list = list()
  for tr in table:
    temp_dict = dict()
    for k, v in tr.items():
      temp_dict[k] = {"text": v.text.strip()}
      if v.img is not None:
        temp_dict[k]["img_src"] = get_img_src(v.img)
    ret_list.append(temp_dict)
  return ret_list

def get_formatted_table(table_name):
  return format_table(SCRAPPED_TABLES_DATA[table_name])

def get_element_from_column(table_name, column_name, info_key):
  ret_list = list()
  formatted_table = get_formatted_table(table_name)
  for hr in formatted_table:
    ret_list.append(hr[column_name][info_key])
  return ret_list
  
if __name__ == '__main__':
  target_table = 'characters'
  results = scrape_table_data(ALL_URLS)
  write_data_as_str_to_txt_file(table=results[target_table], path=f'./test_two_{target_table}_results.txt')
  with open(f'./test_two_{target_table}_json.json', 'w') as file:
    file.write(json.dumps(format_table(results[target_table]), indent=2))