//
// Created by Ivan Kalesnikau on 04.08.2023.
//

#ifndef QPD_REGULARMESHLINEARINTERPOLATION_HPP
#define QPD_REGULARMESHLINEARINTERPOLATION_HPP

#include <Utils/Types.hpp>

template <typename DataTypeX, typename DataTypeY, sizeType dataSize>
class RegularMeshLinearInterpolation {
public:

    using ContainerTypeY = array<DataTypeY, dataSize>;
    ContainerTypeY dataY_;
    using DeltaType = decltype(DataTypeX{} - DataTypeX{});
    DataTypeX start_, stop_;
    DeltaType step_;

public:
    RegularMeshLinearInterpolation() = default;
    RegularMeshLinearInterpolation(const DataTypeX &start, const DataTypeX &stop, const DeltaType &step,
                                   const ContainerTypeY &dataY)
        : start_(start), stop_(stop), step_(step), dataY_(dataY) {}

    DataTypeY interpolate(const DataTypeX x) {
        if (x <= start_) {
            return dataY_.front();
        }
        if (x >= stop_) {
            return dataY_.back();
        }

        indexType lowerIdx = std::floor((x - start_) / step_);
        indexType upperIdx = lowerIdx + 1;

        return lerp<DataTypeX, DataTypeY>(x, start_ + static_cast<scalar>(lowerIdx) * step_,
                                          start_ + static_cast<scalar>(upperIdx) * step_, dataY_[lowerIdx],
                                          dataY_[upperIdx]);
    }
};

#endif  // QPD_REGULARMESHLINEARINTERPOLATION_HPP
