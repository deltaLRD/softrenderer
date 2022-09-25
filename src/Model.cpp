#include "Model.h"


LRD::Model::Model(std::string objfilepath) {
    this->inputfile = objfilepath;
}

bool LRD::Model::load() {
    bool ret = tinyobj::LoadObj(
        &(this->attrib), &(this->shapes), 
        &(this->materials), &(this->warn), 
        &(this->err), this->inputfile.c_str()
    );
    return ret;
}

const std::string LRD::Model::get_err() {
    return this->err;
}

const std::string LRD::Model::get_warn() {
    return this->warn;
}