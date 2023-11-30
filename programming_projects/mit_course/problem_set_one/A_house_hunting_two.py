annual_salary = int(input("Enter your annual salary: "))
portion_saved = float(input("Enter the percent of your salary to save, as a decimal: "))
total_cost = int(input("Enter the cost of your dream home: "))
r,current_savings,portion_down_payment,number_of_month = 0.04, 0, total_cost * 0.25, 0
monthly_salary = annual_salary/12
while(current_savings < portion_down_payment):
  number_of_month += 1
  current_savings += current_savings * (r/12)
  current_savings += monthly_salary * portion_saved
print(f"Number of months: {number_of_month}")
  
  