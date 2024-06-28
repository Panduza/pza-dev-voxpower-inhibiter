#include <Arduino.h>

void setup() {

  // Set pin modes for channels (adjust based on your needs)
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
    char command = Serial.read();
    int channel = Serial.readStringUntil('\n').toInt(); // Convert ASCII digit to integer
    channel += 1; // Channels 1 to 4 of the Voxpower corresponds to the Pin 2 to 5 of the arduino
    if (channel > 5) {
      channel += 8; // Cannels 5 to 8 of the Voxpower corresponds to the Pin 14 to 17 of the arduino
    }

    if (command == 'I') {
      // Inhibit channel
      digitalWrite(channel, HIGH);

    } else if (command == 'E') {
      // Enable channel
      digitalWrite(channel, LOW);

    } else if (command == 'S') {
      // Get channel state

      if (digitalRead(channel) == HIGH) {
        Serial.write("H");
        
      } else {
        Serial.write("L");
      }
      Serial.flush();
    }
  }
}
