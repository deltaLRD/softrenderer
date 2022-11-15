#ifndef TINYOBJLOADER_IMPLEMENTATION
#define TINYOBJLOADER_IMPLEMENTATION
#endif
#include "Model.h"
#include "MVP.h"
#include "Camera.h"
#include "Picture.h"
#include "const.h"

#include <iostream>

int main() {
  LRD::ScreenHeight = 1000;
  LRD::ScreenWidth = 1000;
  LRD::Picture pic(LRD::ScreenHeight, LRD::ScreenWidth, "./cornell_box.ppm");
  LRD::Model model("../tinyobjloader/models/cornell_box.obj");
  model.load();
  LRD::Camera camera{{0.0,0.0,0.0},{0.0,0.0,1.0},{-1.0,0.0,0.0}};
  auto MMatrix = LRD::generateModelMatrix({0,0,0});
  auto VMatrix = LRD::generateViewMatrix(camera);
  auto PMatrix = LRD::generateProjMatrix(camera, 2, 10, LRD::ScreenHeight, LRD::ScreenWidth);
  model.applyMatrix(PMatrix*VMatrix*MMatrix);
  
  return 0;
}