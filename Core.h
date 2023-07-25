//
// Created by peter on 19/7/23.
//

#ifndef COMPUTATIONAL_GEOMETRY_CORE_HEADER
#define COMPUTATIONAL_GEOMETRY_CORE_HEADER
#include<cmath>
namespace abhiram{
#define TOLERENCE 0.0000001

    enum class RELATIVE_POSITION{
        LEFT , RIGHT, BEHIND, BEYOND, BETWEEN, ORIGIN, DESTINATION

    };
    static bool isEqualD(double x, double y){
        return fabs( x - y ) < TOLERENCE;
    }
}

#endif //COMPUTATIONAL_GEOMETRY_CORE_HEADER
