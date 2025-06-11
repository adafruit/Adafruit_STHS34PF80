/*!
 * @file Adafruit_STHS34PF80.cpp
 *
 * @mainpage Adafruit STHS34PF80 infrared sensor library
 *
 * @section intro_sec Introduction
 *
 * This is a library for the STHS34PF80 infrared sensor
 *
 * Designed specifically to work with the Adafruit STHS34PF80 breakout:
 *   http://www.adafruit.com/products/
 *
 * These sensors use I2C to communicate, 2 pins are required to interface.
 *
 * Adafruit invests time and resources providing this open source code,
 * please support Adafruit and open-source hardware by purchasing
 * products from Adafruit!
 *
 * @section author Author
 *
 * Written by Ladyada for Adafruit Industries.
 *
 * @section license License
 *
 * MIT license, all text here must be included in any redistribution
 *
 */

#include "Adafruit_STHS34PF80.h"

/*!
 * @brief Instantiates a new STHS34PF80 class
 */
Adafruit_STHS34PF80::Adafruit_STHS34PF80() {}

/*!
 * @brief Cleans up the STHS34PF80
 */
Adafruit_STHS34PF80::~Adafruit_STHS34PF80() {
  if (i2c_dev) {
    delete i2c_dev;
  }
}

/*!
 * @brief Initializes the hardware and detects a valid STHS34PF80
 * @param i2c_addr I2C address to use
 * @param wire The Wire object to be used for I2C connections
 * @return True if initialization was successful, otherwise false
 */
bool Adafruit_STHS34PF80::begin(uint8_t i2c_addr, TwoWire *wire) {
  if (i2c_dev) {
    delete i2c_dev;
  }

  i2c_dev = new Adafruit_I2CDevice(i2c_addr, wire);

  if (!i2c_dev->begin()) {
    return false;
  }

  Adafruit_BusIO_Register chip_id = Adafruit_BusIO_Register(
      i2c_dev, STHS34PF80_REG_WHO_AM_I, 1);

  if (chip_id.read() != 0xD3) {
    return false;
  }

  return true;
}

/*!
 * @brief Set the motion detection low-pass filter configuration
 * @param config The LPF configuration value
 * @return True if successful, false otherwise
 */
bool Adafruit_STHS34PF80::setMotionLowPassFilter(sths34pf80_lpf_config_t config) {
  Adafruit_BusIO_Register lpf1_reg = Adafruit_BusIO_Register(
      i2c_dev, STHS34PF80_REG_LPF1, 1);
  
  Adafruit_BusIO_RegisterBits lpf_m_bits = Adafruit_BusIO_RegisterBits(
      &lpf1_reg, 3, 0);
  
  return lpf_m_bits.write(config);
}

/*!
 * @brief Get the motion detection low-pass filter configuration
 * @return The current LPF configuration value
 */
sths34pf80_lpf_config_t Adafruit_STHS34PF80::getMotionLowPassFilter() {
  Adafruit_BusIO_Register lpf1_reg = Adafruit_BusIO_Register(
      i2c_dev, STHS34PF80_REG_LPF1, 1);
  
  Adafruit_BusIO_RegisterBits lpf_m_bits = Adafruit_BusIO_RegisterBits(
      &lpf1_reg, 3, 0);
  
  return (sths34pf80_lpf_config_t)lpf_m_bits.read();
}

/*!
 * @brief Set the motion and presence detection low-pass filter configuration
 * @param config The LPF configuration value
 * @return True if successful, false otherwise
 */
bool Adafruit_STHS34PF80::setMotionPresenceLowPassFilter(sths34pf80_lpf_config_t config) {
  Adafruit_BusIO_Register lpf1_reg = Adafruit_BusIO_Register(
      i2c_dev, STHS34PF80_REG_LPF1, 1);
  
  Adafruit_BusIO_RegisterBits lpf_p_m_bits = Adafruit_BusIO_RegisterBits(
      &lpf1_reg, 3, 3);
  
  return lpf_p_m_bits.write(config);
}

/*!
 * @brief Get the motion and presence detection low-pass filter configuration
 * @return The current LPF configuration value
 */
sths34pf80_lpf_config_t Adafruit_STHS34PF80::getMotionPresenceLowPassFilter() {
  Adafruit_BusIO_Register lpf1_reg = Adafruit_BusIO_Register(
      i2c_dev, STHS34PF80_REG_LPF1, 1);
  
  Adafruit_BusIO_RegisterBits lpf_p_m_bits = Adafruit_BusIO_RegisterBits(
      &lpf1_reg, 3, 3);
  
  return (sths34pf80_lpf_config_t)lpf_p_m_bits.read();
}

/*!
 * @brief Set the presence detection low-pass filter configuration
 * @param config The LPF configuration value
 * @return True if successful, false otherwise
 */
bool Adafruit_STHS34PF80::setPresenceLowPassFilter(sths34pf80_lpf_config_t config) {
  Adafruit_BusIO_Register lpf2_reg = Adafruit_BusIO_Register(
      i2c_dev, STHS34PF80_REG_LPF2, 1);
  
  Adafruit_BusIO_RegisterBits lpf_p_bits = Adafruit_BusIO_RegisterBits(
      &lpf2_reg, 3, 3);
  
  return lpf_p_bits.write(config);
}

/*!
 * @brief Get the presence detection low-pass filter configuration
 * @return The current LPF configuration value
 */
sths34pf80_lpf_config_t Adafruit_STHS34PF80::getPresenceLowPassFilter() {
  Adafruit_BusIO_Register lpf2_reg = Adafruit_BusIO_Register(
      i2c_dev, STHS34PF80_REG_LPF2, 1);
  
  Adafruit_BusIO_RegisterBits lpf_p_bits = Adafruit_BusIO_RegisterBits(
      &lpf2_reg, 3, 3);
  
  return (sths34pf80_lpf_config_t)lpf_p_bits.read();
}

/*!
 * @brief Set the ambient temperature shock detection low-pass filter configuration
 * @param config The LPF configuration value
 * @return True if successful, false otherwise
 */
bool Adafruit_STHS34PF80::setTemperatureLowPassFilter(sths34pf80_lpf_config_t config) {
  Adafruit_BusIO_Register lpf2_reg = Adafruit_BusIO_Register(
      i2c_dev, STHS34PF80_REG_LPF2, 1);
  
  Adafruit_BusIO_RegisterBits lpf_a_t_bits = Adafruit_BusIO_RegisterBits(
      &lpf2_reg, 3, 0);
  
  return lpf_a_t_bits.write(config);
}

/*!
 * @brief Get the ambient temperature shock detection low-pass filter configuration
 * @return The current LPF configuration value
 */
sths34pf80_lpf_config_t Adafruit_STHS34PF80::getTemperatureLowPassFilter() {
  Adafruit_BusIO_Register lpf2_reg = Adafruit_BusIO_Register(
      i2c_dev, STHS34PF80_REG_LPF2, 1);
  
  Adafruit_BusIO_RegisterBits lpf_a_t_bits = Adafruit_BusIO_RegisterBits(
      &lpf2_reg, 3, 0);
  
  return (sths34pf80_lpf_config_t)lpf_a_t_bits.read();
}