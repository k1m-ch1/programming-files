import requests
import json

s = requests.session()
API_KEY = {'X-Api-Key': 'Gqxf9r3Ltjp322aE4LB4dA==XDIMZUwL5w6ortjb'}


# generate x amount of requests

facts = []
for _ in range(50):
	response = s.get('https://api.api-ninjas.com/v1/facts/', headers=API_KEY)
	facts.append(response.json()[0]['fact'])
	print(facts[-1])
print(facts)