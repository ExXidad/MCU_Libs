//
// Created by Ivan Kalesnikau on 16.07.2023.
//

#ifndef QPD_EXPONENTIALMOVINGAVERAGESIGNALPROCESSOR_HPP
#define QPD_EXPONENTIALMOVINGAVERAGESIGNALPROCESSOR_HPP

#include <Utils/Types.hpp>

template <typename T, indexType ID = 0>
class ExponentialMovingAverageSignalProcessor {
public:
    using InputType = T;
    using OutputType = T;

    struct Parameters {
        scalar newValueImpactFactor_;
        scalar oldValueImpactFactor_;
        T *oldValue_;
        bool *startFromNewValue_;

        Parameters() = default;

        Parameters(const scalar newValueImpactFactor, scalar *oldValue, bool *startFromNewValue)
            : oldValue_(oldValue),
              newValueImpactFactor_(newValueImpactFactor),
              oldValueImpactFactor_(1 - newValueImpactFactor),
              startFromNewValue_(startFromNewValue) {}
    };

    [[nodiscard]] static OutputType process(const InputType &data, const Parameters &parameters) {
        if (*parameters.startFromNewValue_) {
            (*parameters.startFromNewValue_) = false;
            (*parameters.oldValue_) = data;
        } else {
            (*parameters.startFromNewValue_) = false;
            (*parameters.oldValue_) = 0;
        }
        T output = (*parameters.oldValue_) * parameters.oldValueImpactFactor_ + data * parameters.newValueImpactFactor_;
        (*parameters.oldValue_) = output;
        return output;
    }
};

#endif  // QPD_EXPONENTIALMOVINGAVERAGESIGNALPROCESSOR_HPP
