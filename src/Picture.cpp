#include "Picture.h"
#include "fmt/core.h"
#include <fstream>


LRD::Picture::Picture(unsigned int width, unsigned int height, std::string path)
    : width(width), height(height), path(path) 
{
  data.assign(height, std::vector<Color>(width, {0, 0, 0}));
}

LRD::Color &LRD::Picture::at(unsigned int i, unsigned int j) { return data[i][j]; }

void LRD::Picture::writeToFile() {
  std::ofstream fs(path, std::ios::out);
  fs << "P3\n";
  fs << "# " << path << "\n";
  fs << fmt::format("{} {}\n", width, height);
  fs << 255 << "\n";
  unsigned int cnt = 0;
  for (auto vec : data) {
    for (auto col : vec) {
      cnt++;
      fs << fmt::format("{:>4}{:>4}{:>4}{}", col.r, col.g, col.b, (cnt%4==0?'\n':' '));
    }
  }
  fs.close();
}