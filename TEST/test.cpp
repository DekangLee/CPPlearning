/*
 * @Author: dekangLee dekang579@gmail.com
 * @Date: 2024-03-20 14:07:25
 * @LastEditors: dekangLee dekang579@gmail.com
 * @LastEditTime: 2024-03-20 14:21:37
 * @FilePath: \CPPlearning\TEST\test.cpp
 * @Description:
 *
 * Copyright (c) 2024 by  dekang579@gmail.com, All Rights Reserved.
 */
#include <iostream>
#include <string>
using namespace std;
int main()
{
    // 这个测试说明了cin输入char *arr时会把该数组之前的内容清空
    char buff[1024];
    cin >> buff;
    cout << buff << endl;
    cin >> buff;
    cout << buff << endl;
    string str;
    str = "lall";
    cout << str << endl;
    return 0;
}