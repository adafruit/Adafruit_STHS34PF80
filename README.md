# Adafruit STHS34PF80 Library [![Build Status](https://github.com/adafruit/Adafruit_STHS34PF80/workflows/Arduino%20Library%20CI/badge.svg)](https://github.com/adafruit/Adafruit_STHS34PF80/actions)[![Documentation](https://github.com/adafruit/ci-arduino/blob/master/assets/doxygen_badge.svg)](http://adafruit.github.io/Adafruit_STHS34PF80/html/index.html)

<img src="assets/board.jpg?raw=true" width="500px">

This is the Adafruit STHS34PF80 infrared sensor library for Arduino.

Tested and works great with the Adafruit STHS34PF80 Breakout Board.
* https://www.adafruit.com/products/

This chip uses I2C to communicate, 2 pins are required to interface.

Adafruit invests time and resources providing this open source code, please support Adafruit and open-source hardware by purchasing products from Adafruit!

## About the STHS34PF80

The STHS34PF80 is an uncooled, factory-calibrated infrared motion and presence detection sensor. Key features include:

* **High Sensitivity**: 2000 LSB/°C IR sensitivity
* **Long Range**: Up to 4 meters detection without lens for 70x25cm objects  
* **Wide Field of View**: 80° field of view
* **Smart Algorithms**: Embedded presence, motion, and ambient temperature shock detection
* **Low Power**: 10 µA supply current at 1Hz ODR
* **Temperature Sensor**: Integrated ambient temperature sensor with ±0.3°C accuracy
* **Flexible ODR**: Programmable output data rates from 0.25 Hz to 30 Hz
* **Digital Interface**: I²C and 3-wire SPI interface
* **Operating Range**: 5 µm to 20 µm wavelength, -40°C to +85°C

## Installation

To install, use the Arduino Library Manager and search for "Adafruit STHS34PF80" and install the library.

## Dependencies
 * [Adafruit BusIO](https://github.com/adafruit/Adafruit_BusIO)

## Contributing

Contributions are welcome! Please read our [Code of Conduct](https://github.com/adafruit/Adafruit_STHS34PF80/blob/main/CODE_OF_CONDUCT.md)
before contributing to help this project stay welcoming.

## Documentation and doxygen
Documentation is produced by doxygen. Contributions should include documentation for any new features that they add.

Some examples of how to use the library are included in the examples/ folder.

## About this Driver
Written by Ladyada for Adafruit Industries.
MIT license, check license.txt for more information
All text above must be included in any redistribution