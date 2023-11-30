from django.shortcuts import render
from django.http import HttpResponseRedirect, HttpResponse
from django.contrib.auth import login, logout, authenticate
from django.urls import reverse
from django.db import IntegrityError

# Create your views here.

from .models import User

def home(request):
  # return render(request, 'manage_users/test.html')
  return render(request, 'manage_users/index.html')
  

def login_view(request):
  if request.method == "POST":
    username = request.POST["username"]
    password = request.POST["password"]
    user = authenticate(request=request, username=username, password=password)
    if not (user == None):
      login(request, user)
      return render(request, 'manage_users/index.html', {
        "message":f"Logged in as {username}"
      })
    else:
      return render(request, 'manage_users/login.html', {
        "message": "Invalid Credentials"
      })
  else:
    return render(request, 'manage_users/login.html')

def logout_view(request):
  logout(request)
  return HttpResponseRedirect(reverse('home'))

def register(request):
  if request.method == "POST":
    username = request.POST["username"]
    email = request.POST["email"]
    password = request.POST["password"]
    try:
      user = User.objects.create_user(username, email, password)
    except IntegrityError:
      return render(request, 'manage_users/register.html', {
        "message":"User credentials have already been taken"
      })
    login(request, user)
    return HttpResponseRedirect(reverse('home'))
  return render(request, 'manage_users/register.html')
 