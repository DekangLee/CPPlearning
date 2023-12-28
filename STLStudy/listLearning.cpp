// #include <iostream>
// #include <fstream>
// #include <string>
// #include <time.h>
// #include <cstdlib>
// #include <vector>
// #include <list>
// #include <algorithm>
// using namespace std;
// class compare
// {
// public:
//     // auto operator()(int a, int b)
//     // {
//     //     return a > b;
//     // }
//     decltype(1>2) operator()(int a, int b)
//     {
//         return a > b;
//     }
// };
// template <class T>
// void print(const T &obj)
// {
//     for (auto a : obj)
//     {
//         cout << a << "\t";
//     }
//     cout << endl;
// }
// void print(const list<int> &obj)
// {
//     for (list<int>::const_iterator it = obj.begin(); it != obj.end(); it++)
//     {
//         cout << *it << "\t";
//     }
//     cout << endl;
// }
// void test01()
// {
//     list<int> list1;
//     for (int i = 0; i < 10; i++)
//     {
//         list1.push_back(rand() % 20);
//     }
//     print(list1);
//     list<int> list2(++list1.begin(), --list1.end());
//     print(list2);
// }
// void test02()
// {
//     list<int> list1;
//     list1.resize(20); // 这里与vector一样push_back会补上0元素的位置
//     cout << "list1 size = " << list1.size() << endl;
//     for (int i = 0; i < 10; i++)
//     {
//         list1.push_back(rand() % 20);
//     }
//     print(list1);
//     cout << "list1 size = " << list1.size() << endl;
// }
// void test03()
// {
//     list<int> list1;
//     for (int i = 0; i < 5; i++)
//     {
//         list1.push_back(rand() % 20 + 25);
//     }
//     print(list1);
//     list<int>::iterator it = list1.begin();
//     list1.insert(++it, 2);
//     print(list1);
//     list1.erase(--it);
//     print(list1);
//     list1.remove(30); // 没有返回值，会删除所有匹配到的值
//     print(list1);
// }
// void test04()
// {
//     list<int> list1;
//     for (int i = 0; i < 5; i++)
//     {
//         list1.push_back(rand() % 20 + 25);
//     }
//     cout << "list1反转前：" << endl;
//     print(list1);
//     list1.reverse();
//     cout << "list1反转后：" << endl;
//     print(list1);
//     list1.sort(); // list容器内提供排序算法，默认升序排列，事实上不支持随机访问的容器都不能直接用全局函数sort()排序
//     auto _f = [](int a, int b)
//     { return a > b; };
//     // list1.sort(_f); // lambda表达式
//     list1.sort(compare());
//     print(list1);
//     cout << _f(1, 4) << endl;
// }
// int main()
// {
//     clock_t start_time, end_time;
//     start_time = clock(); // 获取开始执行时间
//     // test01();
//     // test02();
//     // test03();
//     // test04();

//     system("pause");
//     end_time = clock();
//     double Times = (double)(end_time - start_time);
//     return 0;
// }