#pragma once
#include <iostream>
// #include "point.cpp"
using namespace std;
namespace point{class Point
{
private:
    double m_X;
    double m_Y;

public:
    void setX(double x);
    
    void setY(double Y);
    
    double getX();
    
    double getY();
    
};
}
