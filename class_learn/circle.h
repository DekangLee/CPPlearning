#pragma once
#include <iostream>
#include"point.h"
#include "math.h"
// #include "circle.cpp"
using namespace std;
// const double pi = 3.14;
class Circle
{
private:
    double m_R;
    point::Point Center;

public:
    
    void setR(double R);
    
    void setCenter(point::Point p);
    
    double getR();
    
    void isInCircle(point::Point p);
    
};