#include <iostream>
using namespace std;
#include <string>
// 赋值=运算符重载
class Person
{
    friend bool operator<(Person &p1, Person &p2);
    friend bool operator>(Person &p1, Person &p2);
    friend bool operator==(Person &p1, Person &p2);
    friend Person operator+(Person &p1, Person &p2);
    friend class AddNumber;

public:
    int *m_Age;
    Person()
    {
        m_Age = new int;
        m_Hight = new float;
    }
    Person(int Age, float Hight)
    {
        m_Age = new int(Age);
        m_Hight = new float(Hight);
    }
    Person(const Person &p)
    {
        cout<<"深拷贝"<<endl;
        m_Age = new int(*p.m_Age);
        m_Hight = new float(*p.m_Hight);
    }
    void operator()(string s)
    {
        cout << s << endl;
    }

    ~Person()
    {
        if (m_Age != NULL || m_Hight != NULL)
        {
            delete m_Age, m_Hight;
            m_Age = NULL;
            m_Hight = NULL;
        }
    }
    Person &operator=(const Person &p1)
    {
        cout<<"赋值运算符重载"<<endl;
        if (m_Age != NULL || m_Hight != NULL)
        {
            delete m_Age, m_Hight;
            m_Age = NULL;
            m_Hight = NULL;
        }
        m_Age = new int(*p1.m_Age);
        m_Hight = new float(*p1.m_Hight);
        return *this;
    }
    float GetHight()
    {
        return *m_Hight;
    }

private:
    float *m_Hight;
};
class LDK : public Person
{

};
bool operator<(Person &p1, Person &p2)
{
    if (*p1.m_Hight < *p2.m_Hight)
    {
        return true;
    }
    else
        return false;
}
bool operator>(Person &p1, Person &p2)
{
    if (*p1.m_Hight > *p2.m_Hight)
    {
        return true;
    }
    else
        return false;
}

bool operator==(Person &p1, Person &p2)
{
    if (*p1.m_Hight == *p2.m_Hight)
    {
        return true;
    }
    else
        return false;
}
Person operator+(Person &p1, Person &p2)
{
    Person p_temp;
    *p_temp.m_Age = *p1.m_Age + *p2.m_Age;
    return p_temp;
}
void test01()
{
    Person p1(18, 178);
    Person p2;
    p2 = p1;
    Person *p3 = new Person(10, 150);
    // p2 = p1 = *p3; // 与内置数据类型一样从右向左赋值
    cout << "p1的年龄" << *p1.m_Age << endl;
    cout << "p2的年龄" << *p2.m_Age << endl;
    cout << "p3的年龄" << *(p3->m_Age) << endl;
    cout<<"p1的身高"<<p1.GetHight()<<endl;
    cout<<"p2的身高"<<p2.GetHight()<<endl;
    cout<<"p3的身高"<<p3->GetHight()<<endl;
    if (p2 < p1)
    {
        cout << "p1的身高较高" << endl;
    }
    else if (p2 == p1)
    {
        cout << "p1与p2身高一样" << endl;
    }
    else if (p2 > p1)
        cout << "p2身高较高" << endl;
}
class AddNumber
{
public:
    int operator()(int a, int b)
    {
        cout<<"int + int"<<endl;
        return a + b;
    }
    float operator()( float a, float b)
    {
        cout<<"float + float"<<endl;
        return a + b;
    }
    double operator()( double a, double b)
    {
        cout<<"double + double"<<endl;
        return a + b;
    }

    Person operator()(Person &p1, Person &p2)
    {
        Person temp;
        *temp.m_Hight = p1.GetHight() + p2.GetHight();
        return temp;
    }
};
void test02()
{
    Person p1(10, 160);
    Person p2(20, 190);
    AddNumber add;
    LDK ldk;
    cout<<"ldk's hight:"<<ldk.GetHight()<<endl;
    cout<<add(p1,p2).GetHight()<<endl;
    cout<<AddNumber()(1.1,2.4)<<endl; 
    p1("Hello, Ldk"); // 使用起来非常像函数调用，又称之为仿函数
}
int main()
{
    test01();
    // test02();
    system("pause");
    return 1;
}