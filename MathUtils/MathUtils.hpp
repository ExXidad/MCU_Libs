//
// Created by Ivan Kalesnikau on 05.07.2023.
//

#ifndef MEMS_MATHUTILS_HPP
#define MEMS_MATHUTILS_HPP

#include <Utils/Types.hpp>
#include <Utils/Math.hpp>

template <typename T>
T bound(const T value, const T lower, const T upper) {
    return (value > upper) ? upper : ((value < lower) ? lower : value);
}

template <typename T>
scalar GoertzelAlgorithm(const sizeType nsamp, const scalar targetFrequency, const scalar samplingRate, const T* data) {
    sizeType k = static_cast<sizeType>(static_cast<scalar>(0.5) + nsamp * targetFrequency / samplingRate);
    scalar scalingFactor = nsamp / 2;
    scalar q0 = 0, q1 = 0, q2 = 0;
    scalar omega = 2 * math::pi * k / nsamp;
    scalar sin_ = math::sin(omega);
    scalar cos_ = math::cos(omega);
    scalar coeff = 2 * cos_;

    //    scalar total = 0;
    //    scalar totalSq = 0;
    //    for (indexType i = 0; i < nsamp; ++i) {
    //        scalar x = data[i];
    //        total += x;
    //        totalSq += x * x;
    //    }
    //    scalar stdDev = sqrtf((totalSq - total) / nsamp);

    for (indexType i = 0; i < nsamp; ++i) {
        q0 = coeff * q1 - q2 + static_cast<scalar>(data[i]);
        q2 = q1;
        q1 = q0;
        printf("%16.16f ", static_cast<scalar>(data[i]));
    }

    scalar re = (q1 - q2 * cos_) / scalingFactor;
    scalar im = q2 * sin_ / scalingFactor;
    scalar result = math::sqrt(re * re + im * im);
    printf("%16.16f\n",result);

    return result;
}

#endif  // MEMS_MATHUTILS_HPP
