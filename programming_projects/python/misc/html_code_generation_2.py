format_string = lambda x: [f"<section class=\"main-section\" id=\"{i}\">\n\t<header>{i}</header>\n</section>\n" for i in x]
def replace_space(my_str):
  temp_list = my_str.split()
  my_str = ""
  for i in temp_list:
    my_str += i + "_"
  return my_str[:-1]

format_navigation = lambda x: [f"<a class=\"nav-link\" href=\"#{replace_space(i)}\">{i}</a>" for i in x]
my_list = ["Introduction", "What you should know already", "JavaScript and Java", "Hello world", "Declaring variables", "Variable scope", "Global variables", "Constants", "Data types", "if...else statement", "while statement", "Function declarations", "Reference"]
for i in format_navigation(my_list):
  print(i)