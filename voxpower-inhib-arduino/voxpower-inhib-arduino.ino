#include <Arduino.h>

void setup() {
  // Set pin modes for channels (adjust based on your needs)
  for (int i = 2; i < 10; i++) {
    pinMode(i, OUTPUT);
  }

  // Start serial communication (default baud rate is 9600)
  Serial.begin(115200);
}

void loop() {
  if (Serial.available()) {
    char command = Serial.read();
    int channel = Serial.readString().toInt(); // Convert ASCII digit to integer

    if (command == 'I') {
      // Inhibit channel
      digitalWrite(channel, HIGH);
    } else if (command == 'E') {
      // Enable channel
      digitalWrite(channel, LOW);
    } else if (command == 'S') {
      // Get channel state
      if (digitalRead(channel) == HIGH) {
        Serial.write('H');
      } else {
        Serial.write('L');
      }
    }
  }
}