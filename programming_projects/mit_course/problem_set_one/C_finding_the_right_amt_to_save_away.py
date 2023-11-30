#pasted from "A_house_hunting_two.py"
import math
annual_salary = int(input("Enter your annual salary: "))
portion_saved = 1
total_cost = 1000000
semi_annual_raise = 0.07
r,current_savings,portion_down_payment = 0.04, 0, total_cost * 0.25
monthly_salary = annual_salary/12
steps = 0
thing = 0.5
while True:
  steps += 1
  current_savings = 0
  monthly_salary = annual_salary/12
  for i in range(36):
    current_savings += current_savings * (r/12)
    current_savings += monthly_salary * portion_saved
    if (i+1)%6 == 0:  monthly_salary += monthly_salary * semi_annual_raise
  if (math.floor(current_savings/100)*100) == portion_down_payment:
      break
  elif math.floor(current_savings) < portion_down_payment:
    print("Yes")
    portion_saved = portion_saved + thing
    if portion_saved > 1:
      print("Will never save enough in 3 years")
      quit()
  else:
    portion_saved = portion_saved - thing
  thing = thing/2
print("Best savings rate: {}".format(portion_saved))
print("Steps in bisection search: {}".format(steps))
