//
// Created by Ivan Kalesnikau on 03.08.2023.
//

#ifndef QPD_BYTESPLITARRAYSIGNALPROCESSOR_HPP
#define QPD_BYTESPLITARRAYSIGNALPROCESSOR_HPP

#include "ByteSplitSignalProcessor.hpp"

template <typename T, sizeType size, indexType ID = 0>
class ByteSplitArraySignalProcessor {
public:
    using InputType = array<T, size>;
    using OutputType = array<byte, sizeof(T) * size>;

    struct Parameters {};

    static OutputType process(const InputType &data, const Parameters &parameters) {
        OutputType result;
        for (indexType i = 0; i < size; ++i) {
            array<uint8_t, sizeof(T)> tmpBytes = ByteSplitSignalProcessor<T>::process(data[i], {});
            for (indexType j = 0; j < sizeof(T); ++j) {
                result[i * sizeof(T) + j] = tmpBytes[j];
            }
        }
        return result;
    }
};

#endif  // QPD_BYTESPLITARRAYSIGNALPROCESSOR_HPP
