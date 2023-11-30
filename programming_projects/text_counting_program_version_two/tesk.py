import re

ret_val = re.search(r"^From:","From: ")
if ret_val == None:
  print("NOthing found")
else:
  print(f"Something found {ret_val}")