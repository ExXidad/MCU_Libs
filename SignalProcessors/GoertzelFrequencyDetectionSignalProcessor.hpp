//
// Created by Ivan Kalesnikau on 16.07.2023.
//

#ifndef QPD_GOERTZELMODULATIONDETECTIONPROCESSOR_HPP
#define QPD_GOERTZELMODULATIONDETECTIONPROCESSOR_HPP

#include <MathUtils.hpp>
#include <Utils/Types.hpp>

template <typename bufferDataType, sizeType bufferSize, indexType ID = 0>
class GoertzelFrequencyDetectionSignalProcessor {
public:
    using InputType = bufferDataType *;
    using OutputType = scalar;

    struct Parameters {
        scalar frequencyToDetect_;
        scalar samplingRate_;
    };

    [[nodiscard]] static OutputType process(const InputType &data, const Parameters &parameters) {
        return GoertzelAlgorithm(bufferSize, parameters.frequencyToDetect_, parameters.samplingRate_, data);
    }
};

#endif  // QPD_GOERTZELMODULATIONDETECTIONPROCESSOR_HPP
