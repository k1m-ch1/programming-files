import serial
import pyautogui
import time

hc05 = serial.Serial("com8", 9600);

print("Waiting 3 seconds...");
time.sleep(3);
while True:
  recv_msg = hc05.readline();
  if b"pressleft" in recv_msg: pyautogui.press("left");
  if b"pressright" in recv_msg: pyautogui.press("right");