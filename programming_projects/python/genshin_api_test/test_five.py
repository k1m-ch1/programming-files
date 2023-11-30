import genshinstats as gs

def is_valid_uid_new(uid, luid=159767329, ltoken="xnel1urP6XicBnhioSAMDbE6p4pbWY9WYmsS8Cgj"):
  gs.set_cookie(ltuid=luid, ltoken=ltoken)
  data = gs.get_user_stats(uid)
  total_characters = len(data['characters'])
  print('user "sadru" has a total of', total_characters, 'characters')

def is_valid_uid_old(uid, luid=159767329, ltoken="xnel1urP6XicBnhioSAMDbE6p4pbWY9WYmsS8Cgj"):
  gs.set_cookie(ltuid=luid, ltoken=ltoken)
  data = gs.get_user_stats(uid)

is_valid_uid_new(838667071)
print(is_valid_uid_old(838667071))

