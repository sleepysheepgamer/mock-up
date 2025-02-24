#include <SoftwareSerial.h>
SoftwareSerial HC12(10, 11);  // RX, TX

void setup() {
  Serial.begin(9600);
  HC12.begin(9600);
}

void loop() {
  if (Serial.available()) {
    String messageToSend = " ";

    while (Serial.available()) {
      char c = Serial.read();
      messageToSend += c;
      delay(5); 
    }

    HC12.println(messageToSend);
    Serial.print("Sent:");
    Serial.println(messageToSend);
  }
}

