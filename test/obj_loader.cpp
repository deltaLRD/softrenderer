#ifndef TINYOBJLOADER_IMPLEMENTATION
#define TINYOBJLOADER_IMPLEMENTATION
#endif
#include "Model.h"
#include <iostream>
#include <assert.h>

int main(int argc, char* argv[])
{
    Model model("../tinyobjloader/models/cornell_box.obj");
    bool ret = model.load();
    std::cout << model.get_warn() << "\n";
    std::cout << model.get_err() << "\n";
    assert(ret);
    return 0;
}