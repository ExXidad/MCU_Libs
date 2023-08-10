//
// Created by Ivan Kalesnikau on 16.07.2023.
//

#ifndef QPD_TOVECSIGNALPROCESSOR_HPP
#define QPD_TOVECSIGNALPROCESSOR_HPP

#include <Utils/Types.hpp>

template<indexType ID = 0>
class ToVecSignalProcessor
{
public:
    using InputType = scalar;
    using OutputType = Vector2s;

    struct Parameters {
    };

    [[nodiscard]] static OutputType process(const InputType &data, Parameters &parameters)
    {
        return {data, data};
    }
};

#endif// QPD_TOVECSIGNALPROCESSOR_HPP
