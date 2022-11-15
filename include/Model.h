
#ifndef MODEL_H
#define MODEL_H

#include "tiny_obj_loader.h"
#include "Eigen/Dense"
#include <string>
#include <vector>

namespace LRD {


class Model {
public:
  Model() = delete;


  Model(std::string);


  bool load();

  void applyMatrix(const Eigen::Matrix4f& m);

  size_t getVerticesNum();

  const std::string get_err();

  
  const std::string get_warn();

private:
// attrib_t::vertices => 3 floats per vertex

//        v[0]        v[1]        v[2]        v[3]               v[n-1]
//   +-----------+-----------+-----------+-----------+      +-----------+
//   | x | y | z | x | y | z | x | y | z | x | y | z | .... | x | y | z |
//   +-----------+-----------+-----------+-----------+      +-----------+

// attrib_t::normals => 3 floats per vertex

//        n[0]        n[1]        n[2]        n[3]               n[n-1]
//   +-----------+-----------+-----------+-----------+      +-----------+
//   | x | y | z | x | y | z | x | y | z | x | y | z | .... | x | y | z |
//   +-----------+-----------+-----------+-----------+      +-----------+

// attrib_t::texcoords => 2 floats per vertex

//        t[0]        t[1]        t[2]        t[3]               t[n-1]
//   +-----------+-----------+-----------+-----------+      +-----------+
//   |  u  |  v  |  u  |  v  |  u  |  v  |  u  |  v  | .... |  u  |  v  |
//   +-----------+-----------+-----------+-----------+      +-----------+

// attrib_t::colors => 3 floats per vertex(vertex color. optional)

//        c[0]        c[1]        c[2]        c[3]               c[n-1]
//   +-----------+-----------+-----------+-----------+      +-----------+
//   | x | y | z | x | y | z | x | y | z | x | y | z | .... | x | y | z |
//   +-----------+-----------+-----------+-----------+      +-----------+

  std::string inputfile;
  tinyobj::attrib_t attrib;
  std::vector<tinyobj::shape_t> shapes;
  std::vector<tinyobj::material_t> materials;
  std::string warn;
  std::string err;
};
}
#endif