class Animal:
  def __init__(self, age):
    self.age = age
  
  def get_class(self):
    return 'Animal'

  def print_info(self):
    print("Age of Animal: {}".format(self.age))
  
  def get_age(self):
    return self.age
  
class Dog(Animal):
  def __init__(self, name, age):
    Animal.__init__(self, age)
    self.name = name

  def get_name(self):
    return self.name
  
  def print_info(self):
    print("Name of Animal: {}\nAge of Animal: {}".format(self.name, self.age))

some_animal = Animal(10)
some_dog = Dog('bozoi', 20)
some_dog.print_info()
  
  
  