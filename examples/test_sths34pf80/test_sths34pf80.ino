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

  // Test Ambient Temperature Averaging (default: 8 samples)
  Serial.println(F("\nAmbient Temperature Averaging:"));
  if (sths.setAmbTempAveraging(STHS34PF80_AVG_T_8)) {
    Serial.println(F("  Success"));
  } else {
    Serial.println(F("  Failed"));
  }
  Serial.print(F("  Current: "));
  switch (sths.getAmbTempAveraging()) {
    case STHS34PF80_AVG_T_8: Serial.println(F("8 samples")); break;
    case STHS34PF80_AVG_T_4: Serial.println(F("4 samples")); break;
    case STHS34PF80_AVG_T_2: Serial.println(F("2 samples")); break;
    case STHS34PF80_AVG_T_1: Serial.println(F("1 sample")); break;
    default: Serial.println(F("Unknown")); break;
  }

  // Test Object Temperature Averaging (default: 32 samples)
  Serial.println(F("\nObject Temperature Averaging:"));
  if (sths.setObjAveraging(STHS34PF80_AVG_TMOS_32)) {
    Serial.println(F("  Success"));
  } else {
    Serial.println(F("  Failed"));
  }
  Serial.print(F("  Current: "));
  switch (sths.getObjAveraging()) {
    case STHS34PF80_AVG_TMOS_2: Serial.println(F("2 samples")); break;
    case STHS34PF80_AVG_TMOS_8: Serial.println(F("8 samples")); break;
    case STHS34PF80_AVG_TMOS_32: Serial.println(F("32 samples")); break;
    case STHS34PF80_AVG_TMOS_128: Serial.println(F("128 samples")); break;
    case STHS34PF80_AVG_TMOS_256: Serial.println(F("256 samples")); break;
    case STHS34PF80_AVG_TMOS_512: Serial.println(F("512 samples")); break;
    case STHS34PF80_AVG_TMOS_1024: Serial.println(F("1024 samples")); break;
    case STHS34PF80_AVG_TMOS_2048: Serial.println(F("2048 samples")); break;
    default: Serial.println(F("Unknown")); break;
  }

  // Test Wide Gain Mode (default: false - default gain mode)
  Serial.println(F("\nWide Gain Mode:"));
  if (sths.setWideGainMode(false)) {
    Serial.println(F("  Success"));
  } else {
    Serial.println(F("  Failed"));
  }
  Serial.print(F("  Current: "));
  if (sths.getWideGainMode()) {
    Serial.println(F("Wide mode"));
  } else {
    Serial.println(F("Default gain mode"));
  }

  // Test Sensitivity (factory calibrated - read only)
  Serial.println(F("\nSensitivity:"));
  // sths.setSensitivity(0); // Commented out - factory calibrated value
  Serial.print(F("  Current: "));
  Serial.println(sths.getSensitivity());

  // Test Block Data Update (default: true)
  Serial.println(F("\nBlock Data Update:"));
  if (sths.setBlockDataUpdate(true)) {
    Serial.println(F("  Success"));
  } else {
    Serial.println(F("  Failed"));
  }
  Serial.print(F("  Current: "));
  if (sths.getBlockDataUpdate()) {
    Serial.println(F("Enabled"));
  } else {
    Serial.println(F("Disabled"));
  }

  // Set Output Data Rate to continuous mode (1 Hz)
  Serial.println(F("\nOutput Data Rate:"));
  if (sths.setOutputDataRate(STHS34PF80_ODR_1_HZ)) {
    Serial.println(F("  Success"));
  } else {
    Serial.println(F("  Failed"));
  }
  Serial.print(F("  Current: "));
  switch (sths.getOutputDataRate()) {
    case STHS34PF80_ODR_POWER_DOWN: Serial.println(F("Power-down")); break;
    case STHS34PF80_ODR_0_25_HZ: Serial.println(F("0.25 Hz")); break;
    case STHS34PF80_ODR_0_5_HZ: Serial.println(F("0.5 Hz")); break;
    case STHS34PF80_ODR_1_HZ: Serial.println(F("1 Hz")); break;
    case STHS34PF80_ODR_2_HZ: Serial.println(F("2 Hz")); break;
    case STHS34PF80_ODR_4_HZ: Serial.println(F("4 Hz")); break;
    case STHS34PF80_ODR_8_HZ: Serial.println(F("8 Hz")); break;
    case STHS34PF80_ODR_15_HZ: Serial.println(F("15 Hz")); break;
    case STHS34PF80_ODR_30_HZ: Serial.println(F("30 Hz")); break;
    default: Serial.println(F("Unknown")); break;
  }

  // Test CTRL2 functions (actions only, no getters for these)
  Serial.println(F("\nEmbedded Function Page:"));
  if (sths.enableEmbeddedFuncPage(false)) {
    Serial.println(F("  Success"));
  } else {
    Serial.println(F("  Failed"));
  }

  // Only trigger one-shot if in power-down mode
  if (sths.getOutputDataRate() == STHS34PF80_ODR_POWER_DOWN) {
    Serial.println(F("\nTrigger One-shot:"));
    if (sths.triggerOneshot()) {
      Serial.println(F("  Success"));
    } else {
      Serial.println(F("  Failed"));
    }
  } else {
    Serial.println(F("\nContinuous mode - no one-shot trigger needed"));
  }

  Serial.println(F("\nReboot OTP Memory:"));
  if (sths.rebootOTPmemory()) {
    Serial.println(F("  Success"));
  } else {
    Serial.println(F("  Failed"));
  }

  // Configure interrupts: latched, push-pull, active high, all events
  Serial.println(F("\nInterrupt Configuration:"));
  sths.setIntPolarity(false);  // active high
  sths.setIntOpenDrain(false); // push-pull
  sths.setIntLatched(true);    // latched mode
  
  // Enable interrupts for all three events
  uint8_t mask = STHS34PF80_PRES_FLAG | STHS34PF80_MOT_FLAG | STHS34PF80_TAMB_SHOCK_FLAG;
  sths.setIntMask(mask);
  
  // Set interrupt signal to INT_OR (function flags)
  sths.setIntSignal(STHS34PF80_INT_OR);

  // Print current interrupt mask status
  Serial.print(F("  Current interrupt mask: 0x"));
  Serial.print(sths.getIntMask(), HEX);
  Serial.print(F(" ("));
  uint8_t currentMask = sths.getIntMask();
  if (currentMask & STHS34PF80_PRES_FLAG) Serial.print(F("PRES "));
  if (currentMask & STHS34PF80_MOT_FLAG) Serial.print(F("MOT "));
  if (currentMask & STHS34PF80_TAMB_SHOCK_FLAG) Serial.print(F("TAMB_SHOCK "));
  Serial.println(F(")"));

  // Print current interrupt signal setting
  Serial.print(F("  Current interrupt signal: "));
  switch (sths.getIntSignal()) {
    case STHS34PF80_INT_HIGH_Z:
      Serial.println(F("High-Z (disabled)"));
      break;
    case STHS34PF80_INT_DRDY:
      Serial.println(F("Data ready"));
      break;
    case STHS34PF80_INT_OR:
      Serial.println(F("INT_OR (function flags)"));
      break;
    default:
      Serial.println(F("Unknown"));
      break;
  }
}

void loop() {
  if (sths.isDataReady()) {
    Serial.print("Data ready! ");
    
    // Check function status flags
    if (sths.isPresence()) {
      Serial.print("PRESENCE ");
    }
    if (sths.isMotion()) {
      Serial.print("MOTION ");
    }
    if (sths.isTempShock()) {
      Serial.print("TEMP_SHOCK ");
    }
    
    // Read temperature and detection data
    Serial.print("Amb: ");
    Serial.print(sths.readAmbientTemperature(), 2);
    Serial.print("°C, Obj: ");
    Serial.print(sths.readObjectTemperature());
    Serial.print(", Comp: ");
    Serial.print(sths.readCompensatedObjectTemperature());
    Serial.print(", Pres: ");
    Serial.print(sths.readPresence());
    Serial.print(", Mot: ");
    Serial.print(sths.readMotion());
    Serial.print(", Shock: ");
    Serial.print(sths.readTempShock());
    Serial.println();
  }
  delay(100);
}