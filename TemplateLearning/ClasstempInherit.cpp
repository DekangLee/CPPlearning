// #include <iostream>
// #include <string>
// #include <time.h>
// #include <cstdlib>
// using namespace std;
// template <class T>
// class Base;
// template <class T1, class T2> // 如果不想指定数据类型可以将子类变成类模板
// class Son1;
// template <class T>
// class Base
// {
//     friend class Son;
//     friend void test01();
//     // friend Son1<>;
//    template<class T1,class T2> friend class Son1; // 如果不想指定数据类型可以将子类变成类模板

// private:
//     Base()
//     {
//     }
//     Base(T a)
//     {
//         this->m_a = a;
//     }
//     T m_a;
// };
// class Son : public Base<int> // 必须指定父类模板参数类型
// {
//     friend void test01();

// private:
//     Son(int a)
//     {
//         m_a = a;
//     }
// };
// template <class T1, class T2> // 如果不想指定数据类型可以将子类变成类模板
// class Son1 : public Base<T2>
// {
// public:
//     Son1(T1 a)
//     {
//         m_a = a;
//     }
//     T1 m_a;
// };
// template <class Nametype = string, class Agetype = int>
// class Person
// {
// public:
//     Person();
//     Person(Nametype name, Agetype age);
//     void show_Person();
//     Agetype show_Age()
//     {
//         return m_age;
//     }
//     Nametype show_Name()
//     {
//         return m_name;
//     }
//     Nametype m_name;
//     Agetype m_age;
// };
// template <class Nametype, class Agetype>
// Person<Nametype, Agetype>::Person()
// {
//     m_age = 108;
//     m_name = "白文超";
// }
// template <class Nametype, class Agetype>
// Person<Nametype, Agetype>::Person(Nametype name, Agetype age) // 类模板中可以使用默认参数
// {
//     this->m_age = age;
//     this->m_name = name;
// }
// template <class Nametype, class Agetype>
// void Person<Nametype, Agetype>::show_Person()
// {
//     cout << "Name:" << m_name << " Age:" << m_age << endl;
// }
// void test01()
// {
//     Son s1(10);
//     cout << s1.m_a << endl;
//     Son1<int, float> s2(11);
//     cout << s2.Base::m_a << endl;
// }
// void test02()
// {
//     Person<> p1;
//     p1.show_Person();
// }
// int main()
// {
//     clock_t start_time, end_time;
//     start_time = clock(); // 获取开始执行时间
//     test01();
//     // test02();
//     end_time = clock();
//     double Times = (double)(end_time - start_time) / CLOCKS_PER_SEC;
//     cout << "程序运行时间：" << Times << "s" << endl;
//     system("pause");

//     return 1;
// }