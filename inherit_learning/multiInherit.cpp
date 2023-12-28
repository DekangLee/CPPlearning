// #include <iostream>
// #include <string>
// using namespace std;
// class Base1
// {
//     // friend void test01();

// public:
//     friend void test05();
//     int m_A;
//     static int m_D;
//     Base1()
//     {
//         m_A = 200;
//         cout << "Base1的默认构造函数" << endl;
//     }
//     Base1(int a) : m_A(10)
//     {
//         // cout << "Base1的有参构造函数" << endl;
//     }
//     ~Base1()
//     {
//         cout << "Base1的析构函数" << endl;
//     }
//     void func()
//     {
//         cout << "Base1的成员函数func()调用" << endl;
//     }
//     void func(int a)
//     {
//         cout << "Base1的成员函数func(int a)调用" << endl;
//     }

// private:
//     static void func1()
//     {
//         cout << "Base1----->static void func1()" << endl;
//     }

// protected:
//     int m_B;

// private:
//     int m_C;
// };
// int Base1::m_D = 21;
// class Base2
// {
// public:
//     // friend void test05();
//     int m_A;
//     static int m_D;
//     Base2()
//     {
//         m_A = 200;
//         cout << "Base2的默认构造函数" << endl;
//     }
//     Base2(int a) : m_A(10)
//     {
//         // cout << "Base2的有参构造函数" << endl;
//     }
//     ~Base2()
//     {
//         cout << "Base2的析构函数" << endl;
//     }
//     void func()
//     {
//         cout << "Base1的成员函数func()调用" << endl;
//     }
//     void func(int a)
//     {
//         cout << "Base1的成员函数func(int a)调用" << endl;
//     }

// private:
//     static void func1()
//     {
//         cout << "Base1----->static void func1()" << endl;
//     }

// protected:
//     int m_B;

// private:
//     int m_C;
// };
// int Base2::m_D = 22;
// class  Son : public Base1, public Base2
// {
// private:
//     /* data */
// public:
// // int m_A =20;
   
// };

// void test01()
// {
//   Son s;
//   s.Base1::m_A =31;
//   cout<<"size of s ="<<sizeof(Son)<<endl;
// }
// int main()
// {
//     test01();
//     system("pause");
//     return 1;
// }