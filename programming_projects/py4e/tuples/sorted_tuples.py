my_dict = {'Pizza':90, 'Burger':100, 'Seven':79, 'Eight':56, 'Taco':75}
my_list = [('c', 12), ('c', 17), ('j', 10), ('y', 69), ('t', 76)]

my_tuple_list = []

for key, value in my_dict.items():
  my_tuple_list.append((key, value))
  
print(my_tuple_list)