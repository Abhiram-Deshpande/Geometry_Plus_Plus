//
// Created by peter on 19/7/23.
//

#ifndef COMPUTATIONAL_GEOMETRY_VECTOR_HEADER
#define COMPUTATIONAL_GEOMETRY_VECTOR_HEADER
#include<array>
#include<iostream>
#include "./Core.h"

namespace abhiram{

#define DIM2 2
#define DIM3 3

#define X 0
#define Y 1
#define Z 2

    template<class coordinate_type, size_t dimension = DIM3>
    class Vector {

        static_assert(std::is_arithmetic<coordinate_type>(),
                      "Vector class can only store integral or floating points values");
        static_assert(dimension >= DIM2, "Vector dimension at least should be 2D");

        std::array<coordinate_type, dimension> coords = {};
    public:
        Vector() = default;

        Vector(std::array<coordinate_type, dimension> _coords) : coords(_coords) {}

        Vector(coordinate_type _x, coordinate_type _y, coordinate_type _z) : coords({_x, _y, _z}) {}

        Vector(coordinate_type _x, coordinate_type _y) : coords({_x, _y}) {}

        bool operator==(const Vector<coordinate_type, dimension> &) const;

        bool operator>(const Vector<coordinate_type, dimension> &) const;

        bool operator<(const Vector<coordinate_type, dimension> &) const;

        bool operator!=(const Vector<coordinate_type, dimension> &) const;

        coordinate_type operator[](int) const;

        Vector<coordinate_type, dimension> operator+(const Vector<coordinate_type, dimension> &) const;

        Vector<coordinate_type, dimension> operator-(const Vector<coordinate_type, dimension> &) const;

        Vector<coordinate_type, dimension> operator*(const Vector<coordinate_type, dimension> &) const;

        void assign(size_t dim, coordinate_type value) const;

        friend float dotProduct(Vector<coordinate_type,dimension>& , Vector<coordinate_type,dimension>& );

        friend float magnitude(const Vector<coordinate_type,dimension>&);

    };

    template<class coordinate_type, size_t dimension>
    float magnitude(const Vector<coordinate_type, dimension> &v) {

        float powAddition=0.0f;
        for(int i=0;i<dimension;i++){
            powAddition+= pow(v.coords[i],2.0f);
        }
        return sqrt(powAddition);
    }

    template<class coordinate_type, size_t dimension>
    inline float
    dotProduct(Vector<coordinate_type, dimension> &v1, Vector<coordinate_type, dimension> &v2) {
        float product=0.0f;
        if(v1.coords.size() != v2.coords.size()){
            throw std::invalid_argument("Dimension of abhiram does not match");
        }
        for(int i=0;i<dimension;i++){
            product+=(v1[i]*v2[i]);
        }
        return product;
    }


    template<class coordinate_type, size_t dimension>
    coordinate_type Vector<coordinate_type, dimension>::operator[](int index) const {

        if(index >= this->coords.size()){
            throw std::invalid_argument("Array index out of bounds");
        }
        return this->coords[index];
    }

    typedef Vector<float,DIM2> Vector2f;
    typedef Vector<float,DIM3> Vector3f;

    template<class coordinate_type, size_t dimension>
    Vector<coordinate_type, dimension>
    Vector<coordinate_type, dimension>::operator+(const Vector<coordinate_type, dimension>& _other) const {
        std::array<coordinate_type,dimension>temp_array;
        for(int i=0;i<dimension;i++){
            temp_array[i] = coords[i]+ _other.coords[i];
        }
        return Vector<coordinate_type,dimension>(temp_array);
    }

    template<class coordinate_type, size_t dimension>
    Vector<coordinate_type, dimension>
    Vector<coordinate_type, dimension>::operator-(const Vector<coordinate_type, dimension>& _other) const {
        std::array<coordinate_type,dimension>temp_array;
        for(int i=0;i<dimension;i++){
            temp_array[i] = coords[i]- _other.coords[i];
        }
        return Vector<coordinate_type,dimension>(temp_array);
    }
    template<class coordinate_type, size_t dimension>
    Vector<coordinate_type, dimension>
    Vector<coordinate_type, dimension>::operator*(const Vector<coordinate_type, dimension>& _other) const {
        std::array<coordinate_type,dimension>temp_array;
        for(int i=0;i<dimension;i++){
            temp_array[i] = coords[i]* _other.coords[i];
        }
        return Vector<coordinate_type,dimension>(temp_array);
    }


    template<class coordinate_type, size_t dimension>
    inline bool
    Vector<coordinate_type,dimension>::operator == (const Vector<coordinate_type,dimension>& _other) const{

        for( int i=0;i<dimension;i++){

            if(!isEqualD(coords[i],_other.coords[i]))
            {
                return false;
            }
        }
        return true;
    }

    template<class coordinate_type, size_t dimension>
    inline bool
    Vector<coordinate_type,dimension>::operator!=(const Vector<coordinate_type, dimension> & _other) const {

        return !(this->operator==(_other));
    }


    template<class coordinate_type, size_t dimension>
    inline bool
    Vector<coordinate_type,dimension>::operator<(const Vector<coordinate_type, dimension>& _other) const {

        for( int i=0;i<dimension;i++) {
            if (this->coords[i] < _other.coords[i]) {
                return true;
            }
            else if (this->coords[i] > _other.coords[i]){
                return false;
            }
        }
        return false;
    }

    template<class coordinate_type, size_t dimension>
    inline bool
    Vector<coordinate_type,dimension>::operator>(const Vector<coordinate_type, dimension>& _other) const {

        for( int i=0;i<dimension;i++) {
            if (this->coords[i] > _other.coords[i]) {
                return true;
            }
            else if (this->coords[i] < _other.coords[i]){
                return false;
            }
        }
        return false;
    }

    template<class coordinate_type,size_t dimension>
    inline void
    Vector<coordinate_type,dimension>::assign(size_t dim, coordinate_type value) const {
        if(dim> this->coords.size()){
            throw std::invalid_argument("Array index out bounds");
        }
        this->coords[dim] = value;
    }

    float crossProduct2D(Vector2f v1,Vector2f v2); // Definition in source fil
    Vector3f crossProduct3D(Vector3f v1,Vector3f v2); // Definition in the source file
}
#endif //COMPUTATIONAL_GEOMETRY_VECTOR_HEADER
