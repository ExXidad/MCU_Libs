//
// Created by Ivan Kalesnikau on 18.07.2023.
//

#ifndef QPD_FFT_SIGNALPROCESSOR_HPP
#define QPD_FFT_SIGNALPROCESSOR_HPP

#include <arm_math.h>
#include <Utils/Types.hpp>

template <typename InputBufferIterator, sizeType bufferSize, indexType ID = 0>
class FFT_SignalProcessor {
public:
    using InputType = InputBufferIterator;
    using OutputType = scalar*;

    struct Parameters {
        arm_rfft_fast_instance_f32 *FFT_handler_;
        array<scalar, bufferSize> *FFT_inputBuffer_;
        array<scalar, bufferSize> *FFT_outputBuffer_;
        uint8_t ifftFlag_;
    };

    [[nodiscard]] static OutputType process(const InputType &data, const Parameters &parameters) {
        for (indexType i = 0; i < bufferSize; ++i) {
            (*parameters.FFT_inputBuffer_)[i] = static_cast<scalar>(data[i]);
        }
        arm_rfft_fast_f32(parameters.FFT_handler_, parameters.FFT_inputBuffer_->data(),
                          parameters.FFT_outputBuffer_->data(), parameters.ifftFlag_);

        return parameters.FFT_outputBuffer_->data();
    }
};

#endif  // QPD_FFT_SIGNALPROCESSOR_HPP
