//
// Created by Ivan Kalesnikau on 09.08.2023.
//

#ifndef SIGNAL_PROCESSING_TEST_PID_CONTROLLER_HPP
#define SIGNAL_PROCESSING_TEST_PID_CONTROLLER_HPP

#include <Utils/Types.hpp>

template<sizeType stateVectorSize>
class PID_Controller
{
public:
    using StateVectorType = Eigen::Vector<scalar, stateVectorSize>;

    using InputType = StateVectorType;
    using OutputType = StateVectorType;


    struct Parameters {
        StateVectorType goal;
        scalar kp;
        scalar ki;
        scalar kd;
        scalar timestep;
        scalar errorIntegralForgetCoefficient;
        StateVectorType *errorIntegral;
        StateVectorType *previousError;
    };

    static OutputType process(const InputType &input, const Parameters &parameters)
    {
        StateVectorType error = parameters.goal - input;
        StateVectorType errorD = (error - (*parameters.previousError)) / parameters.timestep;
        StateVectorType signal = error * parameters.kp + (*parameters.errorIntegral) * parameters.ki + errorD * parameters.kd;
        (*parameters.errorIntegral) = (*parameters.errorIntegral) * parameters.errorIntegralForgetCoefficient + error * parameters.timestep;
        (*parameters.previousError) = error;
        return signal;
    }
};

#endif//SIGNAL_PROCESSING_TEST_PID_CONTROLLER_HPP
