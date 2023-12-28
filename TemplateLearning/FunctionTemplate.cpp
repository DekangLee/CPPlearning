// #include <iostream>
// #include <string>
// using namespace std;
// // 函数模板
// // 两个整型交换函数
// void swapInt(int &a, int &b)
// {
//     int temp;
//     temp = a;
//     a = b;
//     b = temp;
// }
// // 交换两个浮点数
// void swapDouble(double &a, double &b)
// {
//     double temp;
//     temp = a;
//     a = b;
//     b = temp;
// }
// template <typename T> // 告诉编译器T为通用数据类型
// void mySwap(T &a, T &b)
// {
//     T temp;
//     temp = a;
//     a = b;
//     b = temp;
// }
// template<class T>
// void fun()
// {
//     cout<<"fun调用"<<endl;;
// }
// void test01()
// {
//     // 利用函数模板实现两个数交换
//     int a = 10;
//     int b = 20;
//     // 第一种 自动类型推导
//     // mySwap(a, b);

//     // 显式指定类型
//     mySwap<int>(a, b);
//     cout << "a=" << a << endl;
//     cout << "b=" << b << endl;
// }
// void test02()
// {
//     fun<int>();
// }
// int main()
// {
//     // test01();
//     test02();
//     system("pause");
//     return 0;
// }