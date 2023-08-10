//
// Created by Ivan Kalesnikau on 04.08.2023.
//

#ifndef QPD_UTILS_HPP
#define QPD_UTILS_HPP

template <typename XType, typename YType>
YType lerp(const XType& x, const XType& x1, const XType& x2, const YType& y1, const YType& y2) {
    return (y2 * (x - x1) - y1 * (x - x2)) / (x2 - x1);
}

#endif  // QPD_UTILS_HPP
