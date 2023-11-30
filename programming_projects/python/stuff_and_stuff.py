heat = lambda m, c , tf, ti: m*c*(tf-ti)

my_list = [(10, 0.22, 25, 0, "cal"),
           (150, 1, 75, 15, "cal"),
           (250, 1, 95, 45, "cal"),
           (1.5, 4190, 95, 5, "J"),
           (2.5, 4200, 50, 25, "J")]

i = 0
for a, b, c, d, unit_type in my_list:
  i+=1
  print(f"{i}. {int(heat(a, b, c, d))} {unit_type}")
