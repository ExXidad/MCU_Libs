//
// Created by Ivan Kalesnikau on 09.08.2023.
//

#ifndef MEMS_ARRAYTOVECTORCONVERTSIGNALPROCESSOR_HPP
#define MEMS_ARRAYTOVECTORCONVERTSIGNALPROCESSOR_HPP

#include <Utils/Types.hpp>
#include <cstdio>

template <sizeType size, typename T, indexType ID = 0>
class ArrayToVectorConvertSignalProcessor {
public:
    using InputType = array<T, size>;
    using OutputType = Eigen::Vector<T, size>;

    struct Parameters {};

    static OutputType process(const InputType &data, const Parameters &parameters) {
        OutputType result;
        for (indexType i = 0; i < size; ++i) {
            result(i) = data[i];
        }
        return result;
    }
};

#endif  // MEMS_ARRAYTOVECTORCONVERTSIGNALPROCESSOR_HPP
