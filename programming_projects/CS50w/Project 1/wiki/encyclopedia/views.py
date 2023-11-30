from django.shortcuts import render
from markdown2 import Markdown
from . import util
from django.http import HttpResponse
import re
import random

def index(request):
    if request.method == "POST":
        x = request.POST["title"]
        if request.POST["edit"] == "true":
            util.save_entry(x, request.POST["content"])
        elif x not in util.list_entries() and request.POST["edit"] == "false":
            util.save_entry(x, request.POST["content"])
        else:
            return HttpResponse("ERROR! Page already exists!")
    return render(request, "encyclopedia/index.html", {
        "entries": util.list_entries()
    })

def display_page(request, page_name):
    def cvt():
        if (obj:=util.get_entry(page_name)) == None: 
            return None
        return Markdown().convert(obj)
    return render(request, "encyclopedia/page.html", {"page":cvt(), "page_name":page_name})

def handle_search(request):
    search_result = request.POST['q']
    get_page = util.get_entry(search_result)
    if get_page == None:
        return render(request, "encyclopedia/refer.html", {"possible_entries":[x for x in util.list_entries() if search_result in x.lower()]})
        #return HttpResponse(f"NOT FOUND!\nVisit: {[x for x in util.list_entries() if search_result in x.lower()]}")
    else:
        return display_page(request, search_result)
    # return render(request, "") 

def randomize(request):
    return display_page(request, random.choice(util.list_entries()))

def new(request):
    if request.method == "POST":
        return render(request, "encyclopedia/new.html", {
            "title":request.POST["title"],
            "content":request.POST["content"],
            "edit":"true"
        })
    return render(request, "encyclopedia/new.html", {"edit":"false"})




    
    
