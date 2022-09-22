#include "Model.h"


Model::Model(std::string objfilepath) {
    this->inputfile = objfilepath;
}

bool Model::load() {
    bool ret = tinyobj::LoadObj(
        &(this->attrib), 
        &(this->shapes), 
        &(this->materials), 
        &(this->warn), &(this->err), 
        this->inputfile.c_str()
    );
    return ret;
}

const std::string Model::get_err() {
    return this->err;
}

const std::string Model::get_warn() {
    return this->warn;
}