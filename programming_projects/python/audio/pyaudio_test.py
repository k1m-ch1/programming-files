import pyaudio
import wave

# Parameters
CHUNK = 2
FORMAT = pyaudio.paInt16
CHANNELS = 1  # Stereo for output recording
RATE = 16000 

# Initialize PyAudio
p = pyaudio.PyAudio()

# Find your loopback device index
DEVICE_INDEX = 1  # Replace with the index of your loopback device

# Open audio stream
stream = p.open(format=FORMAT,
                channels=CHANNELS,
                rate=RATE,
                input=True,
                input_device_index=DEVICE_INDEX,
                frames_per_buffer=CHUNK)

print("Recording system audio... Press Ctrl+C to stop.")

try:
    # Save audio to file
    with wave.open("output.wav", "wb") as wf:
        wf.setnchannels(CHANNELS)
        wf.setsampwidth(p.get_sample_size(FORMAT))
        wf.setframerate(RATE)
        while True:
            data = stream.read(CHUNK)
            wf.writeframes(data)  # Write the captured audio data
            # Process `data` as needed
            # print(f"Captured {len(data)} bytes") 
except KeyboardInterrupt:
    print("Stopping...")

# Stop and close the stream
stream.stop_stream()
stream.close()
p.terminate()
