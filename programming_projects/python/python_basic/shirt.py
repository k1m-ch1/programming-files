from PIL import Image, ImageOps, ImageFilter

elit = Image.open(r"python_basic/images/elit.jpg")

elit = ImageOps.fit(elit,(600, 600))
# str_func = {
#   'BLUR':elit.filter(filter=ImageFilter.BLUR()),
#   'BoxBlur':elit.filter(filter=ImageFilter.BoxBlur()),
#   'BuiltinFilter':elit.filter(filter=ImageFilter.BuiltinFilter()),
#   'CONTOUR':elit.filter(filter=ImageFilter.CONTOUR()),
#   'Color3DLUT':elit.filter(filter=ImageFilter.Color3DLUT()),
#   'DETAIL':elit.filter(filter=ImageFilter.DETAIL()),
#   'EMBOSS':elit.filter(filter=ImageFilter.EMBOSS()),
#   'Filter':elit.filter(filter=ImageFilter.Filter()),
#   'GaussianBlur':elit.filter(filter=ImageFilter.GaussianBlur()),
#   'Kernel':elit.filter(filter=ImageFilter.Kernel()),
#   'MaxFilter':elit.filter(filter=ImageFilter.MaxFilter()),
#   'MedianFilter':elit.filter(filter=ImageFilter.MedianFilter()),
#   'MinFilter':elit.filter(filter=ImageFilter.MinFilter()),
#   'ModeFilter':elit.filter(filter=ImageFilter.ModeFilter()),
#   'MultibandFilter':elit.filter(filter=ImageFilter.MultibandFilter()),
#   'RankFilter':elit.filter(filter=ImageFilter.RankFilter()),
#   'SHARPEN':elit.filter(filter=ImageFilter.SHARPEN()),
#   'SMOOTH':elit.filter(filter=ImageFilter.SMOOTH()),
#   'UnsharpMask':elit.filter(filter=ImageFilter.UnsharpMask()),
#   'functools':elit.filter(filter=ImageFilter.functools()),
# }
elit_new = elit.filter(filter=ImageFilter.EMBOSS())
elit_new.save("python_basic/images/new_elit.jpg")
elit_new = Image.open("python_basic/images/new_elit.jpg")
elit.save("python_basic/images/new_elit.gif", save_all=True, append_images= elit_new, duration = 200, loop=0)
# for i in enumerate(dir(ImageFilter)):
#   elit = str_func[i]
#   elit.save(f"python_basic/images/elit_{i}.png")

