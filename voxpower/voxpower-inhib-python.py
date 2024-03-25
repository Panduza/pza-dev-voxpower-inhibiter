import serial
import time

# Define the serial port and baud rate
arduino = serial.Serial(port='COM4', baudrate=115200, timeout=1)
time.sleep(2)

def inhibit(channel):
    """Sends an "I" command to activate the specified inhibit channel."""
    command = "I" + str(channel) + "\n"  # Construct the command string with "I" prefix
    arduino.write(command.encode())  # Encode and send the command
    print(command)

def enable(channel):
    """Sends an "E" command to dactivate the specified inhibit channel."""
    command = "E" + str(channel) + "\n"  # Construct the command string with "E" prefix
    arduino.write(command.encode())  # Encode and send the command

def get_pin_state(channel):
    """Sends an "S" command to request the state of the specified channel and reads the response."""
    command = "S" + str(channel) + "\n"  # Construct the command string with "S" prefix
    arduino.write(command.encode())  # Encode and send the command

    # Read response (assuming Arduino sends a single character 'H' or 'L')
    response = arduino.read().decode()
    if response == 'H':
        return True
    elif response == 'L':
        return False
    
print("start")
inhibit(9)
time.sleep(3)
print("stop")
enable(9)


"""
inhibit(8)
time.sleep(1)
enable(8)
time.sleep(1)
inhibit(9)
time.sleep(1)
enable(9)
"""

arduino.close()