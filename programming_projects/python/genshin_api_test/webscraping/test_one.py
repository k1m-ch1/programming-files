import requests
from bs4 import *

CHARACTERS_URL = 'https://genshin-impact.fandom.com/wiki/Character/List'
WEAPONS_URL = 'https://genshin-impact.fandom.com/wiki/Weapon' 
REGION_URL = 'https://genshin-impact.fandom.com/wiki/Teyvat'

ALL_URLS = {"characters":(CHARACTERS_URL, ['article-table', 'sortable', 'alternating-colors-table', 'jquery-tablesorter']), 
            "weapons": (WEAPONS_URL, ['article-table', 'sortable', 'jquery-tablesorter']), 
            "regions": (REGION_URL, ['wikitable'])
}

for k, v in ALL_URLS.items():
  table = BeautifulSoup(requests.get(v[0], timeout=(3.05, 27)).text, 'lxml').find('table', class_=v[1])
  with open(f'./files/{k}_table.html', 'w') as file:
    file.write(table.prettify())