//
// Created by Ivan Kalesnikau on 03.08.2023.
//

#ifndef QPD_BYTESPLITSIGNALPROCESSOR_HPP
#define QPD_BYTESPLITSIGNALPROCESSOR_HPP

#include <Utils/Types.hpp>

template<typename T, indexType ID = 0>
class ByteSplitSignalProcessor
{
public:
    using InputType = T;
    using OutputType = array<uint8_t, sizeof(T)>;

    union U
    {
        T val;
        uint8_t arr[sizeof(T)];
    };

    struct Parameters {
    };

    static OutputType process(const InputType &data, const Parameters &parameters)
    {
        U u{data};
        OutputType result;
        for (indexType i = 0; i < sizeof(T); ++i) {
            result[i] = u.arr[i];
        }
        return result;
    }
};

#endif  // QPD_BYTESPLITSIGNALPROCESSOR_HPP
