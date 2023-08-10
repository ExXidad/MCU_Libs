//
// Created by Ivan Kalesnikau on 16.07.2023.
//

#ifndef QPD_QPD_POSITIONSIGNALPROCESSOR_HPP
#define QPD_QPD_POSITIONSIGNALPROCESSOR_HPP

#include <Utils/Math.hpp>
#include <Utils/Types.hpp>

#ifdef MCU
#include <etl/limits.h>
#endif

template<indexType ID = 0>
class QPD_PositionSignalProcessor
{
public:
    constexpr static sizeType numberOfChannels = 4;
    using InputType = etl::array<scalar, numberOfChannels>;
    using OutputType = Vector2s;

    struct Parameters {
    };

    [[nodiscard]] static OutputType process(const InputType &data,const Parameters &parameters)
    {
        scalar total = 0;
        for (indexType i = 0; i < numberOfChannels; ++i) {
            total += data[i];
        }

        if (math::abs(total) < 4 *
#ifdef MCU
                                       etl::numeric_limits<scalar>::min()
#endif
#ifdef PC
                                               std::numeric_limits<scalar>::min()
#endif
                    )// [[unlikely]]
        {
            return {0, 0};
        }

        scalar xSignal = ((data[0] + data[3]) - (data[1] + data[2])) / total;
        scalar ySignal = ((data[0] + data[1]) - (data[2] + data[3])) / total;

        return {xSignal, ySignal};
    }
};

#endif// QPD_QPD_POSITIONSIGNALPROCESSOR_HPP
