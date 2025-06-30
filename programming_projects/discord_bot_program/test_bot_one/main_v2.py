import discord

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
client.run('MTEwNzE1NzMyNjU0NjM1MDE0MA.GMSS-e.i3JsByd10O8YbH5dcb7p5Mx5qJ_F3t9edGYXUE')