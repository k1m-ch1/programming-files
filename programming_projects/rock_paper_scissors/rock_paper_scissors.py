import random, re
my_value, my_func, my_dict ,help_dict = "notany", lambda state,you,opp: print(f"{state}, YOU played {you} and COMPUTER played {opp}"), {"rock":"SRP", "paper":"RPS", "scissors":"PSR"},{"info": lambda : print((re.search(r"\(info\)\{([a-zA-Z0-9\s\W]+)\}",open(r'C:\Users\Kimchour\Documents\programming_projects\rock_paper_scissors\instruction.txt','r').read())).group(1))} #value meaning {Can beat, Can draw, Can't beat}
while not my_value in my_dict.keys() :  
  my_value = input("Play rock, paper or scissors: ").lower()  
  if my_value in help_dict: help_dict[my_value]()
computer_value = random.choice(list(my_dict.keys()))
if my_value == computer_value:  my_func("You Drawed", my_value, computer_value) #compare computer's value to your value to check for a draw
elif my_dict[computer_value][1] == my_dict[my_value][0]:  my_func("You won", my_value, computer_value) # compare computer's value to your "Can beat" value
else: my_func("You lost", my_value, computer_value)