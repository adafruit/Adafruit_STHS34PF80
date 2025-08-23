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
  if (!sths.isDataReady()) {
    delay(10);
    return;
  }
  
  Serial.print("Data ready! ");
  
  // Read temperature data
  Serial.print("Amb: ");
  Serial.print(sths.readAmbientTemperature(), 2);
  Serial.print("°C");
  
  // Check for presence and show data if detected
  if (sths.isPresence()) {
    Serial.print(" PRESENCE: ");
    Serial.print(sths.readPresence());
  }
  
  // Check for motion and show data if detected
  if (sths.isMotion()) {
    Serial.print(" MOTION: ");
    Serial.print(sths.readMotion());
  }
  
  // Check for temperature shock and show data if detected
  if (sths.isTempShock()) {
    Serial.print(" TEMP_SHOCK: ");
    Serial.print(sths.readTempShock());
  }
  
  // Show object temperatures only if presence or motion detected
  if (sths.isPresence() || sths.isMotion()) {
    Serial.print(" Obj: ");
    Serial.print(sths.readObjectTemperature());
    Serial.print(", Comp: ");
    Serial.print(sths.readCompensatedObjectTemperature());
  }
  
  Serial.println();
  delay(100);
}