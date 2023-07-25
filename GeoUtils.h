#ifndef COMPUTATIONAL_GEOMETRY_GEO_UTILS_HEADER
#define COMPUTATIONAL_GEOMETRY_GEO_UTILS_HEADER
#include "Point.h"
namespace abhiram{
    double areaOfTriangle2D(const Point2d& p1,const Point2d& p2,const Point2d& p3);
    int orientation2D(const Point2d& a,const Point2d& b,const Point2d& c);

}
#endif //COMPUTATIONAL_GEOMETRY_GEO_UTILS_HEADER
