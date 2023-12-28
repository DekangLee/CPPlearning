#include <iostream>
#include <string>
using namespace std;
// template <class T>
// void Func1(T param) // 模板函数为值形参
// {
//     cout << "Func1(T param,int)" << endl;
//     param = 2023;
//     cout << param << endl;
// }
template <class T>
void Func1(T &param)
{
    cout << "Func1(T &param)" << endl;
    // param = 20;   函数参数一般不需要修改
    cout << param << endl;
}
// template <class T>
// void Func1(const T param)
// {
//     cout << "Func1(const T param)" << endl;
//     // param = 2021;
//     cout << param << endl;
// }
template <class T>
void Func1(const T &param) // 最佳匹配
{
    cout << "Func1(const T &param)" << endl;
    // param = 2022;
    cout << param << endl;
}
// void Func1(int &param)
// {
//     cout<<"void Func1(int &param)"<<endl;
// }
void valueParam()
{
    int v = 0;
    // const int cv = v;
    const int &rv = v;
    // const char *const cc = "李德康";
    Func1(v);  // 函数模板自动推导 Func(int)
    // Func1(cv);    // 函数模板自动推导 Func(const int)
    Func1(rv);    // 函数模板自动推导 Func(const &int)
    // Func1(cc);    // 函数模板自动推导 Func(cosnt char *cosnt)
    // auto a1 = v;  // auto类型自动推导 a1 为int
    // // auto a2 = cv; // auto类型自动推导 a2 为int
    // a2 = 10;
    // cout << "a2 = " << a2 << endl;
    // auto a3 = rv; // auto类型自动推导 a3 为int
    // a3 = 30;
    // cout << "a3 = " << a3 << endl;
    // auto a4 = cc; // auto类型自动推导 a4 为cosnt char *  // 将可能更改原值的顶层const省略
}

void LRefParam()
{
    int v = 0;
    const int cv = v;
    const int &rv = v;
    const char *cc = "李德康";
    int *const pv = &v;
    Func1(v);     // 函数模板自动推导 Func(int)
    Func1(cv);    // 函数模板自动推导 Func(const int)
    Func1(rv);    // 函数模板自动推导 Func(const &int)
    Func1(cc);    // 函数模板自动推导 Func(cosnt char *cosnt)
    auto a1 = v;  // auto类型自动推导 a1 为int
    auto a2 = cv; // auto类型自动推导 a2 为int
    auto a3 = rv; // auto类型自动推导 a3 为int
    auto a4 = cc; // auto类型自动推导 a4 为cosnt char *cosnt
    auto a5 = pv; //auto类型自动推导 a5 为 int *
    *a5 = 10;
    cout<<"v = "<<v<<endl;
}
int main()
{
    // LRefParam();
    valueParam();
    // char a = 110;
    // cout << sizeof(" ") << endl;
    system("pause");
    return 0;
}