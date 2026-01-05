/*
  ESP8266 RS485 Sender
  Reads potentiometer on A0 and sends value over RS485
*/
#include <SoftwareSerial.h>
#define RS485_RX D2
#define RS485_TX D1   // GPIO5
SoftwareSerial rs485(RS485_RX, RS485_TX);
void setup() {
  Serial.begin(115200);
  Serial.println("RS485 Sender Started");

  rs485.begin(9600);   // TX only on ESP8266
}

void loop() {
  int potValue = analogRead(A0);          // 0 - 1023
  int mappedValue = map(potValue, 0, 1023, 0, 180);

  // Send as ASCII message
  rs485.print("S:");
  rs485.println(mappedValue);

  Serial.print("Sent: ");
  Serial.println(mappedValue);

  delay(100);
}
