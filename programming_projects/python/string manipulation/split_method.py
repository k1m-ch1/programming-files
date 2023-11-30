with open('C:\\Users\\Kimchour\\Documents\\programming_projects\\python\\string manipulation\\feels_like_summer.txt', 'r') as file:
  feels_like_summer = file.read()
  new_string = feels_like_summer.split()
  print(type(new_string))
  print(len(new_string))
  print("-------------------------------------------------------")
  for i in new_string:
    print(i)
  