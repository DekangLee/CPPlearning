#include <iostream>
using namespace std;
class Person
{
public:
    Person()
    {
    }
    void showAge() const
    {
        // this->m_Age=10;
        this->m_number = 1234;
    }
    int m_Age;
    mutable int m_number;
};

void test01()
{
    const Person p1;
    p1.showAge();
    cout << p1.m_number << endl;
}
int main()
{
    test01();
    system("pause");
    return 1;
}