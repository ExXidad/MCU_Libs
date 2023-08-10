//
// Created by Ivan Kalesnikau on 04.08.2023.
//

#ifndef QPD_PERIPHERALSENDSIGNALPROCESSOR_HPP
#define QPD_PERIPHERALSENDSIGNALPROCESSOR_HPP

#include <Utils/Types.hpp>

template<typename PeripheralType,sizeType arraySize, indexType ID = 0>
class PeripheralSendSignalProcessor {
public:
    using InputType = array<byte, arraySize>;
    using OutputType = void;

    struct Parameters {
        PeripheralType *peripheral;
    };

    static OutputType process(const InputType &data, const Parameters &parameters) {
        parameters.peripheral->template transmit<arraySize>(data);
    }
};

#endif  // QPD_PERIPHERALSENDSIGNALPROCESSOR_HPP
