//
// Created by Ivan Kalesnikau on 17.07.2023.
//

#ifndef QPD_VECTORTOARRAYCONVERTER_HPP
#define QPD_VECTORTOARRAYCONVERTER_HPP

#include <Utils/Types.hpp>
#include <cstdio>

template <sizeType size, typename T, indexType ID = 0>
class VectorToArrayConvertSignalProcessor {
public:
    using InputType = Eigen::Vector<T, size>;
    using OutputType = array<T, size>;

    struct Parameters {};

    static OutputType process(const InputType &data, const Parameters &parameters) {
        OutputType result;
        for (indexType i = 0; i < size; ++i) {
            result[i] = data(i);
        }
        return result;
    }
};

#endif  // QPD_VECTORTOARRAYCONVERTER_HPP
