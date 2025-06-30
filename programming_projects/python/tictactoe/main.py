import re, random # Import regular expression library and random library

def quit_game():
  print("Quit by using command \"-quit\"\n"+"Thanks for playing!")
  quit()

def replace_placeholder(display_grid):
  """ finds the placeholder in "placeholder_grid" and replace it with a space aka a \" \""""
  #Search for example "A1" in the input string and replace it with a space aka a " "
  while re.search(r'[A-Z][0-9]',display_grid) != None:
    found_span = re.search(r'[A-Z][0-9]',display_grid).span()
    display_grid = display_grid[:found_span[0]] + " " + display_grid[found_span[1]:]
  return display_grid

def player_plays(player_info):
  """Returns a string containing the modified grid. Takes in grid to be manipulated 
  and "player_info" which is a tuple containing player name and a set of moves which the player has selected."""
  global placeholder_grid
  global cell_left, my_commands
  # Set "player_input" to an invalid value
  player_input = "unknown"
  print(f"{player_info[0]}'s turn")
  # Loops until you get a valid input
  while not player_input in cell_left:  
    player_input = input(f"{player_info[0]} plays: ").upper()
    if player_input.lower() in my_commands:
      my_commands[player_input.lower()]()
  cell_left.remove(player_input) # Remove in the "cell_left" set
  my_span = re.search(r'{}'.format(player_input), placeholder_grid).span()  #Get the range of the cell that the player have input
  placeholder_grid = placeholder_grid[:my_span[0]] + "{}".format(player_info[0]) + placeholder_grid[my_span[1]:]  # Replace the cell selected with either X or O
  player_info[1].add(player_input)
  return placeholder_grid

def check_for_win(player_info):
  """Returns whether x or o or none won. Require player_info as argument which is a tuple containing the player's name and the player's played moves"""
  global left_to_right_diagonal #get the global version of case of left_to_right_diagonal win and right_to_left_diagonal win
  global right_to_left_diagonal
  played_moves = list(player_info[1]) #stored your played moves into another variable for less confusion
  vertical_sublist, horizontal_sub_list, num_of_sub_list = list(), list(), len(played_moves) - 2  #Define the sorted array that is meant to be passed into vertical check, horizontal check and define the number of sublist that can be created
  #Check for whether there will be any sublist that can be created
  if num_of_sub_list > 0:
    #Sort the list based on alphabet in the front and based on numbers in back for vertical check and horizontal check respectively
    vertical_sublist, horizontal_sub_list = sorted(played_moves, key=lambda x: x[0]), sorted(played_moves, key=lambda x: x[1])
    for i in range(num_of_sub_list):
      my_vertical_sublist = vertical_sublist[i:i+3]
      my_horizontal_sublist = horizontal_sub_list[i:i+3]
      #Checks for whether there's a sublist that have equal index zero or equal index one || equal alphabet or equal number
      if my_horizontal_sublist[0][0] == my_horizontal_sublist[1][0] == my_horizontal_sublist[2][0] or my_vertical_sublist[0][1] == my_vertical_sublist[1][1] == my_vertical_sublist[2][1]:
        return player_info[0]
    #checks for diagonal wins 
    if len([x for x in played_moves if x in left_to_right_diagonal]) >= 3 or len([x for x in played_moves if x in right_to_left_diagonal]) >= 3: return player_info[0]
  else:
    return None
  
#open file for text data and transfer that file into a string
file_data = open(r'C:\Users\Kimchour\Documents\programming_projects\python\tictactoe\commands.txt', 'r').read()
scoreboard = lambda val: print("SCOREBOARD SCOREBOARD!\nAw, what happened to your friend?\nHey I know that guy. I killed him and he cried like a b*tch. {} undefeated".format(val))
# Define a set for every cell called "all_row_and_col", a set for each diagonal wins called "left_right_diagonal" and vice versa, and the value for x and o
all_row_and_col, left_to_right_diagonal, right_to_left_diagonal, x_set, o_set, x_wins, o_wins = {"A1","A2","A3","B1","B2","B3","C1","C2","C3"}, {"A1","B2","C3"}, {"C1","B2","A3"}, set(), set(), 0, 0
# Define number of cells left to be played called "cell_left" and input for x called "x_input" and y called "y_input"
cell_left, x_input, y_input, x_info, o_info = all_row_and_col, 'unknown', 'unknown', ("X", x_set), ("O", o_set) #x_info or o_info contains information for name in the 0th index and the cells selected in the 1st index
#Use a dictionary to store the name of command and the function associated with it
my_commands = {'-help': lambda : print(re.search(r'\<help\>([a-zA-Z0-9\s\W]+)\</help\>',file_data).group(1)+"\ncurrent state: \n"+replace_placeholder(placeholder_grid)), 
               '-strategy': lambda : print(re.search(r"\<strategy\>[a-zA-Z0-9\s\W]+\</strategy\>", file_data).group()+"\ncurrent state: \n"+replace_placeholder(placeholder_grid)), 
               '-ls': lambda : print(re.search(r"\<ls\>[a-zA-Z0-9\s\W]+\</ls\>", file_data).group()+"\ncurrent state: \n"+replace_placeholder(placeholder_grid)), 
               '-quit': quit_game}
placeholder_grid = """
 A1 | B1 | C1
---+---+---
 A2 | B2 | C2
---+---+---
 A3 | B3 | C3

--------------------------------------------------"""  #Default playing grid with nothing
default_grid = placeholder_grid
 
#Randomize x and o's turn and input it into a list
x_and_o_randomize =[x_info, o_info]
random.shuffle(x_and_o_randomize)
counter,winner = 0, None
print("\n\nInput the cell you want to place\nEx. A1" + "\nType the command \"-ls\" for the list of commands\n\n")
# Main game loop
while True:
  #Game loop
  while len(cell_left) != 0:
    #Alternating turns logic
    counter += 1
    index = counter%2
    placeholder_grid = player_plays(x_and_o_randomize[index])
    winner = check_for_win(x_and_o_randomize[index])
    if winner != None: break
    print(replace_placeholder(placeholder_grid))
  print(replace_placeholder(placeholder_grid), f"\n{winner} won!")
  placeholder_grid = default_grid
  if winner == 'X': 
    counter = 2
    x_wins += 1
    scoreboard(winner)
  elif winner == 'O': 
    counter = 1
    o_wins += 1
    scoreboard(winner)
  print("Score X: {}, O: {}".format(x_wins, o_wins))
  print("------------------------------------------------------------\n\n")
  #Logic for checking for whether you want to continue or not
  continue_or_not = "unknown"
  while continue_or_not != 'yes' and continue_or_not != 'no':  continue_or_not = input("Start a new game? (type \"yes\" if yes and \"no\" if no)\n>").lower()
  if continue_or_not == 'no':
    print("Thanks for playing!")
    quit()
  else:
    print("\nNEW GAME\n",default_grid)
  #Reset everything
  all_row_and_col, x_set, o_set = {"A1","A2","A3","B1","B2","B3","C1","C2","C3"}, set(), set()
  cell_left, x_input, y_input, x_info, o_info = all_row_and_col, 'unknown', 'unknown', ("X", x_set), ("O", o_set)
  x_and_o_randomize = [x_info, o_info]

