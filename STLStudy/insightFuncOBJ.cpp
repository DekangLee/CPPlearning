// #include <iostream>
// #include <string>
// #include <map>
// #include <vector>
// #include <ctime>
// #include <cstdlib>
// #include <algorithm>
// #include <functional>
// #include "commen.hpp"
// using namespace std;

// // 内建仿函数对象 算术仿函数
// void test01()
// {
//     negate<int> retreat;
//     cout << "20取反:" << retreat(20) << endl;
//     plus<int> myplus;
//     cout << "1+2 = " << myplus(1, 2) << endl;
// }
// // 关系型仿函数
// void test02()
// {
//     vector<int> v;
//     greater<int> Grerter;
//     srand(time(0));
//     for (int i = 0; i < 10; i++)
//     {
//         // srand(time(0));
//         v.push_back(GenNum(0, 10));
//     }
//     print(v);
//     sort(v.begin(), v.end(), Grerter);
//     cout << "------------------" << endl;
//     print(v);
// }
// // 逻辑仿函数
// void test03()
// {
//     logical_not<bool> logNot;
//     vector<bool> v1;
//     v1.push_back(true);
//     v1.push_back(false);
//     v1.push_back(true);
//     v1.push_back(false);
//     print(v1);
//     vector<bool> v2;
//     v2.resize(v1.size());
//     transform(v1.begin(), v1.end(), v2.begin(), logNot);
//     cout<<"-----------------"<<endl;
//     print(v2);
// }
// int myMax(int n, int m)
// {
//     return n>m?n:m;
// }
// int main()
// {
//     clock_t start_time, end_time;
//     start_time = clock(); // 获取开始执行时间
//     // test01();
//     // test02();
//     // test03();
//     // test04();
//     // test05();
//     // test06();
//     // test07();
//     cout<<"3与19之间的最大值是:"<<myMax(3,19)<<endl;
//     end_time = clock();
//     double Times = (double)(end_time - start_time) / CLOCKS_PER_SEC;
//     cout << "程序运行" << Times << "s" << endl;
//     system("pause");
//     return 0;
// }