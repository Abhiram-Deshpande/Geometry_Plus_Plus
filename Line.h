//
// Created by peter on 20/7/23.
//

#ifndef COMPUTATIONAL_GEOMETRY_LINE_H
#define COMPUTATIONAL_GEOMETRY_LINE_H
#include"Vector.h"
namespace abhiram{

    template<class coordinate_type, size_t dimension = DIM3>
    class Line{
            Vector<coordinate_type,dimension>point;
            Vector<coordinate_type,dimension>dir;

    public:
        Line(){}

        Line(Vector<coordinate_type,dimension> &v1, Vector<coordinate_type,dimension> & v2){
            this->dir = v2-v1;
            this->point = v1;
        }

        const Vector<coordinate_type, dimension> &getPoint() const {
            return this->point;
        }

        const Vector<coordinate_type, dimension> &getDir() const {
            return this->dir;
        }

    };
}
#endif //COMPUTATIONAL_GEOMETRY_LINE_H
