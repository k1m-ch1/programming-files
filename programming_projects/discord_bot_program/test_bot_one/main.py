import discord
from discord.ext import commands

client = commands.Bot(command_prefix='!', intents=discord.Intents.all())

@client.event
async def on_ready():
  print("The bot is ready for use")
  print("--------------------")

@client.command()
async def hello(request):
  await request.send("Hello!")

@client.command()
async def goodbye(ctx):
  await ctx.send("Goodbye!")

client.run('MTEwNzE1NzMyNjU0NjM1MDE0MA.GMSS-e.i3JsByd10O8YbH5dcb7p5Mx5qJ_F3t9edGYXUE')