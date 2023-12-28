#include "circle.h"
void Circle::setR(double R)
{
    m_R = R;
}
void Circle::setCenter(point::Point p)
{
    Center.setX(p.getX());
    Center.setY(p.getY());
}
double Circle::getR()
{
    return m_R;
}
void Circle::isInCircle(point::Point p)
{
    double distance = sqrt(pow(Center.getX() - p.getX(), 2) + pow(Center.getY() - p.getY(), 2));
    if (distance > m_R)
    {
        cout << "点在圆外" << endl;
    }
    else if (distance == m_R)
    {
        cout << "点在圆上" << endl;
    }
    else
        cout << "点在圆内" << endl;
}
