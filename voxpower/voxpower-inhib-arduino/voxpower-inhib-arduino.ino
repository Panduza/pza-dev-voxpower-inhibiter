#include <Arduino.h>

void setup() {
  // Serial.setTimeout(1000);

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
    // const char response[] = ;
    // Serial.write(command);
    if (channel > 5) {
      channel = channel + 8;
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
        const char message[] = "H";
        Serial.write(message, sizeof(message) - 1);
        Serial.flush();
        
      } else {
        const char message[] = "L";
        Serial.write(message, sizeof(message) - 1);
        Serial.flush();
      }
    }
    Serial.flush();
  }
}
