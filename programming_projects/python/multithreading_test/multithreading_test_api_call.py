from threading import Thread
from requests import get

API_KEY = {'X-Api-Key': 'Gqxf9r3Ltjp322aE4LB4dA==XDIMZUwL5w6ortjb'}
FACT_NUM = 100
list_of_facts = []

def fetch_fact(collection_list):		
	res = get('https://api.api-ninjas.com/v1/facts/', headers=API_KEY)
	collection_list.append(res.json()[0]['fact'])

threads = []
 	
for _ in range(FACT_NUM):
	thread = Thread(target=fetch_fact, args=[list_of_facts])
	thread.start()
	threads.append(thread)

for t in threads:
	t.join()

print(list_of_facts)


