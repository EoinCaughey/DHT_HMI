from flask import Flask, render_template
from serial_reader import (
    temperature_buffer as temp,
    humidity_buffer as hum,
    time_buffer as time
    )   

app = Flask(__name__)

@app.route("/")
def home():
    return render_template("index.html")

@app.route("/live")
def live():
    return {
        "temperature": list(temp),
        "humidity": list(hum),
        "time": list(time)
    }

app.run(debug=False, use_reloader = False)