import math

def power_by(power):
  def power_return(operand):
    return pow(operand, power)
  return power_return

power_to_base_3 = power_by(5)
print(power_to_base_3(3))

  