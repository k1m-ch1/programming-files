import asyncio
import time

async def bar():
  print("Sleeping for 2 seconds....")
  await asyncio.sleep(2)
  print("bar finished executing!")

async def foo():
  print("Foo began executing")
  task = asyncio.create_task(bar())
  print("Foo finished executing")
  await task
  

asyncio.run(foo())
  