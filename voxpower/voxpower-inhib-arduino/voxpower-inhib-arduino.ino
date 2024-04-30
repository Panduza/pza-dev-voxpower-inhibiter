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
  Serial.begin(115200);
}

void loop() {
  if (Serial.available()) {
    
    char command = Serial.read();
    int channel = Serial.readStringUntil('\n').toInt(); // Convert ASCII digit to integer
    if (channel > 5) {
      channel = channel + 8;
    }

    if (command == 'I') {
      // Inhibit channel
      digitalWrite(channel, HIGH);
      Serial.write('H');

    } else if (command == 'E') {
      // Enable channel
      digitalWrite(channel, LOW);
      Serial.write('L');

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
