import re
import operator
import random
import time
from datetime import datetime
import csv

list_of_operators = [(operator.add, "+"), (operator.sub, "-"), (operator.mul, "\u00D7")]

def select_mode():
    yn_pattern = r'^[YN]{3}$'
    with open("./sources/welcome_message.txt", 'r') as file:
        mode_select = input(file.read()).upper()
        while not re.match(yn_pattern, mode_select):
            pass
    return [opp for yn, opp in zip(mode_select, list_of_operators) if yn == 'Y']


def main():
    run_date = datetime.now().strftime("%Y-%m-%d_%H-%M-%S")
    selected_mode = select_mode()
    data = []
    int_pattern = r"^[0-9]+$|^-[0-9]+$"
    exit_pattern = r"^exit$"
    while not re.match(int_pattern, number_of_questions:=input("How many questions this session: ")):
        print("Invalid input, please input an integer.")
    number_of_questions = int(number_of_questions)
    for i in range(1, number_of_questions+1):
        a = random.randint(1, 19)
        b = random.randint(1, 9)
        selected_opp = random.choice(selected_mode)
        answer = selected_opp[0](a, b)
        start_time = time.time()
        print(f"Question number {i}: {a} {selected_opp[1]} {b}")
        while not re.match(f"{int_pattern}|{exit_pattern}", result:=input("Answer: ")):
            pass

        if result == "exit":
            print(f"You answered {i-1} out of {number_of_questions} questions. exiting the program... ")
            break
        result = int(result)
        data.append([a, selected_opp[1], b, result, answer, result == answer, time.time() - start_time])
        print(f"Correct answer: {answer}, Time taken: {data[-1][-1]:.02f} seconds\n")

    with open("./output/"+run_date+".csv", 'w') as file:
        writer = csv.writer(file)
        writer.writerow(["a", "operator", "b", "your answer", "correct answer", "correct?", "time taken"])
        writer.writerows(data)
    
    number_of_correct_ans = len([0 for d in data if d[5]])
    print(f"You got {number_of_correct_ans} out of {len(data)} correct. ({(number_of_correct_ans/len(data)) * 100:.02f}%). File name is {run_date}")
    
    






if __name__ == "__main__":
    main()