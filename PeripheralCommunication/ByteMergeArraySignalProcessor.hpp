//
// Created by Ivan Kalesnikau on 03.08.2023.
//

#ifndef QPD_BYTEMERGEARRAYSIGNALPROCESSOR_HPP
#define QPD_BYTEMERGEARRAYSIGNALPROCESSOR_HPP

#include "ByteMergeSignalProcessor.hpp"

template <typename T, sizeType size, indexType ID = 0>
class ByteMergeArraySignalProcessor {
public:
    using InputType = array<uint8_t, sizeof(T) * size>;
    using OutputType = array<T, size>;

    struct Parameters {};

    static OutputType process(const InputType &data, const Parameters &parameters) {
        OutputType result;
        for (indexType i = 0; i < size; ++i) {
            array<uint8_t, sizeof(T)> tmpBytes;
            for (indexType j = 0; j < sizeof(T); ++j) {
                tmpBytes[j] = data[i * sizeof(T) + j];
            }
            result[i] = ByteMergeSignalProcessor<T>::process(tmpBytes, {});
        }
        return result;
    }
};

#endif  // QPD_BYTEMERGEARRAYSIGNALPROCESSOR_HPP
