//
// Created by Ivan Kalesnikau on 06.10.2022.
//

#ifndef COORDINATESYSTEM_INTERPOLATION_HPP
#define COORDINATESYSTEM_INTERPOLATION_HPP

#include <Utils/Types.hpp>
#include "Utils.hpp"

#ifdef MCU
#include <etl/algorithm.h>
#endif
#ifdef PC
#include <algorithm>
#endif

template<typename DataTypeX, typename DataTypeY, sizeType dataSize>
class IrregularMeshLinearInterpolation
{
public:
    using ContainerTypeX = array<DataTypeX, dataSize>;
    using ContainerTypeY = array<DataTypeY, dataSize>;
    ContainerTypeX dataX_;
    ContainerTypeY dataY_;

public:
    IrregularMeshLinearInterpolation() = default;
    IrregularMeshLinearInterpolation(const ContainerTypeX &dataX, const ContainerTypeY &dataY)
        : dataX_(dataX), dataY_(dataY) {}

    DataTypeY interpolate(const DataTypeX x)
    {
        if (x <= dataX_.front()) {
            return dataY_.front();
        }
        if (x >= dataX_.back()) {
            return dataY_.back();
        }

#ifdef MCU
        indexType upperIdx = etl::distance(dataX_.begin(), etl::upper_bound(dataX_.begin(), dataX_.end(), x));
#endif
#ifdef PC
        indexType upperIdx = std::distance(dataX_.begin(), std::upper_bound(dataX_.begin(), dataX_.end(), x));
#endif

        indexType lowerIdx = upperIdx - 1;

        return lerp<DataTypeX, DataTypeY>(x, dataX_[lowerIdx], dataX_[upperIdx], dataY_[lowerIdx], dataY_[upperIdx]);
    }
};

#endif// COORDINATESYSTEM_INTERPOLATION_HPP
