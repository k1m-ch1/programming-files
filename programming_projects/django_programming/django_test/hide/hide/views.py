from django.shortcuts import render
from django.http import HttpResponse, Http404, JsonResponse

import time

def index(request):
  return render(request, 'hide/index.html')

def request_content(request):
  if request.method == 'GET':
    from_index = int(request.GET.get('from'))
    to_index = int(request.GET.get('to'))
    ret_list = []
    for i in range(from_index, to_index):
      ret_list.append(f"POST #{i}")
    return JsonResponse({"post": ret_list})
    
    