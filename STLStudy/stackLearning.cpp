// #include <iostream>
// #include <string>
// #include <time.h>
// #include <deque>
// #include <vector>
// #include <stack>
// #include <queue>
// #include <cstdlib>
// #include <algorithm>
// #include <cmath>
// #include "C:\Users\Administrator\Desktop\project-C++\CPPlearning\TemplateLearning\example.hpp"
// using namespace std;

// void test01()
// {
//     stack<EXM::Person> stk; // 先进后出，底部不可访问  无迭代器
//     stk.push(EXM::Person("张三", 10, 110));
//     stk.push(EXM::Person("李四", 14, 140));
//     stk.push(EXM::Person("王五", 23, 140));
//     stk.push(EXM::Person("赵六", 30, 130));
//     while (!stk.empty())
//     {
//         cout << stk.top() << endl; // .top()为可以修改的左值引用
//         stk.pop();
//     }
// }
// void test02()
// {
//     queue<EXM::Person> q; // 先进先出，首部和尾部可以访问，中间部分不可以 无迭代器
//     q.push(EXM::Person("张三", 10, 110));
//     q.push(EXM::Person("李四", 14, 140));
//     q.push(EXM::Person("王五", 23, 140));
//     q.push(EXM::Person("赵六", 30, 130));
//     queue<EXM::Person> q1(q);
//     queue<EXM::Person> q2;
//     q2 = q;
//     cout << q.size() << endl;
//     while (!q.empty())
//     {
//         cout << q.front() << endl; // .top()为可以修改的左值引用
//         q.pop();
//     }
// }
// int main()
// {
//     clock_t start_time, end_time;
//     start_time = clock(); // 获取开始执行时间
//     test01();
//     test02();
//     system("pause");
//     end_time = clock();
//     double Times = (double)(end_time - start_time);
//     return 0;
// }