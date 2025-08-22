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

/*!
 * @brief Set ambient temperature averaging configuration
 * @param config The averaging configuration value
 * @return True if successful, false otherwise
 */
bool Adafruit_STHS34PF80::setAmbTempAveraging(sths34pf80_avg_t_t config) {
  Adafruit_BusIO_Register avg_trim_reg = Adafruit_BusIO_Register(
      i2c_dev, STHS34PF80_REG_AVG_TRIM, 1);
  
  Adafruit_BusIO_RegisterBits avg_t_bits = Adafruit_BusIO_RegisterBits(
      &avg_trim_reg, 2, 4);
  
  return avg_t_bits.write(config);
}

/*!
 * @brief Get ambient temperature averaging configuration
 * @return The current averaging configuration value
 */
sths34pf80_avg_t_t Adafruit_STHS34PF80::getAmbTempAveraging() {
  Adafruit_BusIO_Register avg_trim_reg = Adafruit_BusIO_Register(
      i2c_dev, STHS34PF80_REG_AVG_TRIM, 1);
  
  Adafruit_BusIO_RegisterBits avg_t_bits = Adafruit_BusIO_RegisterBits(
      &avg_trim_reg, 2, 4);
  
  return (sths34pf80_avg_t_t)avg_t_bits.read();
}

/*!
 * @brief Set object temperature averaging configuration
 * @param config The averaging configuration value
 * @return True if successful, false otherwise
 */
bool Adafruit_STHS34PF80::setObjAveraging(sths34pf80_avg_tmos_t config) {
  Adafruit_BusIO_Register avg_trim_reg = Adafruit_BusIO_Register(
      i2c_dev, STHS34PF80_REG_AVG_TRIM, 1);
  
  Adafruit_BusIO_RegisterBits avg_tmos_bits = Adafruit_BusIO_RegisterBits(
      &avg_trim_reg, 3, 0);
  
  return avg_tmos_bits.write(config);
}

/*!
 * @brief Get object temperature averaging configuration
 * @return The current averaging configuration value
 */
sths34pf80_avg_tmos_t Adafruit_STHS34PF80::getObjAveraging() {
  Adafruit_BusIO_Register avg_trim_reg = Adafruit_BusIO_Register(
      i2c_dev, STHS34PF80_REG_AVG_TRIM, 1);
  
  Adafruit_BusIO_RegisterBits avg_tmos_bits = Adafruit_BusIO_RegisterBits(
      &avg_trim_reg, 3, 0);
  
  return (sths34pf80_avg_tmos_t)avg_tmos_bits.read();
}

/*!
 * @brief Set wide gain mode configuration
 * @param wide_mode True for wide mode, false for default gain mode
 * @return True if successful, false otherwise
 */
bool Adafruit_STHS34PF80::setWideGainMode(bool wide_mode) {
  Adafruit_BusIO_Register ctrl0_reg = Adafruit_BusIO_Register(
      i2c_dev, STHS34PF80_REG_CTRL0, 1);
  
  Adafruit_BusIO_RegisterBits gain_bits = Adafruit_BusIO_RegisterBits(
      &ctrl0_reg, 3, 4);
  
  return gain_bits.write(wide_mode ? 0x00 : 0x07);
}

/*!
 * @brief Get wide gain mode configuration
 * @return True if in wide mode, false if in default gain mode
 */
bool Adafruit_STHS34PF80::getWideGainMode() {
  Adafruit_BusIO_Register ctrl0_reg = Adafruit_BusIO_Register(
      i2c_dev, STHS34PF80_REG_CTRL0, 1);
  
  Adafruit_BusIO_RegisterBits gain_bits = Adafruit_BusIO_RegisterBits(
      &ctrl0_reg, 3, 4);
  
  return gain_bits.read() == 0x00;
}

/*!
 * @brief Set sensitivity value for ambient temperature compensation
 * @param sensitivity Signed 8-bit sensitivity value (two's complement)
 * @return True if successful, false otherwise
 */
bool Adafruit_STHS34PF80::setSensitivity(int8_t sensitivity) {
  Adafruit_BusIO_Register sens_data_reg = Adafruit_BusIO_Register(
      i2c_dev, STHS34PF80_REG_SENS_DATA, 1);
  
  return sens_data_reg.write((uint8_t)sensitivity);
}

/*!
 * @brief Get sensitivity value for ambient temperature compensation
 * @return Signed 8-bit sensitivity value (two's complement)
 */
int8_t Adafruit_STHS34PF80::getSensitivity() {
  Adafruit_BusIO_Register sens_data_reg = Adafruit_BusIO_Register(
      i2c_dev, STHS34PF80_REG_SENS_DATA, 1);
  
  return (int8_t)sens_data_reg.read();
}

/*!
 * @brief Set block data update configuration
 * @param enable True to enable block data update, false to disable
 * @return True if successful, false otherwise
 */
bool Adafruit_STHS34PF80::setBlockDataUpdate(bool enable) {
  Adafruit_BusIO_Register ctrl1_reg = Adafruit_BusIO_Register(
      i2c_dev, STHS34PF80_REG_CTRL1, 1);
  
  Adafruit_BusIO_RegisterBits bdu_bit = Adafruit_BusIO_RegisterBits(
      &ctrl1_reg, 1, 4);
  
  return bdu_bit.write(enable ? 1 : 0);
}

/*!
 * @brief Get block data update configuration
 * @return True if block data update is enabled, false if disabled
 */
bool Adafruit_STHS34PF80::getBlockDataUpdate() {
  Adafruit_BusIO_Register ctrl1_reg = Adafruit_BusIO_Register(
      i2c_dev, STHS34PF80_REG_CTRL1, 1);
  
  Adafruit_BusIO_RegisterBits bdu_bit = Adafruit_BusIO_RegisterBits(
      &ctrl1_reg, 1, 4);
  
  return bdu_bit.read() == 1;
}

/*!
 * @brief Set output data rate configuration
 * @param odr The output data rate value
 * @return True if successful, false otherwise
 */
bool Adafruit_STHS34PF80::setOutputDataRate(sths34pf80_odr_t odr) {
  Adafruit_BusIO_Register ctrl1_reg = Adafruit_BusIO_Register(
      i2c_dev, STHS34PF80_REG_CTRL1, 1);
  
  Adafruit_BusIO_RegisterBits odr_bits = Adafruit_BusIO_RegisterBits(
      &ctrl1_reg, 4, 0);
  
  return odr_bits.write(odr);
}

/*!
 * @brief Get output data rate configuration
 * @return The current output data rate value
 */
sths34pf80_odr_t Adafruit_STHS34PF80::getOutputDataRate() {
  Adafruit_BusIO_Register ctrl1_reg = Adafruit_BusIO_Register(
      i2c_dev, STHS34PF80_REG_CTRL1, 1);
  
  Adafruit_BusIO_RegisterBits odr_bits = Adafruit_BusIO_RegisterBits(
      &ctrl1_reg, 4, 0);
  
  return (sths34pf80_odr_t)odr_bits.read();
}

/*!
 * @brief Reboot OTP memory
 * @return True if successful, false otherwise
 */
bool Adafruit_STHS34PF80::rebootOTPmemory() {
  Adafruit_BusIO_Register ctrl2_reg = Adafruit_BusIO_Register(
      i2c_dev, STHS34PF80_REG_CTRL2, 1);
  
  Adafruit_BusIO_RegisterBits boot_bit = Adafruit_BusIO_RegisterBits(
      &ctrl2_reg, 1, 7);
  
  return boot_bit.write(1);
}

/*!
 * @brief Enable or disable embedded function page access
 * @param enable True to enable embedded function page, false to disable
 * @return True if successful, false otherwise
 */
bool Adafruit_STHS34PF80::enableEmbeddedFuncPage(bool enable) {
  Adafruit_BusIO_Register ctrl2_reg = Adafruit_BusIO_Register(
      i2c_dev, STHS34PF80_REG_CTRL2, 1);
  
  Adafruit_BusIO_RegisterBits func_cfg_access_bit = Adafruit_BusIO_RegisterBits(
      &ctrl2_reg, 1, 4);
  
  return func_cfg_access_bit.write(enable ? 1 : 0);
}

/*!
 * @brief Trigger one-shot measurement
 * @return True if successful, false otherwise
 */
bool Adafruit_STHS34PF80::triggerOneshot() {
  Adafruit_BusIO_Register ctrl2_reg = Adafruit_BusIO_Register(
      i2c_dev, STHS34PF80_REG_CTRL2, 1);
  
  Adafruit_BusIO_RegisterBits oneshot_bit = Adafruit_BusIO_RegisterBits(
      &ctrl2_reg, 1, 0);
  
  return oneshot_bit.write(1);
}

/*!
 * @brief Set interrupt polarity
 * @param active_low True for active low (default), false for active high
 * @return True if successful, false otherwise
 */
bool Adafruit_STHS34PF80::setIntPolarity(bool active_low) {
  Adafruit_BusIO_Register ctrl3_reg = Adafruit_BusIO_Register(
      i2c_dev, STHS34PF80_REG_CTRL3, 1);
  
  Adafruit_BusIO_RegisterBits int_h_l_bit = Adafruit_BusIO_RegisterBits(
      &ctrl3_reg, 1, 7);
  
  return int_h_l_bit.write(active_low ? 1 : 0);
}

/*!
 * @brief Set interrupt output type
 * @param open_drain True for open drain, false for push-pull (default)
 * @return True if successful, false otherwise
 */
bool Adafruit_STHS34PF80::setIntOpenDrain(bool open_drain) {
  Adafruit_BusIO_Register ctrl3_reg = Adafruit_BusIO_Register(
      i2c_dev, STHS34PF80_REG_CTRL3, 1);
  
  Adafruit_BusIO_RegisterBits pp_od_bit = Adafruit_BusIO_RegisterBits(
      &ctrl3_reg, 1, 6);
  
  return pp_od_bit.write(open_drain ? 1 : 0);
}

/*!
 * @brief Set interrupt latched mode
 * @param latched True for latched mode, false for pulsed mode (default)
 * @return True if successful, false otherwise
 */
bool Adafruit_STHS34PF80::setIntLatched(bool latched) {
  Adafruit_BusIO_Register ctrl3_reg = Adafruit_BusIO_Register(
      i2c_dev, STHS34PF80_REG_CTRL3, 1);
  
  Adafruit_BusIO_RegisterBits int_latched_bit = Adafruit_BusIO_RegisterBits(
      &ctrl3_reg, 1, 2);
  
  return int_latched_bit.write(latched ? 1 : 0);
}

/*!
 * @brief Set interrupt mask for function status flags
 * @param mask Interrupt mask (bits 2:0 for PRES_FLAG, MOT_FLAG, TAMB_SHOCK_FLAG)
 * @return True if successful, false otherwise
 */
bool Adafruit_STHS34PF80::setIntMask(uint8_t mask) {
  Adafruit_BusIO_Register ctrl3_reg = Adafruit_BusIO_Register(
      i2c_dev, STHS34PF80_REG_CTRL3, 1);
  
  Adafruit_BusIO_RegisterBits int_mask_bits = Adafruit_BusIO_RegisterBits(
      &ctrl3_reg, 3, 3);
  
  return int_mask_bits.write(mask & 0x07);
}

/*!
 * @brief Get interrupt mask for function status flags
 * @return Current interrupt mask value (bits 2:0 for PRES_FLAG, MOT_FLAG, TAMB_SHOCK_FLAG)
 */
uint8_t Adafruit_STHS34PF80::getIntMask() {
  Adafruit_BusIO_Register ctrl3_reg = Adafruit_BusIO_Register(
      i2c_dev, STHS34PF80_REG_CTRL3, 1);
  
  Adafruit_BusIO_RegisterBits int_mask_bits = Adafruit_BusIO_RegisterBits(
      &ctrl3_reg, 3, 3);
  
  return int_mask_bits.read();
}

/*!
 * @brief Set interrupt signal type
 * @param signal Interrupt signal type (HIGH_Z, DRDY, or INT_OR)
 * @return True if successful, false otherwise
 */
bool Adafruit_STHS34PF80::setIntSignal(sths34pf80_int_signal_t signal) {
  Adafruit_BusIO_Register ctrl3_reg = Adafruit_BusIO_Register(
      i2c_dev, STHS34PF80_REG_CTRL3, 1);
  
  Adafruit_BusIO_RegisterBits ien_bits = Adafruit_BusIO_RegisterBits(
      &ctrl3_reg, 2, 0);
  
  return ien_bits.write(signal);
}

/*!
 * @brief Get interrupt signal type
 * @return Current interrupt signal type
 */
sths34pf80_int_signal_t Adafruit_STHS34PF80::getIntSignal() {
  Adafruit_BusIO_Register ctrl3_reg = Adafruit_BusIO_Register(
      i2c_dev, STHS34PF80_REG_CTRL3, 1);
  
  Adafruit_BusIO_RegisterBits ien_bits = Adafruit_BusIO_RegisterBits(
      &ctrl3_reg, 2, 0);
  
  return (sths34pf80_int_signal_t)ien_bits.read();
}