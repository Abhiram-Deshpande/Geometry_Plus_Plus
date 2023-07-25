//
// Created by peter on 20/7/23.
//
#include "Vector.h"

float crossProduct2D(abhiram::Vector2f v1, abhiram::Vector2f v2){

    return (v1[0]*v2[1])-(v1[1]*v2[0]);
}

abhiram::Vector3f crossProduct3D(abhiram::Vector3f &v1, abhiram::Vector3f &v2){

    float x_,y_,z_;
    x_ = v1[1]*v2[2]-v1[2]*v2[1];
    y_= -(v1[0]*v2[2]-v2[0]*v1[2]);
    z_= v1[0]*v2[1]-v1[1]*v2[2];
    return  {x_,y_,z_};
}
