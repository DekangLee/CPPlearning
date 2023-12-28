// #include <iostream>
// #include <string>
// using namespace std;
// // 函数重载   无论哪种重载情况绝对不能有二义性！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
// // const关键字与引用&增大参数匹配范围，比如const class &p 可以为“常数”与class &p区别 ，但无法与 class p 区别
// void func()
// {
//     cout << "func" << endl;
// }
// void func(int q) // 有参与无参可以发生重载
// {
//     cout << "func(int)" << endl;
// }
// void func(int a, int)
// {
//     cout << "func(int , int占位符)" << endl;
// }
// void func2(int a, int b = 1)
// {
//     cout << "func2(int , int)" << endl;
// }
// void func2(int a) // 参数的个数不同可以发生重载
// {
//     cout << "func2(int)" << endl;
// }
// // void func1(int &a) // 引用作为函数重载
// // {
// //     cout << "this is func1(int &a)" << endl;
// // }
// // 值传递与引用传递不能发生函数重载
// // void func1(int a)
// // {
// //     cout << "this is func1(int a)" << endl;
// // }
// void func1(int *a) // 地址传递作为函数重载
// {
//     cout << "this is func1(int *a)" << endl;
// }
// // void func1(const int &a)
// // {
// //     cout << "this is func1(const int &a)" << endl;
// // }
// // 与void func1(const int &a)，和void func1(int a)形参列表一致会发生重载重复报错！！！！
// void func1(const int a)
// {
//     cout << "this is func1(const int a)" << endl;
// }
// void func3(int a, int b)
// {
//     cout<<"a:"<<a<<endl;
//     cout<<"b:"<<b<<endl;
//     cout << "this is func3(int a, int b)" << endl;
// }
// void func3(float a, float b)
// {
//     cout << "this is func3(float a, float b)" << endl;
// }
// void test01()
// {
//     int a = 10;
//     int b = 9;
//     func1(b);
//     // func3(1.2, 1.2); // 发生发错误 1.2 字面量会被转成double数据类型
//     func3(1, -1.4); // 会发生func3(int a, int b)重载
// }
// int main()
// {
//     test01();
//     // func2(1,1);
//     // int a=10;
//     // int &b=a;

//     // func1(1);

//     system("pause");
//     return 1;
// }