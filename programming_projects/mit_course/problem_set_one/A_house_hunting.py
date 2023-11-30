# total_cost = 100000
# portion_down_payment = 0.25
# current_savings = 0
# r = 0.04
# annual_salary = 
# portion_saved = annual_salary * 
import math

annual_salary = int(input("What is your annual salary: "))

monthly_salary = annual_salary/12

portion_saved = float(input("How much portion of your monthly salary you want to save(in decimals): "))
portion_saved = monthly_salary * portion_saved

Total_cost = int(input("How much is the cost of your dream cost: "))
print(portion_saved)
portion_down_payment = 0.25 * Total_cost

current_saving = 0
number_month = 0
finish = False

while finish == False:
  number_month = 1 + number_month
  percent_saved = portion_saved * 0.4/12
  current_saving = percent_saved + portion_saved
  print(current_saving)
  if math.floor(current_saving) >= portion_down_payment:
    finish = True
  else:
    portion_saved = current_saving + portion_saved
    
print(f"You will need ti save up for {number_month}months")
  
  





