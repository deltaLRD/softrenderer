#ifndef MVP_H
#define MVP_H

#include "Eigen/Dense"
#include "Transform.h"
#include "Camera.h"

namespace LRD {

/*
 *    _//  z
 *  _//
 * //
 * ||----------> y
 * ||
 * ||
 * ||
 * \/
 * x
 */

Eigen::Matrix4f generateRotMatrix(float ax, float ay, float az, float angle);
Eigen::Matrix4f generateRotMatrix(const Eigen::Vector3f& axiso, float angle);

Eigen::Matrix4f generateScaleMatrix(float x, float y, float z);
Eigen::Matrix4f generateScaleMatrix(const Eigen::Vector3f& scale);

Eigen::Matrix4f generateMoveMatrix(float dx, float dy, float dz);
Eigen::Matrix4f generateMoveMatrix(const Eigen::Vector3f& d);

Eigen::Matrix4f generateModelMatrix(LRD::Transform trans);

Eigen::Matrix4f generateViewMatrix(LRD::Camera camera);
} // namespace LRD

#endif