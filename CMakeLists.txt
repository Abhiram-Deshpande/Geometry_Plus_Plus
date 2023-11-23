cmake_minimum_required(VERSION 3.25)
project(Computational_Geometry)

set(CMAKE_CXX_STANDARD 17)

add_executable(Computational_Geometry main.cpp Core.h Vector.h Vector.cpp GeoUtils.h Point.h GeoUtils.cpp Line.cpp Line.h)
