// Basic test for STHS34PF80 infrared sensor

#include "Adafruit_STHS34PF80.h"

Adafruit_STHS34PF80 sths;

void setup() {
  Serial.begin(115200);
  while (!Serial) delay(10);

  Serial.println("Adafruit STHS34PF80 test!");

  if (!sths.begin()) {
    Serial.println("Could not find a valid STHS34PF80 sensor, check wiring!");
    while (1) delay(10);
  }

  Serial.println("STHS34PF80 Found!");
}

void loop() {
  delay(1000);
}