//
// Created by LRD on 2022/9/28.
//
#include "Eigen/Dense"
#include "MVP.h"
#include <cassert>
#include <cmath>
#include <iostream>

int main(int argc, char *argv[]) {
    Eigen::Vector3f pos(1.0, 4.0, 2.0);

    auto            RotMatrix = LRD::generateRotMatrix(0.0, 0.0, 1.0, 90.0);
    Eigen::Vector4f alignPos;
    alignPos << pos, 1.0;
    auto newAlignPos = RotMatrix * alignPos;
    // std::cout << newAlignPos << "\n";
    assert(std::abs(newAlignPos.x() - 4.0) <= 0.000001 &&
           std::abs(newAlignPos.y() - (-1.0)) <= 0.000001 &&
           std::abs(newAlignPos.z() - 2.0) <= 0.000001 &&
           std::abs(newAlignPos.w() - 1.0) <= 0.000001);
    RotMatrix = LRD::generateRotMatrix(1.0, 0.0, 0.0, 90.0);
    auto newAlignPos2 = RotMatrix * alignPos;
    std::cout << newAlignPos2 << "\n";
    assert(std::abs(newAlignPos2.x() - 1.0) <= 0.000001 &&
           std::abs(newAlignPos2.y() - (2.0)) <= 0.000001 &&
           std::abs(newAlignPos2.z() - (-4.0)) <= 0.000001 &&
           std::abs(newAlignPos2.w() - 1.0) <= 0.000001);

    return 0;
}