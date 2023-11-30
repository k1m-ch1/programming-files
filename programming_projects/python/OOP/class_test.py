class Fraction:
  id = 1
  def __init__(self, numerator, denomenator):
    self.numerator = numerator
    self.denomenator = denomenator
    self.id = Fraction.id
    Fraction.id += 1
  
  def get_numerator(self):
    return self.numerator

  def get_denomenator(self):
    return self.denomenator
  
  def get_fraction(self):
    return (self.get_numerator(), self.get_denomenator())
  
  def __add__(self, other):
    return Fraction((self.numerator*other.denomenator) + (other.numerator*self.denomenator), self.denomenator * other.denomenator)
  
  def float(self):
    return self.numerator/self.denomenator

fraction_one = Fraction(1,2)
fraction_two = Fraction(3,2)
fraction_three = fraction_one + fraction_two
print(fraction_one.id, fraction_two.id, fraction_three.id)
print((fraction_three + Fraction(1,2)).get_fraction())
fraction_four = Fraction(10,2)
print(fraction_four.id)
    