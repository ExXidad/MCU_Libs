//
// Created by Ivan Kalesnikau on 16.07.2023.
//

#ifndef QPD_DOUBLESIGNALPROCESSOR_HPP
#define QPD_DOUBLESIGNALPROCESSOR_HPP

#include <Utils/Types.hpp>

template<typename T, indexType ID = 0>
class DoubleSignalProcessor
{
public:
    using InputType = T;
    using OutputType = T;

    struct Parameters {
    };

    [[nodiscard]] static OutputType process(const InputType &data, Parameters &parameters)
    {
        return data * 2;
    }
};

#endif// QPD_DOUBLESIGNALPROCESSOR_HPP
