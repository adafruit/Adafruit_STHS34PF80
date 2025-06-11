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