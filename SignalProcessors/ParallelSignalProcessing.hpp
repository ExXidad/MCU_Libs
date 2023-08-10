//
// Created by Ivan Kalesnikau on 16.07.2023.
//

#ifndef SIGNAL_PROCESSING_TEST_PARALLELSIGNALPROCESSINGPIPELINE_HPP
#define SIGNAL_PROCESSING_TEST_PARALLELSIGNALPROCESSINGPIPELINE_HPP

#include <Utils/Types.hpp>

template<typename SignalProcessingPipeline, sizeType numberOfChannels>
class ParallelSignalProcessing
{
public:
    using InputType = array<typename SignalProcessingPipeline::InputType, numberOfChannels>;
    using OutputType = array<typename SignalProcessingPipeline::OutputType, numberOfChannels>;

    using Parameters = array<typename SignalProcessingPipeline::Parameters, numberOfChannels>;

    [[nodiscard]] static OutputType process(const InputType &data,const Parameters &parameters)
    {
        OutputType output;
        for (indexType i = 0; i < numberOfChannels; ++i) {
            output[i] = SignalProcessingPipeline::process(data[i], parameters[i]);
        }
        return output;
    }
};

#endif//SIGNAL_PROCESSING_TEST_PARALLELSIGNALPROCESSINGPIPELINE_HPP
