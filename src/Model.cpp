#include "Model.h"
#include "Eigen/src/Core/Matrix.h"


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

void LRD::Model::applyMatrix(const Eigen::Matrix4f& m){
    auto VSize = this->attrib.vertices.size();
    for(int i=0;i<VSize;i+=3) {
        Eigen::Vector4f v{
            this->attrib.vertices[i],
            this->attrib.vertices[i+1],
            this->attrib.vertices[i+2],
            1.0f
        };
        Eigen::Vector4f nv = m*v;
        this->attrib.vertices[i] = nv[0]/nv[3];
        this->attrib.vertices[i+1] = nv[1]/nv[3];
        this->attrib.vertices[i+2] = nv[2]/nv[3];
    }
}

size_t LRD::Model::getVerticesNum() {
    return this->attrib.vertices.size();
}

const std::string LRD::Model::get_err() {
    return this->err;
}

const std::string LRD::Model::get_warn() {
    return this->warn;
}