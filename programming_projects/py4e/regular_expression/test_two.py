import re

# sample_text = """
# From: stephen.marquard@uct.ac.za, 
# csev@umich.edu, and 
# cwen @iupui.edu"""

# sample_text = "My roll number is 25"

# raw_string = r"From: [a-zA-Z]"
# ret_result = re.search(raw_string, sample_text)
# print(ret_result)

sample_text = """
From stephen.marquard@uct.ac.za Sat Jan  5 09:14:16 2008
Return-Path: <postmaster@collab.sakaiproject.org>
          for <source@collab.sakaiproject.org>;
Received: (from apache@localhost)
Author: stephen.marquard@uct.ac.za"""

sample_text_two = """
  09:14:16
  12-34-56
  31*12*22
  9,11,01
  23)10)93
  123-456-7891
"""

sample_text_two = sample_text_two.rstrip()
raw_string = r"\d+.\d+.\d+"
some_object = re.compile(raw_string)
ret_value = some_object.finditer(sample_text_two)
for i in ret_value:
  print(i)