//
// Created by Ivan Kalesnikau on 16.07.2023.
//

#ifndef QPD_MEANSIGNALPROCESSOR_HPP
#define QPD_MEANSIGNALPROCESSOR_HPP

#include <Utils/Types.hpp>

template<sizeType bufferSize, typename bufferDataType, indexType ID = 0>
class MeanSignalProcessor
{
public:
    using InputType = bufferDataType *;
    using OutputType = scalar;

    struct Parameters {
        scalar frequencyToDetect_;
        scalar samplingRate_;
    };

    [[nodiscard]]  static OutputType process(const InputType &data,const Parameters &parameters)
    {
        scalar total = 0;
        for (indexType i = 0; i < bufferSize; ++i) {
            total += static_cast<scalar>(data[i]);
        }
        return total / bufferSize;
    }
};

#endif// QPD_MEANSIGNALPROCESSOR_HPP
