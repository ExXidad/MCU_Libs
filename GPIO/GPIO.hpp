//
// Created by Ivan Kalesnikau on 03.04.2023.
//

#ifndef MB_V2_GPIO_HPP
#define MB_V2_GPIO_HPP

#include "gpio.h"

struct GPIO {
  GPIO_TypeDef *gpioPort_;
  uint16_t gpioPin_;

  GPIO() = default;

  GPIO(GPIO_TypeDef *gpioPort, const uint16_t gpioPin)
      : gpioPort_(gpioPort), gpioPin_(gpioPin) {}

  inline void on() const {
    HAL_GPIO_WritePin(gpioPort_, gpioPin_, GPIO_PIN_SET);
  }

  inline void off() const {
    HAL_GPIO_WritePin(gpioPort_, gpioPin_, GPIO_PIN_RESET);
  }

  inline void toggle() const { HAL_GPIO_TogglePin(gpioPort_, gpioPin_); }

  GPIO_PinState inline read() const {
    return HAL_GPIO_ReadPin(gpioPort_, gpioPin_);
  }
};

inline bool operator==(const GPIO &gpio, const uint16_t exti) {
  return gpio.gpioPin_ == exti;
}
inline bool operator==(const uint16_t exti, const GPIO &gpio) {
  return gpio.gpioPin_ == exti;
}

#endif // MB_V2_GPIO_HPP
