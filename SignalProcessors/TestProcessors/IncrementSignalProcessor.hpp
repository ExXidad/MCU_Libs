//
// Created by Ivan Kalesnikau on 16.07.2023.
//

#ifndef QPD_INCREMENTSIGNALPROCESSOR_HPP
#define QPD_INCREMENTSIGNALPROCESSOR_HPP

#include <Utils/Types.hpp>

template<typename T, indexType ID = 0>
class IncrementSignalProcessor
{
public:
    using InputType = T;
    using OutputType = T;

    struct Parameters {
    };

    [[nodiscard]] static OutputType process(const InputType &data, Parameters &parameters)
    {
        return data + 1;
    }
};

#endif// QPD_INCREMENTSIGNALPROCESSOR_HPP
