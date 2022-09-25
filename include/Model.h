
#ifndef MODEL_H
#define MODEL_H

#include "tiny_obj_loader.h"
#include <string>
#include <vector>

namespace LRD {


class Model {
public:
  Model() = delete;


  Model(std::string);


  bool load();


  const std::string get_err();

  
  const std::string get_warn();

private:
  std::string inputfile;
  tinyobj::attrib_t attrib;
  std::vector<tinyobj::shape_t> shapes;
  std::vector<tinyobj::material_t> materials;
  std::string warn;
  std::string err;
};
}
#endif