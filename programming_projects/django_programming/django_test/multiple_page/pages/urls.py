from django.urls import path

from . import views
urlpatterns = [
  path('', views.index, name="index"),
  path('pages/<int:page>', views.show_page, name="show_page")
]