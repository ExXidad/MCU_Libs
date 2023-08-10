//
// Created by Ivan Kalesnikau on 04.08.2023.
//

#ifndef QPD_SPI_DMA_PERIPHERAL_HPP
#define QPD_SPI_DMA_PERIPHERAL_HPP

#include <Utils/Types.hpp>
#include <spi.h>
#include <dma.h>

class SPI_DMA_Peripheral {
public:
    SPI_HandleTypeDef *hspi_;

    SPI_DMA_Peripheral() = default;
    SPI_DMA_Peripheral(SPI_HandleTypeDef *hspi) : hspi_(hspi) {}

    template <sizeType size>
    void transmit(const array<uint8_t, size> &data) {
        HAL_SPI_Transmit_DMA(hspi_, const_cast<byte*>(data.data()), data.size());
    }

    template <sizeType size>
    void receive(array<uint8_t, size> &data) {
        HAL_SPI_Receive_DMA(hspi_, data.data(), data.size());
    }
};

[[nodiscard]] inline bool operator==(const SPI_DMA_Peripheral &spiPeripheral, const SPI_HandleTypeDef *hspi) {
    return spiPeripheral.hspi_ == hspi;
}

[[nodiscard]] inline bool operator==(const SPI_HandleTypeDef *hspi, const SPI_DMA_Peripheral &spiPeripheral) {
    return spiPeripheral.hspi_ == hspi;
}

#endif  // QPD_SPI_DMA_PERIPHERAL_HPP
