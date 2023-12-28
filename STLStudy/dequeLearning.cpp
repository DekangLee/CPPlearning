// #include <iostream>
// #include <string>
// #include <time.h>
// #include <deque>
// #include <vector>
// #include <cstdlib>
// #include <algorithm>
// #include "C:\Users\Administrator\Desktop\project-C++\test\TemplateLearning\example.hpp"
// using namespace std;
// class data
// {
//     friend ostream &operator<<(ostream &cout, const data &d);
//     // friend ostream &operator<<(ostream &cout, data &d);
//     int m_a = 0;
//     int m_b = 0;

// public:
//     data(int a, int b) : m_a(a), m_b(b){};
// };
// ostream &operator<<(ostream &cout, const data &d)
// {
//     cout << d.m_a << " " << d.m_b << endl;
//     return cout;
// }
// // ostream &operator<<(ostream &cout, data &d)
// // {
// //     cout << d.m_a << " " << d.m_b << endl;
// //     return cout;
// // }
// void test01()
// {
//     deque<int> d1;
//     cout << "d1.size = " << d1.size() << endl;
//     cout << "d1.max_size = " << d1.max_size() << endl;
//     for (int i = 0; i < 10; i++)
//     {
//         d1.push_back(EXM::GenerateNum<int>(0, 20)); // push_back()方法与vector一致，尾部插入
//     }
//     cout << "d1.size = " << d1.size() << endl;
//     cout << "d1.max_size = " << d1.max_size() << endl;
//     print(d1);
//     d1.clear();
//     cout << "d1.size = " << d1.size() << endl;
//     cout << "d1.max_size = " << d1.max_size() << endl;
//     for (int i = 0; i < 10; i++)
//     {
//         d1.push_front(i); // push_fornt()vector不存在该方法
//     }
//     print(d1);
//     deque<int> d2(d1); // 拷贝构造
//     print(d2);         //
// }
// void test02()
// {
//     deque<int> d1;
//     d1.push_front(10);
//     d1.at(0) = 1; // 该值时可以修改的左值（引用）
//     string s = " ";
//     s.at(0) = '1'; //   与deque一致返回值为可修改的左值
//     print(d1);
// }
// void test03()
// {
//     deque<int> d1;
//     for (int i = 0; i < 5; i++)
//     {
//         d1.push_back(EXM::GenerateNum<int>(2, 30));
//     }
//     if (d1.empty())
//     {
//         cout << "deque为空" << endl;
//     }
//     else
//         cout << "deque不为空" << endl;
//     deque<data> d2;
//     d2.emplace_back(1, 3); // emplace_back与push的区别在于前者可以不用将元素构造出来，直接用emplace_back(elem1,elem2)
//     print(d2);
//     cout << data(4, 5) << endl;
// }
// // 插入数据
// void test04()
// {
//     deque<int> d;
//     int count = 0;
//     int *p = nullptr;
//     for (int i = 0; i < 10000; i++)
//     {
//         d.push_back(1);
//         if (p != &d[0])
//         {
//             p = &d[0];
//             count++;
//         }
//     }
//     cout << count << endl;
//     d.clear();
//     d.resize(20); // resize()之后，再进行push_back()直接在尾部插入，与vector向前补齐不同
//     print(d);
//     for (int i = 0; i < 9; i++)
//     {
//         d.push_back(i);
//     }
//     print(d);
//     d.clear();
//     d.insert(d.begin(), 1); // 与vector一样，第一个参数为迭代器
//     print(d);
// }
// void test05()
// {
//     deque<int> d;
//     for (int i = 0; i < 5; i++)
//     {
//         d.push_back(EXM::GenerateNum<int>(2, 30));
//     }
//     // const deque<int> d1 = d;
//     print(d);
//     // d.pop_back();
//     // for (deque<int>::const_iterator it = d1.begin(); it != d1.end(); it++)
//     // {
//     //     cout << *it << endl;
//     // }
//     d.front() = 20; // 可更改的引用（左值）
//     print(d);
// }
// // deque容器的排序
// void test06()
// {
//     deque<int> d;
//     vector<float> v;
//     for (int i = 0; i < 10; i++)
//     {
//         d.push_back(EXM::GenerateNum<int>(2, 30));
//         v.push_back(EXM::GenerateNum<float>(2, 30));
//     }
//     cout << "排序前：" << endl;
//     print(d);
//     print(v);
//     sort(d.begin(), d.end()); // sort 算法默认升序  函数原型sort(_RandomAccessIterator __first, _RandomAccessIterator __last)
//                               // 这里注意到需要支持随机访问的容器才能使用
//     sort(v.begin() + 2, v.end());   //(v.begin() + 2, v.end())可以用来指定容器需要排序的区间
//     cout << "排序后" << endl;
//     print(d);
//     print(v);
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
//     test06();
//     // test07();
//     // test08();
//     system("pause");
//     end_time = clock();
//     double Times = (double)(end_time - start_time);
//     return 0;
// }