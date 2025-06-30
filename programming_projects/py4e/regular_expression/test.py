import re

my_list = ["Olivia", "Noah", "James", "Pizza hut",
           "Burger King", "Mason", "Ethane", "Lun@"
           ,"XAeA12"]

for i in my_list:
  match_result = re.search("^O", i)
  print(match_result)