/*!
 * @file Adafruit_STHS34PF80.h
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
 * Written by Ladyada for Adafruit Industries.
 *
 * MIT license, all text here must be included in any redistribution.
 *
 */

#ifndef __ADAFRUIT_STHS34PF80_H__
#define __ADAFRUIT_STHS34PF80_H__

#include "Arduino.h"
#include <Adafruit_BusIO_Register.h>
#include <Adafruit_I2CDevice.h>
#include <Wire.h>

#define STHS34PF80_DEFAULT_ADDR 0x5A ///< Default I2C address for the STHS34PF80

#define STHS34PF80_REG_LPF1 0x0C ///< Low-pass filter configuration 1 register
#define STHS34PF80_REG_LPF2 0x0D ///< Low-pass filter configuration 2 register
#define STHS34PF80_REG_WHO_AM_I 0x0F ///< Device identification register
#define STHS34PF80_REG_AVG_TRIM 0x10 ///< Averaging configuration register
#define STHS34PF80_REG_CTRL0 0x17 ///< Control register 0 (gain mode)
#define STHS34PF80_REG_SENS_DATA 0x1D ///< Sensitivity data register
#define STHS34PF80_REG_CTRL1 0x20 ///< Control register 1 (ODR configuration)
#define STHS34PF80_REG_CTRL2 0x21 ///< Control register 2 (boot, function access, one-shot)
#define STHS34PF80_REG_CTRL3 0x22 ///< Control register 3 (interrupt configuration)
#define STHS34PF80_REG_STATUS 0x23 ///< Status register
#define STHS34PF80_REG_FUNC_STATUS 0x25 ///< Function status register
#define STHS34PF80_REG_TOBJECT_L 0x26 ///< Object temperature LSB register
#define STHS34PF80_REG_TOBJECT_H 0x27 ///< Object temperature MSB register
#define STHS34PF80_REG_TAMBIENT_L 0x28 ///< Ambient temperature LSB register
#define STHS34PF80_REG_TAMBIENT_H 0x29 ///< Ambient temperature MSB register
#define STHS34PF80_REG_TOBJ_COMP_L 0x38 ///< Compensated object temperature LSB register
#define STHS34PF80_REG_TOBJ_COMP_H 0x39 ///< Compensated object temperature MSB register
#define STHS34PF80_REG_TPRESENCE_L 0x3A ///< Presence detection LSB register
#define STHS34PF80_REG_TPRESENCE_H 0x3B ///< Presence detection MSB register
#define STHS34PF80_REG_TMOTION_L 0x3C ///< Motion detection LSB register
#define STHS34PF80_REG_TMOTION_H 0x3D ///< Motion detection MSB register
#define STHS34PF80_REG_TAMB_SHOCK_L 0x3E ///< Ambient shock detection LSB register
#define STHS34PF80_REG_TAMB_SHOCK_H 0x3F ///< Ambient shock detection MSB register

/*!
 * @brief Class that stores state and functions for interacting with the STHS34PF80
 */
class Adafruit_STHS34PF80 {
public:
  Adafruit_STHS34PF80();
  ~Adafruit_STHS34PF80();

  bool begin(uint8_t i2c_addr = STHS34PF80_DEFAULT_ADDR, TwoWire *wire = &Wire);

private:
  Adafruit_I2CDevice *i2c_dev;
};

#endif