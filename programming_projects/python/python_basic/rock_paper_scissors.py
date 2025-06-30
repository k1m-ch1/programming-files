print("Play rock, paper, scissors!")
a = input("Player 1's move: ")
b = input("Player 2's move: ")
if (a == "rock" and b == "scissors") or (a == "scissors" and b == "paper") or (a == "paper" and b == "rock"):
  print("Player 1 wins!")
elif (a == b):
  print("Draw!")
elif (b == "rock" and a == "scissors") or (b == "scissors" and a == "paper") or (b == "paper" and a == "rock"):
  print("Player 2 wins!")
else: print("Inavlid move(s)! [Please input \"Rock\", \"Paper\" or \"Scissors\"]")