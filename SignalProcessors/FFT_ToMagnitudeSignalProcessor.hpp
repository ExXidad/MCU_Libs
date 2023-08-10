//
// Created by Ivan Kalesnikau on 18.07.2023.
//

#ifndef QPD_FFT_TOMAGNITUDESIGNALPROCESSOR_HPP
#define QPD_FFT_TOMAGNITUDESIGNALPROCESSOR_HPP

#include <Utils/Types.hpp>
#include <Utils/Math.hpp>

template <sizeType inputBufferSize, indexType ID = 0>
class FFT_ToMagnitudeSignalProcessor {
public:
    using InputType = scalar *;
    using OutputType = scalar *;

    struct Parameters {
        array<scalar, inputBufferSize> *FFT_inputBuffer_;
        array<scalar, inputBufferSize> *FFT_outputBuffer_;
    };

    [[nodiscard]] static OutputType process(const InputType &data, const Parameters &parameters) {
        static_assert((inputBufferSize % 2) == 0, "Incorrect input buffer dimension!");
        constexpr sizeType outputBufferSize = inputBufferSize / 2;
        constexpr scalar invOutputBufferSize = 1 / static_cast<scalar>(outputBufferSize);

        for (indexType i = 0; i < inputBufferSize / 2; ++i) {
            scalar re = (*parameters.FFT_inputBuffer_)[2 * i];
            scalar im = (*parameters.FFT_inputBuffer_)[2 * i + 1];
            (*parameters.FFT_outputBuffer_)[i] = math::sqrt(re * re + im * im) * invOutputBufferSize;
        }

        return parameters.FFT_outputBuffer_->data();
    }
};

#endif  // QPD_FFT_TOMAGNITUDESIGNALPROCESSOR_HPP
