// #include <iostream>
// #include <string>
// #include <map>
// #include <vector>
// #include <ctime>
// #include <cstdlib>
// #include <algorithm> // 包含头文件
// #include <functional>
// #include "commen.hpp"
// class Print
// {
// public:
//     void operator()(int a)
//     {
//         cout << a << " ";
//     }
// };
// class Transform
// {
// public:
//     int operator()(int a)
//     {
//         if (a > 10)
//         {
//             return 10;
//         }
//         else
//             return a;
//     }
// };
// // 常用遍历算法for_each()
// void test01()
// {
//     auto _fprint = [](int val)
//     {
//         cout << val << " ";
//     };
//     vector<int> v = {4, 2, 1, 8, 3, 6, 8, 10, 23};
//     // for_each(v.begin(),v.end(),_fprint);
//     for_each(v.begin(), v.end(), Print());
//     cout << endl;
// }
// // 常用遍历算法transform
// void test02()
// {
//     vector<int> v = {3, 9, 10, 2, 39, 18, 34, 12, 31};
//     vector<int> Target_v;
//     Target_v.resize(v.size());  // 这里需要注意，需要先给目标容器分配空间
//     transform(v.begin(), v.end(), Target_v.begin(), Transform());  // 可以通过Transform指定规则
//     for_each(Target_v.begin(), Target_v.end(), Print());
// }
// int main()
// {
//     clock_t start_time, end_time;
//     start_time = clock(); // 获取开始执行时间
//     // test01();
//     test02();
//     // test03();
//     // test04();
//     // test05();
//     // test06();
//     // test07();
//     end_time = clock();
//     double Times = (double)(end_time - start_time) / CLOCKS_PER_SEC;
//     cout << "程序运行" << Times << "s" << endl;
//     system("pause");
//     return 0;
// }