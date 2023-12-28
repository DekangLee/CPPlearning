// #include <iostream>
// #include <string>
// #include <map>
// #include <vector>
// #include <ctime>
// #include <cstdlib>
// #include <algorithm>
// using namespace std;
// template <class T>
// void print(const T &v)
// {
//     for (auto a : v)
//     {
//         cout << a << " ";
//     }
//     cout << endl;
// }
// // 一元谓词
// class GreaterFive
// {
// public:
//     GreaterFive(){

//     };
//     bool operator()(int val)
//     {
//         return val > 5;
//     }
// };
// class Compare
// {
//     public:
//     bool operator()(int a, int b)
//     {
//         return a>b;
//     }
// };
// void test01()
// {
//     vector<int> v;
//     srand(time(0));
//     for (int i = 0; i < 10; i++)
//     {
//         v.push_back(rand() % 10 + 1);
//     }
//     print(v);
//     vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());
//     if (it == v.end())
//     {
//         cout << "未找到大于5的数" << endl;
//     }
//     else
//         cout << "存在大于5的数" << it - v.begin() << endl;
// }
// void test02()
// {
//     vector<int> v;
//     srand(time(0));
//     for (int i = 0; i < 10; i++)
//     {
//         v.push_back(rand() % 10 + 1);
//     }
//     print(v);
//     sort(v.begin(), v.end()); // 默认从小到大
//     cout << "排序后---------" << endl;
//     print(v);
//     cout<<"-------------"<<endl;
//     sort(v.begin(), v.end(),Compare());
//     print(v);
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