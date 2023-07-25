//
// Created by peter on 20/7/23.
//
#include "GeoUtils.h"
#include "Core.h"
double abhiram::areaOfTriangle2D(const abhiram::Point2d &a, const abhiram::Point2d &b, const abhiram::Point2d &c) {

    auto AB = b-a;
    auto AC = c-a;
    auto result = crossProduct2D(AB,AC);
    return result/2;
}
int abhiram::orientation2D(const abhiram::Point2d &a, const abhiram::Point2d &b, const abhiram::Point2d &c) {

    int area = areaOfTriangle2D(a,b,c);
    Vector2f ab = b - a;
    Vector2f ac = c - a;

    if(area >0 && area <TOLERENCE){
        area=0;
    }
    if(area <0 && area <TOLERENCE){
        area=0;
    }

    if(area >0){
        return static_cast<int>(RELATIVE_POSITION::LEFT);
    }
    if(area <0)
        return static_cast<int>(RELATIVE_POSITION::RIGHT);

    if((ab[X] * ac[X])<0 || (ab[Y] * ac[Y] <0))
    {
        return static_cast<int>(RELATIVE_POSITION::BEHIND);
    }
    if(magnitude(ab) < magnitude(ac)){
        return static_cast<int>(RELATIVE_POSITION::BEYOND);
    }

    if(a==c){
        return static_cast<int>(RELATIVE_POSITION::ORIGIN);
    }
    if(b==c){
        return static_cast<int>(RELATIVE_POSITION::DESTINATION);
    }
    return static_cast<int>(RELATIVE_POSITION::BETWEEN);
    }
