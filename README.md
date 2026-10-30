# LED Finger Detection

Lights up LEDs on an Arduino to match the fingers a webcam sees you holding up. A Python script on the computer does the hand tracking and sends simple serial commands to the board, which switches the LEDs.

## What's in this repo

`ledcontrol/ledcontrol.ino` is the Arduino side. It listens on serial at 9600 baud and drives five LEDs on pins 8 through 12.

The Python hand tracking script is not committed yet.

## Serial protocol

One command per line:

```
LED8 ON
LED8 OFF
```

The number is the Arduino pin (8 to 12). Commands for any other pin are ignored.

## Wiring

Connect each LED's anode through a 220 Ω resistor to pins 8, 9, 10, 11, and 12, with every cathode going to GND.

## Running it

1. Open `ledcontrol/ledcontrol.ino` in the Arduino IDE and upload it to the board.
2. Test it from the Serial Monitor (9600 baud, newline line ending) by typing `LED8 ON`.
3. From Python, send the same strings with pyserial:

```python
import serial, time
board = serial.Serial("COM3", 9600)   # use your board's port
time.sleep(2)                          # the board resets when the port opens
board.write(b"LED8 ON\n")
```
