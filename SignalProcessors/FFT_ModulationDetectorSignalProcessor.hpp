//
// Created by Ivan Kalesnikau on 18.07.2023.
//

#ifndef QPD_FFT_MODULATIONDETECTORSIGNALPROCESSOR_HPP
#define QPD_FFT_MODULATIONDETECTORSIGNALPROCESSOR_HPP

#include <Utils/Types.hpp>

template <sizeType dataBufferSize, indexType ID = 0>
class FFT_ModulationDetectorSignalProcessor {
public:
    using InputType = scalar*;
    using OutputType = scalar;

    struct Parameters {
        scalar modulationFrequency_;
        scalar samplingRate_;
        scalar bandwidth_;
    };

    [[nodiscard]] static indexType freqToIdx(const scalar &freq, const Parameters &parameters) {
        return static_cast<indexType>(dataBufferSize * freq / parameters.samplingRate_);
    }

    [[nodiscard]] static OutputType process(const InputType &data, const Parameters &parameters) {
        indexType upperFreqIdx = freqToIdx(parameters.modulationFrequency_ + parameters.bandwidth_ / 2, parameters);
        indexType lowerFreqIdx = freqToIdx(parameters.modulationFrequency_ - parameters.bandwidth_ / 2, parameters);

        scalar spectralIntegral = 0;
        for (indexType i = lowerFreqIdx; i < upperFreqIdx; ++i) {
            spectralIntegral += data[i];
        }
        spectralIntegral *= parameters.bandwidth_ / (upperFreqIdx - lowerFreqIdx);

        //        for (indexType i = 0; i < inputBufferSize; ++i) {
        //            printf("%f ", data[i]);
        //        }
        //        printf("\n");

        return spectralIntegral;
    }
};

#endif  // QPD_FFT_MODULATIONDETECTORSIGNALPROCESSOR_HPP
