/*
 * @Author: dekangLee dekang579@gmail.com
 * @Date: 2023-12-29 08:56:05
 * @LastEditors: dekangLee dekang579@gmail.com
 * @LastEditTime: 2024-03-14 14:45:41
 * @FilePath: \CPPlearning\Function_overloading\functionPoint.cpp
 * @Description: 
 * 
 * Copyright (c) 2024 by  dekang579@gmail.com, All Rights Reserved. 
 */
#include <stdio.h>
#include <iostream>
int Max(int, int); // 函数声明
double add(double a, double b);
double mins(double a, double b);
double multi(double a, double b);
double divide(double a, double b);
double caculate(double a, double b, double (*cal)(double, double));
int main(void)
{
    // int (*p)(int, int); // 定义一个函数指针
    // int a, b, c;
    // p = Max; // 把函数Max赋给指针变量p, 使p指向Max函数
    // printf("please enter a and b:");
    // scanf("%d%d", &a, &b);
    // c = (*p)(a, b); // 通过函数指针调用Max函数
    // printf("a = %d\nb = %d\nmax = %d\n", a, b, c);
    double (*a)(double,double) = add;
    std::cout<<caculate(1.0,2.0,multi)<<std::endl;
    return 0;
}
int Max(int x, int y) // 定义Max函数
{
    int z;
    if (x > y)
    {
        z = x;
    }
    else
    {
        z = y;
    }
    return z;
}
double add(double a, double b)
{
    return a + b;
}
double mins(double a, double b)
{
    return a - b;
}
double multi(double a, double b)
{
    return a * b;
}
double divide(double a, double b)
{
    return a / b;
}
double caculate(double a, double b, double (*cal)(double, double))
{
    return cal(a, b);
}
