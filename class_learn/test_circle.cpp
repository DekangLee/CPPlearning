#include"point.h"
#include"circle.h"
// #include "circle.cpp"
// #include "point.cpp"
#include<string>
class Student
{
public:
    string name;
    string number;
    string getName()
    {
        return name;
    }
    string getNumber()
    {
        return number;
    }
    void setName(string name)
    {
        this->name = name;
    }
};
int main()
{

    point::Point p;
    p.setX(3);
    p.setY(4);
    point::Point center;
    center.setX(0);
    center.setY(0);
    Circle c;
    c.setR(5);
    c.setCenter(center);
    c.isInCircle(p);

    system("pause");
    return 1;
}