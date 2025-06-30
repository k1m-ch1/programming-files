import asyncio

async def pausing_multiple(waiting_list):
	tasks = []
	for wait_time in waiting_list:
		tasks.append(asyncio.sleep(wait_time))
	res = await asyncio.gather(*tasks)
	print(res)
	return res

asyncio.run(pausing_multiple([5, 4, 3, 2, 6]))