import functools
from operator import add, mul
# Create your views here.

class formula:
  def __init__(self, variables):
    """
      Variables is a list and in that list contains a tuple of tuple.
      The first layer of tuple represents some variables that will add together.
      The second layer of tuple represents a fraction where the top is the nominator and the bottom is the denominator.
      The third layer of tuple represents tuples that will multiply it self.
      The fourth layer of tuple holds 2 info, ('name', 'unit'). Ex. ('radius', 'm')
      Ex.
    """
    self.variables = variables
  
  def get_variables(self):
    """
      Get the name of all of the variables as a list of string.
    """
    ret_val = set()
    for i in self.variables:
      for j in i:
        if type(j) == tuple:
          for k in j:
            if type(k) == tuple:
              ret_val.add(k[0])
    return list(ret_val)
  
  def calculate(self, request):
    """
      request is a django class that contains information about the post request.
    """
    
    def get_val(formatted_tuple):
      """
        formatted_tuple is a tuple of size 2.
        ('name', 'unit')
        Ex.
        ('radius', 'm')
      """
      if formatted_tuple == tuple:
        return float(request.POST[formatted_tuple[0]])
      else:
        return float(formatted_tuple)
    
    def evaluate_fraction(fraction):
      for i, tuple_to_num in enumerate(fraction):
        if tuple_to_num == tuple:
          tuple_to_num = map(get_val, tuple_to_num)
          fraction[i] = functools.reduce(mul, tuple_to_num)
      return fraction[0]/fraction[1]
        
    
    variables_temp = self.variables.copy()
    ret_val = float()
    for i in variables_temp:
      ret_val += map(evaluate_fraction, i)
    
    return ret_val
      
      
      


type_of_formulas = ["area", "volume", "electricity", "kinematics", "thermodynamics"]
nav_in_type_of_formulas = {
  "area":["square", "rectangle", "right triangle", "circle"],
  "volume":["cube", "cuboid", "cylinder", "cone", "sphere"],
  "electricity":["resistance", "current", "voltage", "capacitance"],
  "kinematics":["velocity", "acceleration"],
  "thermodynamics":["heat"]
  }
BASE = ('base', 'm')
LENGTH = ('length', 'm')
HEIGHT = ('height', 'm')
RADIUS = ('radius', 'm')
RESISTIVITY = ('resistivity', 'ohm*m')
CHARGE = ('charge', 'C')
CURRENT = ('current', 'A')
CAPACITANCE = ('capacitance', 'F')
DISTANCE = ('distance', 'D')
TIME = ('time', 's')
HEAT = ('heat', 'J')
ACCELERATION = ('acceleration', 'ms^(-2)')
VELOCITY = ('velocity', 'ms^(-1)')
HEAT_CAPACITY = ('J(mk)^(-1)')
formulas = {'square': formula([((LENGTH, LENGTH),1)]), 
            'rectangle': None, 
            'right triangle': None, 
            'circle': None, 
            'cube': None, 
            'cuboid': None, 
            'cylinder': None, 
            'cone': None, 
            'sphere': None, 
            'resistance': None, 
            'current': None, 
            'voltage': None, 
            'capacitance': None, 
            'velocity': None, 
            'acceleration': None, 
            'heat': None}
