// #include <iostream>
// #include <string>
// #include <time.h>
// #include <deque>
// #include <vector>
// #include <cstdlib>
// #include <algorithm>
// #include <cmath>
// #include "C:\Users\Administrator\Desktop\project-C++\test\TemplateLearning\example.hpp"
// const int NUMBER = 5;
// const int CRITICS = 10;
// template <class T>
// void print(deque<T> d)
// {
//     for (auto a : d)
//     {
//         cout << a << "\t";
//     }
//     cout << endl;
// }
// class Person
// {
// public:
//     Person(string name, int score)
//     {
//         m_name = name;
//         m_score = score;
//     }
//     string m_name;
//     float m_score;
// };
// ostream &operator<<(ostream &cout, Person p)
// {
//     cout << "name:" << p.m_name << " score:" << p.m_score << endl;
//     return cout;
// }
// void CreatePerson(vector<Person> &v)
// {
//     string NameSeed = "ABCDE";
//     for (int i = 0; i < NUMBER; i++)
//     {
//         string name = "选手"; // 字符常量是不可以与char c直接用+拼接的
//         name += NameSeed[i];
//         v.emplace_back(name, EXM::GenerateNum<float>(0, 10));
//     }
// }
// void setScore(vector<Person> &v_p)
// {
//     // 将评委的分数放入deque中

//     for (auto &a : v_p)
//     {
//         deque<int> d_score;
//         for (int i = 0; i < CRITICS; i++)
//         {
//             int score = rand() % 41 + 60;
//             d_score.push_back(score);
//         }
//         sort(d_score.begin(), d_score.end());
//         print(d_score);
//         d_score.pop_back();
//         d_score.pop_front();  // 需要注意这里用deque的原因为vector没有pop_front()
//         int sum = 0;
//         for (auto a : d_score)
//         {
//             sum += a;
//         }
//         auto temp = static_cast<float>(sum) / d_score.size();
//         a.m_score = round(temp * 10) / 10;
//     }
// }
// void test01()
// {
//     vector<Person> v_p;
//     CreatePerson(v_p);
//     print(v_p);
//     setScore(v_p);
//     print(v_p);
// }
// int main()
// {
//     clock_t start_time, end_time;
//     start_time = clock(); // 获取开始执行时间
//     test01();
//     string NmaeSeed = "ABCDE";
//     cout << ("选手：" + NmaeSeed[0]) << endl;
//     system("pause");
//     end_time = clock();
//     double Times = (double)(end_time - start_time);
//     return 0;
// }