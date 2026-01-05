/*
  ESP8266 RS485 Receiver
  Receives servo angle over RS485 and moves servo
*/
#include <SoftwareSerial.h>
#include <Servo.h>

#define RS485_RX D1   // GPIO5
#define RS485_TX D2   // GPIO5
#define SERVO_PIN D0  // GPIO16
SoftwareSerial rs485(RS485_RX, RS485_TX);
Servo myServo;
String incoming = "";

void setup() {
  Serial.begin(115200);
  Serial.println("RS485 Receiver Started");

  rs485.begin(9600);   // RX only
  myServo.attach(SERVO_PIN);
  myServo.write(0);
}

void loop() {
  while (rs485.available()) {
    char c = rs485.read();

    if (c == '\n') {
      processMessage(incoming);
      incoming = "";
    } else {
      incoming += c;
    }
  }
}

void processMessage(String msg) {
  if (msg.startsWith("S:")) {
    int angle = msg.substring(2).toInt();
    angle = constrain(angle, 0, 180);

    myServo.write(angle);

    Serial.print("Servo angle: ");
    Serial.println(angle);
  }
}
