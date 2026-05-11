import serial
from collections import deque
import threading
import time
from datetime import datetime

ser = serial.Serial(
    port='COM3',
    baudrate=115200,
    timeout=1
)

temperature_buffer = deque(maxlen=300)
humidity_buffer = deque(maxlen=300)
time_buffer = deque(maxlen=300)


def read_serial():
    while True:
        
        line = ser.readline().decode().strip()

        if not line:
            continue

        values = line.split(",")

        if len(values) != 2:
            continue

        try:
            temperature = float(values[0])
            humidity = float(values[1])

        except:
            continue

        temperature_buffer.append(temperature)
        humidity_buffer.append(humidity)
        time_buffer.append(datetime.now().strftime("%H:%M:%S"))

        time.sleep(0.01)

threading.Thread(target=read_serial, daemon=True).start()