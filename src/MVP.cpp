#include "MVP.h"
#include "Eigen/src/Core/Matrix.h"

Eigen::Matrix4f LRD::generateMoveMatrix(float dx, float dy, float dz) {
    Eigen::Matrix4f M;
    M << 1.0, 0.0, 0.0, dx, 0.0, 1.0, 0.0, dy, 0.0, 0.0, 1.0, dz, 0.0, 0.0, 0.0,
        1.0;
    return M;
}

Eigen::Matrix4f LRD::generateScaleMatrix(float x, float y, float z) {
    Eigen::Matrix4f M;
    M << x, 0.0, 0.0, 0.0, 0.0, y, 0.0, 0.0, 0.0, 0.0, z, 0.0, 0.0, 0.0, 0.0,
        1.0;
    return M;
}
Eigen::Matrix4f LRD::generateScaleMatrix(const Eigen::Vector3f& scale) {
    return LRD::generateScaleMatrix(scale.x(), scale.y(), scale.y());
}

Eigen::Matrix4f LRD::generateRotMatrix(float ax, float ay, float az,
                                       float angle) {
    // Use Rodriguez rotation formula
    float           radian = (-angle / 360.0) * 2 * 3.1415926;
    Eigen::Matrix4f model = Eigen::Matrix4f::Identity();
    Eigen::Matrix3f I = Eigen::Matrix3f::Identity();
    Eigen::Matrix3f M;
    Eigen::Matrix3f Rk;
    Rk << 0, -az, ay, az, 0, -ax, -ay, ax, 0;

    M = I + (1 - cos(radian)) * Rk * Rk + sin(radian) * Rk;

    model << M(0, 0), M(0, 1), M(0, 2), 0, M(1, 0), M(1, 1), M(1, 2), 0,
        M(2, 0), M(2, 1), M(2, 2), 0, 0, 0, 0, 1;
    return model;
}

Eigen::Matrix4f LRD::generateRotMatrix(const Eigen::Vector3f& axiso, float angle)
{
    return LRD::generateRotMatrix(axiso.x(), axiso.y(), axiso.z(), angle);
}

Eigen::Matrix4f LRD::generateModelMatrix(LRD::Transform trans) {
    Eigen::Matrix4f m;
    Eigen::Matrix4f MoveMatrix =
        LRD::generateMoveMatrix(trans.dx, trans.dy, trans.dz);
    Eigen::Matrix4f RotMatrix =
        LRD::generateRotMatrix(trans.ax, trans.ay, trans.az, trans.angle);
    Eigen::Matrix4f ScaleMatrix =
        LRD::generateScaleMatrix(trans.scalex, trans.scaley, trans.scalez);
    m = MoveMatrix * ScaleMatrix * RotMatrix;
    return m;
}

Eigen::Matrix4f LRD::generateMoveMatrix(const Eigen::Vector3f& d) {
    return LRD::generateMoveMatrix(d.x(), d.y(), d.z());
}

/**
 * @brief generate the View Matrix of a camera
 * @param camera 
 * @return Eigen::Matrix4f
 */
Eigen::Matrix4f LRD::generateViewMatrix(LRD::Camera& camera) {
    // https://zhuanlan.zhihu.com/p/373489211
    Eigen::Matrix4f m;
    Eigen::Vector3f Up{0,1,0};
    Eigen::Vector3f R = Up.cross(camera.dir);
    Eigen::Vector3f U = camera.dir.cross(R);
    m <<    R[0], R[1], R[2], -camera.pos[0],
            U[0], U[1], U[2], -camera.pos[1],
            camera.dir[0], camera.dir[1], camera.dir[2], -camera.pos[2],
            0,0,0,1;
    return m;
}

Eigen::Matrix4f LRD::generateProjMatrix(LRD::Camera& camera, float znear, float zfar, float width, float height) {
    Eigen::Matrix4f m;
    m <<    2.0*znear/height, 0, 0, 0,
            0, 2.0*znear/width, 0, 0,
            0, 0, -2.0f/(zfar-znear), -(zfar+znear)/(zfar-znear),
            0,0,0,1;
    return m;
}