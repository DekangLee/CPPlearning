// /*
//  * @Author: dekangLee dekang579@gmail.com
//  * @Date: 2024-06-07 15:16:52
//  * @LastEditors: dekangLee dekang579@gmail.com
//  * @LastEditTime: 2024-06-07 15:46:06
//  * @FilePath: \CPPlearning\NewFeature\test2.cpp
//  * @Description:
//  *
//  * Copyright (c) 2024 by  dekang579@gmail.com, All Rights Reserved.
//  */
// #include <iostream>
// using namespace std;
// template <typename T>
// void printValue(T &t)
// {
//     cout << "l-value" << endl;
// }
// template <typename T>
// void printValue(T &&t)
// {
//     cout << "r-value" << endl;
// }
// template <typename T>
// void testForword(T &&v)
// {
//     printValue(v);
//     printValue(move(v));
//     printValue(forward<T>(v));
// }
// // forward<T>(t)
// // 1.当T为左值引用类型时，t将被转换为左值
// // 2.当T不是左值引用类型时，t将被转换为右值。
// int main()
// {
//     testForword(100);
//     int b = 0;
//     auto &&a = 100;
//     auto &&c = b;
//     cout << endl;
//     testForword(b);
//     cout << endl;
//     testForword(forward<int>(b));
//     cout << endl;
//     testForword(forward<int &>(b));
//     cout << endl;
//     testForword(forward<int &&>(b));
//     return 0;
// }