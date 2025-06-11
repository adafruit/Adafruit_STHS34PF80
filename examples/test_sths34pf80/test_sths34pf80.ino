// Basic test for STHS34PF80 infrared sensor

#include "Adafruit_STHS34PF80.h"

Adafruit_STHS34PF80 sths;

void printLPFSetting(sths34pf80_lpf_config_t lpf_setting) {
  switch (lpf_setting) {
    case STHS34PF80_LPF_ODR_DIV_9:
      Serial.print("ODR/9");
      break;
    case STHS34PF80_LPF_ODR_DIV_20:
      Serial.print("ODR/20");
      break;
    case STHS34PF80_LPF_ODR_DIV_50:
      Serial.print("ODR/50");
      break;
    case STHS34PF80_LPF_ODR_DIV_100:
      Serial.print("ODR/100");
      break;
    case STHS34PF80_LPF_ODR_DIV_200:
      Serial.print("ODR/200");
      break;
    case STHS34PF80_LPF_ODR_DIV_400:
      Serial.print("ODR/400");
      break;
    case STHS34PF80_LPF_ODR_DIV_800:
      Serial.print("ODR/800");
      break;
    default:
      Serial.print("Unknown");
      break;
  }
}

void setup() {
  Serial.begin(115200);
  while (!Serial) delay(10);

  Serial.println("Adafruit STHS34PF80 test!");

  if (!sths.begin()) {
    Serial.println("Could not find a valid STHS34PF80 sensor, check wiring!");
    while (1) delay(10);
  }

  Serial.println("STHS34PF80 Found!");

  // Test all low-pass filter configurations
  Serial.println("\n--- Low-Pass Filter Tests ---");
  Serial.println("Available options: ODR/9, ODR/20, ODR/50, ODR/100, ODR/200, ODR/400, ODR/800");
  
  // Test Motion LPF
  Serial.println("\n1. Motion LPF:");
  if (sths.setMotionLowPassFilter(STHS34PF80_LPF_ODR_DIV_9)) {
    Serial.println("  Set to ODR/9 - Success");
  } else {
    Serial.println("  Set to ODR/9 - Failed");
  }
  Serial.print("  Current setting: ");
  printLPFSetting(sths.getMotionLowPassFilter());
  Serial.println();

  // Test Motion+Presence LPF
  Serial.println("\n2. Motion+Presence LPF:");
  if (sths.setMotionPresenceLowPassFilter(STHS34PF80_LPF_ODR_DIV_20)) {
    Serial.println("  Set to ODR/20 - Success");
  } else {
    Serial.println("  Set to ODR/20 - Failed");
  }
  Serial.print("  Current setting: ");
  printLPFSetting(sths.getMotionPresenceLowPassFilter());
  Serial.println();

  // Test Presence LPF
  Serial.println("\n3. Presence LPF:");
  if (sths.setPresenceLowPassFilter(STHS34PF80_LPF_ODR_DIV_50)) {
    Serial.println("  Set to ODR/50 - Success");
  } else {
    Serial.println("  Set to ODR/50 - Failed");
  }
  Serial.print("  Current setting: ");
  printLPFSetting(sths.getPresenceLowPassFilter());
  Serial.println();

  // Test Temperature LPF
  Serial.println("\n4. Temperature LPF:");
  if (sths.setTemperatureLowPassFilter(STHS34PF80_LPF_ODR_DIV_100)) {
    Serial.println("  Set to ODR/100 - Success");
  } else {
    Serial.println("  Set to ODR/100 - Failed");
  }
  Serial.print("  Current setting: ");
  printLPFSetting(sths.getTemperatureLowPassFilter());
  Serial.println();
}

void loop() {
  delay(1000);
}