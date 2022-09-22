#ifndef PICTURN_H
#define PICTURN_H

#include "Color.h"
#include <string>
#include <vector>

class Picture {

public:
    
    Picture() = delete;

    Picture(unsigned int width, unsigned int height, std::string path);

    void writeToFile();

    Color& at(unsigned int i, unsigned int j);


private:
    std::vector<std::vector<Color>> data;
    unsigned int width;
    unsigned int height;
    std::string path;
};

#endif