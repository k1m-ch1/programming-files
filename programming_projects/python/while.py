import random
secret_number = random.randint(0, 10)
number_of_tries = 0
max_tries = 3
complete = False
while number_of_tries < max_tries:
  guess = int(input("Guess: "))
  number_of_tries = number_of_tries + 1
  if guess == secret_number:
    print("congratulation")
    complete = True
    break
  else:
    print("wrong choice, guess number" + str(number_of_tries))

if complete == False:
  print(f"Try again next time, the correct answer is {secret_number}")

