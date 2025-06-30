from django.urls import path
import random
from . import views
from . import util
app_name = "encyclopedia"

urlpatterns = [
    path("", views.index, name="index"),
    path("<str:page_name>/", views.display_page, name="page"),
    path("encyclopedia/search/", views.handle_search, name="search"),
    path("encyclopedia/random/", views.randomize, name="random"), 
    path("encyclopedia/new", views.new, name="new")
]
