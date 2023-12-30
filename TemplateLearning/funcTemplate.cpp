/*
 * @Author: dekangLee dekang579@gmail.com
 * @Date: 2023-12-30 21:28:38
 * @LastEditors: dekangLee dekang579@gmail.com
 * @LastEditTime: 2023-12-30 21:34:50
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
    cout << *num << endl;
    cout << num << endl;
    return 0;
}
int main()
{
    char *ch = new char('a');
    work(ch);
    return 0;
}