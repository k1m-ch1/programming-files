
import genshinstats as gs
from sys import exit

try:
  gs.set_cookie(ltuid=159767329, ltoken="xnel1urP6XicBnhioSAMDbE6p4pbWY9WYmsS8Cgj")
except:
  exit("Couldn't set cookie, incorrect luid or ltoken")


my_uid = 838667071

try:
  data = gs.get_user_stats(my_uid)
except:
  exit("uid not found")
total_characters = len(data['characters'])

print('user "kc" has a total of', total_characters, 'characters')

for character in data['characters']:
  print(character)