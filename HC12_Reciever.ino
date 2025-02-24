#include <SoftwareSerial.h>
SoftwareSerial HC12(10, 11);  // RX, TX

void setup() {
  Serial.begin(9600);
  HC12.begin(9600);
}

void loop() {
  if (HC12.available()) {
    String receivedMessage = " ";

    while (HC12.available()) {
      char c = HC12.read();
      if (c != '\n' && c != '\r') {  
        receivedMessage += c;
      }
      delay(5);  
      if (receivedMessage.startsWith("Sent: ")) {
      receivedMessage = receivedMessage.substring(6);  
      }
    }
 
    Serial.print("Received:");
    Serial.println(receivedMessage);
  }
}












