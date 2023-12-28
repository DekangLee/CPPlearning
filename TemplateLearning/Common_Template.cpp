// #include <iostream>
// #include <string>
// using namespace std;
// class Person
// {
// public:
//     int m_a;
//     int operator()() // 仿函数
//     {
//         return m_a;
//     }
//     Person()
//     {
//     }
//     Person(int a)
//     {
//         this->m_a = a;
//     }
//     Person(const Person &p1)
//     {
//         cout << "Person的拷贝构造" << endl;
//         this->m_a = p1.m_a;
//     }
//     Person &operator+(int a) // 加法构造
//     {
//         this->m_a += a;
//         return *this;
//     }
//     Person &operator=(Person &p1)
//     {
//         cout << "这是=运算符重载函数" << endl;
//         this->m_a = p1.m_a;
//         return *this;
//     }
//     bool operator>(Person &p1)
//     {
//         if (this->m_a > p1.m_a)
//             return true;
//         else
//             return false;
//     }
// };
// // bool operator>(const Person &p1, const Person &p2)
// // {
// //     if (p1.m_a > p2.m_a)
// //     {
// //         return true;
// //     }
// //     else
// //         return false;
// // }
// ostream &operator<<(ostream &cout, Person p1)
// {
//     cout << p1.m_a;
//     return cout;
// }
// class Student : public Person
// {
// public:
//     Student(int a)
//     {
//         m_a = a;
//     }
//     int getAge(int a)
//     {
//         return m_a + 1;
//     }
// };
// void Print(int a, int b)
// {
//     cout << "这是普通函数Print(int a, int b)调用" << endl;
// }
// void Print(float a, int b)
// {
//     cout << "这是普通函数Print(float a, int b)调用" << endl;
// }
// void Print(double a, int b)
// {
//     cout << "这是普通函数Print(double a, int b)调用" << endl;
// }
// template <class T>
// void Print(T a, int b, int c)
// {
//     T temp = a + b;

//     cout << "这是函数模板Print(T a, int b,int c)调用" << endl;
// }
// template <class T>
// void Print(T a, int b)
// {
//     T temp = a + b;

//     cout << "这是函数模板Print(T a, int b)调用" << endl;
// }
// // template <class T>
// // T &Compare(T &a, T &b)
// // {
// //     cout << "调用模板函数T &Compare(T &a, T &b)" << endl;
// //     if (a > b)
// //     {
// //         return a;
// //     }
// //     else
// //         return b;
// // }
// template <class T>
// bool Compare(T &a, T &b)
// {
//     if (a == b)
//         return true;
//     else
//         return false;
// }
// // Person &Compare(Person &p1, Person &p2)
// // {
// //     cout << "调用普通函数Person &Compare(Person &p1,Person &p2)" << endl;
// //     return p1 > p2 ? p1 : p2;
// // }
// template <>  // Person具体化的代码
// bool Compare(Person &p1, Person &p2)
// {
//     if (p1.m_a == p2.m_a)
//         return true;
//     else
//         return false;
// }
// void test01()
// {
//     int a = 10;
//     int b = 20;
//     Print(1.1, 1.1);
//     Print(3.2, 1);
// }
// void test02()
// {
//     Person p1(10);
//     Student s1(10);
//     cout << s1.getAge(1) << endl;
// }
// void test03()
// {
//     Person p1(10);
//     Person p2(20);
//     // cout << p2() << endl;
//     cout << Compare(p1, p2) << endl;
//     // Person &p3 = p1;
//     // p3.m_a = 1;
//     cout << Compare(p1, p2) << endl;
// }
// int main()
// {
//     // test01();
//     // test02();
//     test03();
//     system("pause");
//     return 1;
// }