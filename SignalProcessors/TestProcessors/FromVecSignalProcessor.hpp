//
// Created by Ivan Kalesnikau on 16.07.2023.
//

#ifndef QPD_FROMVECSIGNALPROCESSOR_HPP
#define QPD_FROMVECSIGNALPROCESSOR_HPP

#include <Utils/Types.hpp>

template<indexType ID = 0>
class FromVecSignalProcessor
{
public:
    using InputType = Vector2s;
    using OutputType = scalar;

    struct Parameters {
    };

    [[nodiscard]] static OutputType process(const InputType &data, Parameters &parameters)
    {
        return data(0) + data(1);
    }
};

#endif// QPD_FROMVECSIGNALPROCESSOR_HPP
