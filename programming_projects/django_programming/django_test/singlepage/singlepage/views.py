from django.shortcuts import render
from django.http import Http404, HttpResponse

def index(request):
  return render(request, 'singlepage/index.html')
  
my_text = ["Lorem ipsum dolor sit amet, consectetur adipiscing elit. Ut vitae magna eros. Integer porta vel tortor a lobortis. Sed mauris sapien, porta sed neque eu, maximus sodales erat. Curabitur accumsan ipsum sed elit eleifend, id tincidunt nunc ornare. Nulla interdum vitae lectus in tincidunt. Donec velit felis, elementum at imperdiet eget, laoreet vitae nisl. Maecenas id est mi. Nam et leo a ligula pellentesque consectetur. Nunc ac massa metus. Ut sed aliquet lacus. Integer rutrum aliquam nisi. Fusce mollis dolor eget diam accumsan dapibus. Aliquam varius varius tellus sit amet pharetra.",
           "Curabitur at dolor non leo vestibulum dapibus. Quisque faucibus metus ac dapibus auctor. Integer posuere nunc nulla, nec suscipit velit sollicitudin et. Aliquam ornare erat id mauris vehicula scelerisque. Sed mattis mi arcu, vel imperdiet erat posuere non. Vestibulum eu dapibus enim, sed dictum quam. Quisque sed lacinia magna, sed ornare quam. Donec faucibus aliquam mauris, eu sagittis turpis venenatis sed. Fusce porttitor at leo ut consectetur. Cras consectetur dignissim mi ac lacinia. Aliquam vehicula, leo sed finibus aliquam, sapien ex faucibus velit, id ornare justo sem id lacus. In vitae sem sapien. Pellentesque faucibus porttitor dapibus. Donec sit amet aliquam turpis.",
           "Donec ut nibh et ante facilisis rutrum. Aenean id ipsum tincidunt, porta nisl vel, accumsan sapien. Fusce ac odio faucibus, scelerisque velit non, mattis ligula. Curabitur imperdiet sodales nisl, non efficitur enim molestie at. Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nunc semper, sapien sit amet scelerisque auctor, felis lorem sollicitudin ipsum, vitae ultricies dui justo sit amet ipsum. Mauris nec ligula vel orci auctor cursus ac eu urna. Nullam faucibus, nibh sed varius lacinia, mi dolor cursus metus, ac scelerisque nulla arcu et risus."]

def show_page(request, page_number):
  if request.method == "GET":
    if page_number < 1 or page_number > 3:
      return Http404("page_number needs to be between the range of 1 and 3")
    else:
      return HttpResponse(my_text[page_number-1]);