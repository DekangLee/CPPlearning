// #include <iostream>
// using namespace std;
// #include <string>
// // 加号运算符重载
// class Person
// {
// public:
//     int m_age;
//     int m_hight;
//     string m_name;
//     // 成员函数重载运算符
//     // Person operator +(Person &p)
//     // {
//     //     Person temp_p;
//     //     temp_p.m_age=this->m_age+p.m_age;
//     //     return temp_p;
//     // }
//     // Person()
//     // {
//     //     m_age=10;
//     // }
// };
// // 全局函数重载运算符
// Person operator+(const Person &p1, const Person &p2)
// {
//     Person temp_p;
//     temp_p.m_age = p1.m_age + p2.m_age;
//     return temp_p;
// }
// Person operator+(const Person &p1, const int &age)
// {
//     Person temp_p;
//     temp_p.m_age = p1.m_age + age;
//     return temp_p;
// }
// void test01()
// {
//     Person p1, p2;
//     p1.m_age = 10;
//     p2.m_age = 20;
//     Person p3 = p1 + 10 + 20 + 30;
//     cout << p3.m_age << endl;
// }
// int main()
// {
//     test01();
//     system("pause");
//     return 1;
// }