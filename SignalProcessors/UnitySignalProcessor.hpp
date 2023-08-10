//
// Created by Ivan Kalesnikau on 16.07.2023.
//

#ifndef QPD_UNITYSIGNALPROCESSOR_HPP
#define QPD_UNITYSIGNALPROCESSOR_HPP

#include <Utils/Types.hpp>

template <typename T, indexType ID = 0>
class UnitySignalProcessor {
public:
    using InputType = T;
    using OutputType = T;

    struct Parameters {};

    [[nodiscard]] static OutputType process(const InputType &data, const Parameters &parameters) { return data; }
};

#endif  // QPD_UNITYSIGNALPROCESSOR_HPP
