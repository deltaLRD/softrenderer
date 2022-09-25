#include "Eigen/Dense"


int main(int argc, char* argv[])
{
    Eigen::Vector3f pos(2.0, 3.0, 5.0);
    Eigen::Vector4f alignPos;
    alignPos << pos, 1.0;
    Eigen::Matrix4f m;
    m << 1.0, 0.0, 0.0, 1.0,
         0.0, 1.0, 0.0, -1.0,
         0.0, 0.0, 1.0, 0.0,
         0.0, 0.0, 0.0, 1.0;
    auto newpos = m*alignPos;
    assert(newpos.x() == 3.0 && newpos.y() == 2.0 && newpos.z() == 5.0 && newpos.w() == 1.0);
    return 0;
}