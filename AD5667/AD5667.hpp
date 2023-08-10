//
// Created by Ivan Kalesnikau on 02.05.2023.
//

#ifndef MB_V2_AD5667_HPP
#define MB_V2_AD5667_HPP

#include <Utils/Types.hpp>
#include "i2c.h"
#include <GPIO.hpp>
#include <cstdio>
#include <etl/array.h>

class AD5667 {
public:
  constexpr static scalar step = 1. / 65535.;

  enum class CHANNEL : uint16_t { A = 1, B = 2, BOTH = 3 };

  enum class COMMAND : uint8_t {
    WRITE = 0,
    UPDATE = 1,
    WRITE_UPDATE_ALL = 2,
    WRITE_UPDATE = 3,
    POWER_TOGGLE = 4,
    RESET = 5,
    LDAC = 6,
    REFERENCE_TOGGLE = 7
  };

  enum class POWER_SETUP_MODE : uint16_t {
    NORMAL = 0,
    PULL_DOWN_1K = 1 << 4,
    PULL_DOWN_10K = 1 << 5,
    HIGH_IMPEDANCE = 3 << 4
  };

private:
  I2C_HandleTypeDef *hi2c_;
  GPIO CLR_GPIO_;
  GPIO LDAC_GPIO_;
  uint16_t address_;
  etl::array<uint8_t, 3> buffer3_{0, 0, 0};

public:
  AD5667(I2C_HandleTypeDef *hi2c, const GPIO &CLR_GPIO, const GPIO &LDAC_GPIO,
         const uint16_t address);

  void sendData(const COMMAND command, const CHANNEL whichDac,
                const uint16_t data);

  void sendSignal(const COMMAND command,const CHANNEL whichDac, const scalar signal);

  void clear();

  void setupPower(const CHANNEL channel, const POWER_SETUP_MODE powerSetupMode);

  void fullReset();

  inline GPIO &CLR_GPIO() { return CLR_GPIO_; }

  inline GPIO &LDAC_GPIO() { return LDAC_GPIO_; }

  void bufferDebugPrint();

  void clearBuffer3();

private:
  static uint8_t dacAddress(const CHANNEL channel);
};

#endif // MB_V2_AD5667_HPP
