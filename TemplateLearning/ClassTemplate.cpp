#include <iostream>
#include <string>
using namespace std;
template <class Nametype, class Agetype = int>
class Person
{
public:
    Person()
    {
        
    }
    Person(Nametype name, Agetype age) // 类模板中可以使用默认参数
    {
        this->m_age = age;
        this->m_name = name;
    }
    void show_Person()
    {
        cout << "Name:" << m_name << " Age:" << m_age << endl;
    }
    Agetype show_Age()
    {
        return m_age;
    }
    Nametype show_Name()
    {
        return m_name;
    }
    Nametype m_name;
    Agetype m_age;
};
// 类模板作为函数参数,指定传入类型
void printPerson(Person<string, int> &p)
{
    p.show_Person();
}
// template <class T1, class T2>
// void printPerson(Person<T1, T2> &p)
// {
//     // cout << "模板函数" << endl;
//     cout << "T1的类型" << typeid(T1).name() << endl;
//     cout << "T2的类型" << typeid(T2).name() << endl;
//     p.show_Person();
// }
template <class T>
void printPerson(T &p)
{
    cout << "整个类模板化" << endl;
    p.show_Person();
}
template <class T>
class MyClass
{
public:
    T obj;
    void func1()
    {
        cout << obj.show_Age() << endl;
    }
    void func2()
    {
        cout << obj.show_Name() << endl;
    }
    void func3() // 事实上Person类中根本没有show_________这个夸张的函数，但是可以编译通过！！！！只要不调用就可以编译通过
                 // 这侧面印证了，类模板的成员函数创建是在执行的时候创建的
    {
        cout << obj.show___________________() << endl;
    }
};
void test01()
{
    Person<string> p1("李德康", 18); // 类模板没有自动类型推导的方式，只能使用显示指定类型<string, int>
    cout << p1.show_Name() << "   " << p1.show_Age() << endl;
    Person<int, int> p2('t', 12);
    cout << p2.show_Name() << "  " << p2.show_Age() << endl;
}
void test02()
{
    Person<string> p1("李德康", 18);
    MyClass<Person<string, int>> c1;
    c1.func1();
    c1.func2();
}
void test03()
{
    Person<string, int> p1("孙悟空", 500);
    Person<string, int> p2("猪八戒", 300);
    Person<string, int> p3("唐僧", 30);
    // printPerson(p1);
    // printPerson<>(p2);
    printPerson(p3);
}
int main()
{
    // test01();
    // test02();
    test03();
    system("pause");
    return 1;
}