//
// Created by Ivan Kalesnikau on 05.07.2023.
//
#include "AD5667.hpp"

AD5667::AD5667(I2C_HandleTypeDef *hi2c, const GPIO &CLR_GPIO,
               const GPIO &LDAC_GPIO, const uint16_t address)
    : hi2c_(hi2c), CLR_GPIO_(CLR_GPIO), LDAC_GPIO_(LDAC_GPIO),
      address_(address) {
  CLR_GPIO_.on();
}

void AD5667::sendData(const COMMAND command, const CHANNEL channel,
                      const uint16_t data) {
  clearBuffer3();
  buffer3_[0] |= 0 << 7;                             // Reserved
  buffer3_[0] |= 0 << 6;                             // Byte operation
  buffer3_[0] |= static_cast<uint8_t>(command) << 3; // Command
  buffer3_[0] |= dacAddress(channel);                // DAC address
  buffer3_[1] = data >> 8;                           // MSD
  buffer3_[2] = data & 0x00FF;                       // LSD
  HAL_I2C_Master_Transmit(hi2c_, address_ << 1, buffer3_.data(), 3,
                          HAL_MAX_DELAY);
//  bufferDebugPrint();
}

void AD5667::sendSignal(const COMMAND command, const CHANNEL channel,
                        const scalar signal) {
  sendData(command, channel, signal / step);
}

uint8_t AD5667::dacAddress(const CHANNEL channel) {
  switch (channel) {
  case CHANNEL::A: {
    return 0;
  }
  case CHANNEL::B: {
    return 1;
  }
  case CHANNEL::BOTH: {
    return 7;
  }
  }
}
void AD5667::clear() {
  CLR_GPIO_.on();
  HAL_Delay(1);
  CLR_GPIO_.off();
}
void AD5667::setupPower(const CHANNEL channel,
                        const POWER_SETUP_MODE powerSetupMode) {
  sendData(COMMAND::POWER_TOGGLE, channel,
           static_cast<uint16_t>(powerSetupMode) |
               static_cast<uint16_t>(channel));
}

void AD5667::fullReset() { sendData(COMMAND::RESET, CHANNEL::BOTH, 0); }

void AD5667::bufferDebugPrint() {
  for (indexType i = 0; i < 3; ++i) {
    for (indexType j = 0; j < 8; ++j) {

      printf("%d", ((buffer3_[i] & (1 << (7 - j))) >> (7 - j)));
    }
    printf(" ");
  }
  printf("\n");
}

void AD5667::clearBuffer3() {
  for (indexType i = 0; i < 3; i++) {
    buffer3_[i] = 0;
  }
};