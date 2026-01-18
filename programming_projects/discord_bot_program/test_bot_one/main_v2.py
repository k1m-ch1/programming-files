import discord
import os
from dotenv import load_dotenv

laod_dotenv()

class MyClient(discord.Client):
  async def on_ready(self):
    print(f"Logged on as {self.user}")
    
  async def on_message(self, message):
    if not message.author == client.user:
      await message.channel.send("Message sent!")
      print(f"Message from {message.author}: {message.content}")
  
intents = discord.Intents.default()
intents.message_content = True

client = MyClient(intents=intents)
client.run(os.getenv("API_KEY"))
