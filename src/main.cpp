#ifndef TINYOBJLOADER_IMPLEMENTATION
#define TINYOBJLOADER_IMPLEMENTATION
#endif
#include "Model.h"
#include <iostream>

int main() {
  Model model("../tinyobjloader/models/cornell_box.obj");
  model.load();
  
  return 0;
}