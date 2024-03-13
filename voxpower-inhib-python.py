import serial
import time

# Define the serial port and baud rate
arduino = serial.Serial(port='COM3', baudrate=115200, timeout=1)
time.sleep(2)

def inhibit(channel):
    """Sends an "I" command to activate the specified inhibit channel."""
    command = "I" + str(channel)  # Construct the command string with "I" prefix
    arduino.write(command.encode())  # Encode and send the command

def enable(channel):
    """Sends an "E" command to dactivate the specified inhibit channel."""
    command = "E" + str(channel)  # Construct the command string with "E" prefix
    arduino.write(command.encode())  # Encode and send the command


inhibit(8)
time.sleep(1)
enable(8)
time.sleep(1)
inhibit(9)
time.sleep(1)
enable(9)


arduino.close()