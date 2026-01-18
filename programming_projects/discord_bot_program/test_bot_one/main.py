import discord
from discord.ext import commands
import os
from dotenv import load_dotenv

load_dotenv()

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

client.run(os.getenv("API_KEY"))
