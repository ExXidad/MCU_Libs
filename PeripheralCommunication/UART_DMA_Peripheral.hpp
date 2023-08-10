//
// Created by Ivan Kalesnikau on 03.08.2023.
//

#ifndef QPD_UART_DMA_PERIPHERAL_HPP
#define QPD_UART_DMA_PERIPHERAL_HPP

#include <Utils/Types.hpp>
#include <usart.h>
#include <dma.h>

class UART_DMA_Peripheral
{
public:
    UART_HandleTypeDef *huart_;

    UART_DMA_Peripheral() = default;
    UART_DMA_Peripheral(UART_HandleTypeDef *huart) : huart_(huart) {}

    template<sizeType size>
    void transmit(const array<uint8_t, size> &data)
    {
        HAL_UART_Transmit_DMA(huart_, const_cast<byte*>(data.data()), data.size());
    }

    template<sizeType size>
    void receive(array<uint8_t, size> &data)
    {
        HAL_UART_Receive_DMA(huart_, data.data(), data.size());
    }
};

[[nodiscard]] inline bool operator==(const UART_DMA_Peripheral &uartPeripheral, const UART_HandleTypeDef *huart)
{
    return uartPeripheral.huart_ == huart;
}

[[nodiscard]] inline bool operator==(const UART_HandleTypeDef *huart, const UART_DMA_Peripheral &uartPeripheral)
{
    return uartPeripheral.huart_ == huart;
}

#endif// QPD_UART_DMA_PERIPHERAL_HPP
