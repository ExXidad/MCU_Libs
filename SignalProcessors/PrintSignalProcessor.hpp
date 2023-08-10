//
// Created by Ivan Kalesnikau on 17.07.2023.
//

#ifndef QPD_PRINTSIGNALPROCESSOR_HPP
#define QPD_PRINTSIGNALPROCESSOR_HPP

#include <Utils/Types.hpp>
#include <cstdio>

template <typename T, indexType ID = 0>
class PrintSignalProcessor {
public:
    using InputType = T;
    using OutputType = T;

    struct Parameters {};

    static OutputType process(const InputType &data, const Parameters &parameters) {
        for (const auto el : data) {
            printf("%8.8f ", el);
        }
        printf("\n");
        return data;
    }
};

// template<sizeType arraySize, indexType ID = 0>
// class PrintSignalProcessor
//{
// public:
//     using InputType = array<scalar, arraySize>;
//     using OutputType = void;
//
//     struct Parameters {
//     };
//
//     static OutputType process(const InputType &data,const Parameters &parameters)
//     {
//         for (indexType i = 0; i < arraySize; ++i) {
//             printf("%8.8f ",data[i]);
//         }
//         printf("\n");
//     }
// };

#endif  // QPD_PRINTSIGNALPROCESSOR_HPP
