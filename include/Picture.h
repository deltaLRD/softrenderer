#ifndef PICTURN_H
#define PICTURN_H

#include "Color.h"
#include <string>
#include <vector>

namespace LRD {


class Picture {

public:
  Picture() = delete;
  
  /**
   * @brief Construct a new Picture object
   * @brief the picture [0][0] position is on the top left, the [height][width] is on the right bottom
   * @param width the width of the picture
   * @param height the height of the picture
   * @param path the path of the file to storage the picture
   */
  Picture(unsigned int width, unsigned int height, std::string path);
  
  /**
   * @brief write the picture add to a .ppm format picture
   * 
   */
  void writeToFile();
  
  /**
   * @brief return Color at the pixel at [i][j]
   * 
   * @param i
   * @param j 
   * @return Color& 
   */
  Color &at(unsigned int i, unsigned int j);

private:
  std::vector<std::vector<Color>> data;
  unsigned int width;
  unsigned int height;
  std::string path;
};
}
#endif