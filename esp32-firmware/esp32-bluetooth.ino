#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32_BT"); // Bluetooth device name
  Serial.println("ESP32 Bluetooth Device Started, Waiting for pairing...");
}

void loop() {
  if (SerialBT.available()) {
    String incoming = SerialBT.readStringUntil('\n');
    Serial.println("Received: " + incoming);

    if (incoming.indexOf("ON") >= 0) {
      Serial.println("Turning something ON");
      // digitalWrite(LED_PIN, HIGH); // Example for controlling something
    }
    else if (incoming.indexOf("OFF") >= 0) {
      Serial.println("Turning something OFF");
      // digitalWrite(LED_PIN, LOW);
    }
  }
}
