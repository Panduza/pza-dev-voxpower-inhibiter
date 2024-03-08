---
title: "pza-dev-voxpower-inhibiter"
wheigth: 
---

# pza-dev-voxpower-inhibiter

Defintion of the middleware to pilot the VoxPower by inhibiting the output modules.

### Board used

The board used for this middleware **must** be an Arduino UNO


### Cables

The connection between the PC and the Arduino **must** be via an USB cable

The connection between the Arduino and the Vox Power ***must** be via simple cables linked to the connectors

### Connectors

The connectors for the Vox Power **must** be :

|        | Manufacturer | Housing   | Terminal  |
| :----- | :----------: | :-------: | :-------: |
| Input  | Molex        | 510210600 | 500588000 |
| Output | Molex        | 511101251 | 503948051 |

### Pinout

The input pinout **must** be :

| Pin    | 1        | 2        | 3        | 4        | 5        | 6        |
| :----- | :------: | :------: | :------: | :------: | :------: | :------: |
| Signal | COM      | 5V       | SD       | reserved | reserved | reserved |


The output pintout **must** be :

| Pin    | 1    | 2    | 3    | 4    | 5    | 6    | 7    | 8    | 9    | 10   | 11   | 12   |
| :----- | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: |
| Signal | PG   | INH  |  PG  | INH  | PG   | INH  | PG   | INH  | GINH | ACOK | 5V   | COM  |

### Software

The command sent by the PC to the Arduino to inhibit an output module **must** be a Python function like
```bash
inhibit(output_module)
```

that will send a json payload at 115200 baudrate via USB serial port :
```json
{
    "inhibit pins": <pins_to_inhibit>
}
```

Then the Arduino **must** send for the corresponding pin
```bash
digitalWrite(pin, HIGH)
```

### Arduino pins 

The pins used to send the commands signals from the Arduino to the Vox output **must** be D0 to D11 GPIO pins.
To ihibit an output module the signal **must** be 5V.