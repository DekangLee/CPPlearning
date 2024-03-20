/*
 * @Author: dekangLee dekang579@gmail.com
 * @Date: 2023-12-30 21:28:38
 * @LastEditors: dekangLee dekang579@gmail.com
 * @LastEditTime: 2024-01-02 16:11:00
 * @FilePath: \CPPlearning\TemplateLearning\funcTemplate.cpp
 * @Description:
 *
 * Copyright (c) 2023 by  dekang579@gmail.com, All Rights Reserved.
 */
#include <iostream>
using namespace std;
template <class T>
int work(T *arg)
{
    int num = (int)*arg;
    // int *num =(int*)arg;
    // cout << *num << endl;
    cout << num << endl;
    return 0;
}
class A
{
public:
    int foo(int (*work)())
    {
        func = work;
        return -1;
    }
    void test()
    {
        func();
    }

private:
    static int (*func)();
};
int func1()
{
    cout<<"int func"<<endl;
    return 0;
}
int func2()
{

}
int (*A::func)() = func2;
int main()
{
    // char *ch = new char('a');
    // work(ch);
    A a;
    a.foo(func1);
    a.test();
    // A::foo();

    return 0;
}