//
// Created by Ivan Kalesnikau on 04.08.2023.
//

#ifndef QPD_SPI_PERIPHERAL_HPP
#define QPD_SPI_PERIPHERAL_HPP

#include <spi.h>
#include <Utils/Types.hpp>

class SPI_Peripheral {
public:
    SPI_HandleTypeDef *hspi_;

    SPI_Peripheral() = default;
    SPI_Peripheral(SPI_HandleTypeDef *hspi) : hspi_(hspi) {}

    template <sizeType size>
    void transmit(const array<byte, size> &data) {
        HAL_SPI_Transmit(hspi_, const_cast<byte*>(data.data()), data.size(), HAL_MAX_DELAY);
    }

    template <sizeType size>
    void receive(array<byte, size> &data) {
        HAL_SPI_Receive(hspi_, data.data(), data.size(), HAL_MAX_DELAY);
    }
};

[[nodiscard]] inline bool operator==(const SPI_Peripheral &spiPeripheral, const SPI_HandleTypeDef *hspi) {
    return spiPeripheral.hspi_ == hspi;
}

[[nodiscard]] inline bool operator==(const SPI_HandleTypeDef *hspi, const SPI_Peripheral &spiPeripheral) {
    return spiPeripheral.hspi_ == hspi;
}

#endif  // QPD_SPI_PERIPHERAL_HPP
