import csv

with open('./word.csv', 'r') as file:
	reader = csv.reader(file)
	words = (lambda *args: args)(*reader)
	for i in words[::-1]:
		print(i[0], end="")
		input()
		print(":", i[1])



