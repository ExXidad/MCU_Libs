//
// Created by Ivan Kalesnikau on 03.08.2023.
//

#ifndef QPD_BYTEMERGESIGNALPROCESSOR_HPP
#define QPD_BYTEMERGESIGNALPROCESSOR_HPP

#include <Utils/Types.hpp>

template<typename T, indexType ID = 0>
class ByteMergeSignalProcessor
{
public:
    using InputType = array<uint8_t, sizeof(T)>;
    using OutputType = T;

    union U
    {
        uint8_t arr[sizeof(T)];
        T val;
    };

    struct Parameters {
    };

    static OutputType process(const InputType &data, const Parameters &parameters)
    {
        U u;
        for (indexType i = 0; i < sizeof(T); ++i) {
            u.arr[i] = data[i];
        }
        return u.val;
    }
};

#endif  // QPD_BYTEMERGESIGNALPROCESSOR_HPP
