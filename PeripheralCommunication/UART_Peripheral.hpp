//
// Created by Ivan Kalesnikau on 03.08.2023.
//

#ifndef QPD_UART_PERIPHERAL_HPP
#define QPD_UART_PERIPHERAL_HPP

#include <Utils/Types.hpp>
#include <usart.h>

class UART_Peripheral {
public:
    UART_HandleTypeDef *huart_;

    UART_Peripheral()=default;
    UART_Peripheral(UART_HandleTypeDef *huart) : huart_(huart) {}

    template <sizeType size>
    void transmit(const array<uint8_t, size> &data) {
        HAL_UART_Transmit(huart_, const_cast<byte*>(data.data()), data.size(),HAL_MAX_DELAY);
    }

    template <sizeType size>
    void receive(array<uint8_t, size> &data) {
        HAL_UART_Receive(huart_, data.data(), data.size(),HAL_MAX_DELAY);
    }
};

[[nodiscard]] inline bool operator==(const UART_Peripheral &uartPeripheral, const UART_HandleTypeDef *huart) {
    return uartPeripheral.huart_ == huart;
}

[[nodiscard]] inline bool operator==(const UART_HandleTypeDef *huart, const UART_Peripheral &uartPeripheral) {
    return uartPeripheral.huart_ == huart;
}


template <sizeType size>
class UART_Peripheral_ {
public:
    UART_HandleTypeDef *huart_;
    array<uint8_t, size> buffer_;

    UART_Peripheral_()=default;
    UART_Peripheral_(UART_HandleTypeDef *huart) : huart_(huart) {}

    void transmit() {
        HAL_UART_Transmit(huart_, buffer_.data(), buffer_.size(),HAL_MAX_DELAY);
    }


    void receive() {
        HAL_UART_Receive(huart_, buffer_.data(), buffer_.size(),HAL_MAX_DELAY);
    }
};

#endif  // QPD_UART_PERIPHERAL_HPP
