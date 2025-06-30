import asyncio
import aiohttp

API_KEY = {'X-Api-Key': 'Gqxf9r3Ltjp322aE4LB4dA==XDIMZUwL5w6ortjb'}


async def get_facts(n_times):
	tasks = []
	async with aiohttp.ClientSession() as s:
		for _ in range(n_times):
				tasks.append(s.get('https://api.api-ninjas.com/v1/facts/', headers=API_KEY))
		res = await asyncio.gather(*tasks)
		for r in res:
			tmp = await r.json()
			print(tmp[-1]['fact'])
	return res


asyncio.run(get_facts(50))