// #include <iostream>
// using namespace std;
// #include <string>
// class person
// {
// private:
//     /* data */
// public:
//     static int m_A;
//     int m_B;
//     const int m_C = 10;
//     static void fun1()
//     {
//         m_A=9;
//         cout<<"静态成员函数"<<endl;
//     }
//     person(/* args */)
//     {
//     }
//     ~person()
//     {
//     }
// };
// int person::m_A = 200; // 类内声明，类外初始化
// void test01()
// {
//     person p1;
    
//     cout << p1.m_A << endl;
//     p1.m_A = 100;
//     person p2;
//     cout << p2.m_B<< endl;
// }
// void test02()
// {
//     person::fun1();  // 静态成员函数可以使用类名调用，并且只能使用静态成员变量
//     cout<<person::m_A<<endl;
// }
// int main()
// {
//     // test01();
//     test02();
//     cout<<sizeof(person)<<endl; // 静态成员变量不在对象中存储

//     system("pause");
//     return 1;
// }