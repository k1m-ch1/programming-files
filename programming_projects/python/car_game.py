quit_game = False
start = 0
stop = 0
while(quit_game == False):
  inputted_word = input(">")
  if inputted_word == "help":
    print("start - to start the car\nstop - to stop the car\nquit - to quit the game")
  elif inputted_word == "start":
    stop = 0
    start = start + 1
    if start == 1:
      print("You started the car...")
    elif start > 1:
      print("you already started the car")
  elif inputted_word == "stop":
    start = 0
    stop = 1 + stop
    if stop == 1:
     print("You stopped the car...")
    elif stop > 1:
      print("you already stop the car")
  elif inputted_word == "quit":
    print("You've quitted the game")
    quit_game = True
  else:
    print("Sorry! I couldn't understand what you're saying")
    
