import asyncio
import genshin
from webscraping import test_two


async def main():
    cookies = {"ltuid": 159767329	, "ltoken": "xnel1urP6XicBnhioSAMDbE6p4pbWY9WYmsS8Cgj"}
    client = genshin.Client(cookies)
 
    data = await client.get_genshin_user(tectone_uid)
    for character in data.characters:
      print(character.name)
asyncio.run(main())