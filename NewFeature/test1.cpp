// /*
//  * @Author: dekangLee dekang579@gmail.com
//  * @Date: 2024-05-21 09:56:36
//  * @LastEditors: dekangLee dekang579@gmail.com
//  * @LastEditTime: 2024-06-07 15:07:11
//  * @FilePath: \CPPlearning\NewFeature\test1.cpp
//  * @Description:
//  *
//  * Copyright (c) 2024 by  dekang579@gmail.com, All Rights Reserved.
//  */
// #include <iostream>
// class myClass
// {
// public:
//     myClass()
//     {
//         this->a = new int(0);
//         this->c = 0;
//         std::cout << "myClass()" << std::endl;
//     }
//     myClass(myClass &a)
//     {
//         this->c = a.c;
//         this->a = new int(*(a.a));
//         std::cout << "myClass(myClass &a)" << std::endl;
//     }
//     myClass(const myClass &a)
//     {
//         this->c = a.c;
//         this->a = new int(*a.a);
//         std::cout << "myClass(const myClass &a)" << std::endl;
//     }
//     myClass(myClass &&b)
//     {
//         this->c = b.c;
//         this->a = b.a;
//         b.a = nullptr;
//         b.c = -100;
//         std::cout << "myClass(myClass &&b)" << std::endl;
//     }

//     myClass(int &c)
//     {
//         this->c = c;
//         this->a = new int(0);
//         std::cout << "myClass(int &c)" << std::endl;
//     }
//     myClass(const int &c)
//     {
//         this->c = c;
//         this->a = new int(0);
//         std::cout << "myClass(const int &c)" << std::endl;
//     }
//     explicit myClass(int &&c)
//     {
//         this->c = c;
//         this->a = new int(0);
//         std::cout << " myClass(int &&c)" << std::endl;
//     }
//     myClass(const int &&c)
//     {
//         this->c = c;
//         this->a = new int(0);
//         std::cout << "myClass(const int &&c)" << std::endl;
//     }
//     ~myClass()
//     {
//         if (this->a != nullptr)
//             delete a;
//     }
//     int c;
//     int *a = nullptr;
// };
// myClass func()
// {
//     myClass t(1);
//     return t;
// }
// void test(myClass &a)
// {
//     std::cout << "传入参数是左值" << std::endl;
// }
// void test(myClass &&a)
// {
//     std::cout << "传入参数是右值" << std::endl;
// }
// template <class T>
// void f(T &&parma);
// template <class T>
// void f1(const T &&parma) // const 限定直接被推导成const右值引用
// {

// }
// class TEST
// {
// public:
//     int i;
//     int j;
//     TEST(int thei, int thej):i(thei),j(thej){};
//     TEST(TEST && t)
//     {
//         std::cout <<"TEST移动构造函数" <<std::endl;
//     }
// };
// TEST foo()
// {
//     TEST t(1,3);
//     return t;
// }
// int main()
// {
//     // 左值
//     int a = 9;
//     // 左值引用
//     int &b = a;
//     // 右值
//     8;
//     // 右值引用
//     int &&c = 8;
//     // 常量左值引用
//     const int &d = 9;
//     // 常量右值引用
//     const int &&e = 9;
//     // myClass classA(1);
//     // myClass classB(std::move(func()));
//     // myClass classC = func();
//     // cout << endl;
//     // myClass &&classD = std::move(classC);
//     // classD.c = 100;
//     // std::cout << classC.c << std::endl;
//     // test(func());
//     // test(classD);
//     // auto && f = c;
//     TEST t = std::move(foo());
// }