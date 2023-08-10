//
// Created by Ivan Kalesnikau on 16.07.2023.
//

#ifndef QPD_DATAPROCESSINGPIPELINE_HPP
#define QPD_DATAPROCESSINGPIPELINE_HPP

template <typename... SignalProcessors>
class SignalProcessingPipeline;

template <typename SignalProcessor>
class SignalProcessingPipeline<SignalProcessor> {
public:
    using InputType = typename SignalProcessor::InputType;
    using OutputType = typename SignalProcessor::OutputType;

    using Parameters = typename SignalProcessor::Parameters;

    [[nodiscard]] static OutputType process(const InputType &data, const Parameters &parameters) {
        return SignalProcessor::process(data, parameters);
    }
};

template <typename SignalProcessor, typename... SignalProcessors>
class SignalProcessingPipeline<SignalProcessor, SignalProcessors...> {
public:
    using InputType = typename SignalProcessor::InputType;
    using OutputType = typename SignalProcessingPipeline<SignalProcessors...>::OutputType;

    struct Parameters : SignalProcessor::Parameters, SignalProcessingPipeline<SignalProcessors...>::Parameters {};

    [[nodiscard]] static OutputType process(const InputType &data, const Parameters &parameters) {
        return SignalProcessingPipeline<SignalProcessors...>::process(SignalProcessor::process(data, parameters),
                                                                      parameters);
    }
};

#endif  // QPD_DATAPROCESSINGPIPELINE_HPP
