#include <Arduino.h>

void setup() {

  // Set pin modes for channels
  for (int i = 2; i < 6; i++) {
    pinMode(i, OUTPUT);
  }
  for (int i = 14; i < 18; i++) {
    pinMode(i, OUTPUT);
  }


  // Start serial communication (default baud rate is 9600)
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    // Receive a message with one character for command to set the pin state and one character for the id of the pin
    char command = Serial.read();
    int channel = Serial.readStringUntil('\n').toInt(); // Convert ASCII digit to integer
    channel += 1; // Channels 1 to 4 of the Voxpower corresponds to the Pin 2 to 5 of the arduino
    if (channel > 5) {
      channel += 8; // Cannels 5 to 8 of the Voxpower corresponds to the Pin 14 to 17 of the arduino
    }

    if (command == '?' ) {
      Serial.write("OK\n");

    } else if (command == 'I') {
      // Inhibit channel
      digitalWrite(channel, HIGH);

      Serial.write("OK\n");

    } else if (command == 'E') {
      // Enable channel
      digitalWrite(channel, LOW);
      
      Serial.write("OK\n");

    } else if (command == 'S') {
      // Get channel state

      if (digitalRead(channel) == HIGH) {
        Serial.write("H\n");
        
      } else {
        Serial.write("L\n");
      }
    }
    // Flush the buffer to immediately send the response
    Serial.flush();
  }
}
