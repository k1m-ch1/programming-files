import asyncio
import genshin
from webscraping import test_two as t2

async def main():
    cookies = {"ltuid": 159767329	, "ltoken": "xnel1urP6XicBnhioSAMDbE6p4pbWY9WYmsS8Cgj"}
    
    client = genshin.Client(cookies)

    my_uid = 838667071
    tectone_uid = 600002954
    whale_uid = 600452363
    mega_whale_uid = 600452363
    moga_uid = 700233070
    data = await client.get_genshin_user(my_uid)
    print(f'user has {len(data.characters)} characters')
    for character in data.characters:
      character_list_from_web = t2.get_element_from_column('characters', 'Name', 'text')
      correlates = character.name in character_list_from_web
      print(f"{character.name} exists in the table in the web: {correlates} at index {character_list_from_web.index(character.name)}")
        
asyncio.run(main())