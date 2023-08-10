//
// Created by Ivan Kalesnikau on 16.07.2023.
//

#ifndef QPD_PICKFIRSTSIGNALPROCESSOR_HPP
#define QPD_PICKFIRSTSIGNALPROCESSOR_HPP

#include <Utils/Types.hpp>

template<sizeType bufferSize, typename bufferDataType, indexType ID = 0>
class PickFirstSignalProcessor
{
public:
    using InputType = bufferDataType *;
    using OutputType = scalar;

    struct Parameters {
    };

    [[nodiscard]] static OutputType process(const InputType &data,const Parameters &parameters)
    {
        return data[0];
    }
};

#endif// QPD_PICKFIRSTSIGNALPROCESSOR_HPP
