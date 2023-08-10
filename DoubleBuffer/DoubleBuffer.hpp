//
// Created by Ivan Kalesnikau on 29.06.2023.
//

#ifndef QPD_DOUBLEBUFFER_HPP
#define QPD_DOUBLEBUFFER_HPP

#include <Utils/Types.hpp>

template <typename T, sizeType bufferSize, typename ParametersT, void (*processFunction)(T *, const ParametersT &)>
class DoubleBuffer : public array<T, bufferSize * 2> {
public:
    DoubleBuffer() = default;

    void pasteThisToHalfCpltCallback(const ParametersT &parameters) { processFunction(this->data(), parameters); }

    void pasteThisToCpltCallback(const ParametersT &parameters) {
        processFunction(this->data() + bufferSize, parameters);
    }
};

#endif  // QPD_DOUBLEBUFFER_HPP
