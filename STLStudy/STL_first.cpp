// #include <iostream>
// #include <string>
// #include <time.h>
// #include <cstdlib>
// #include <vector>
// #include <algorithm>
// #include "C:\Users\Administrator\Desktop\project-C++\test\TemplateLearning\example.hpp"
// using namespace std;
// void test01()
// {
//     vector<int> v1;
//     v1.push_back(10);
//     v1.push_back(20);
//     v1.push_back(30);
//     v1.push_back(40);
//     v1.push_back(50);
//     // vector<int>::iterator itbegin = v1.begin(); // 创建起始迭代器 指向v1的第一个元素
//     // vector<int>::iterator itend = v1.end();     // 创建结束迭代器 指向v1最后一个元素的下一个元素
//     // while (itbegin != itend)
//     // {
//     //     cout << *itbegin << endl; // 注意需要解引用操作
//     //     itbegin++;
//     // }
//     // 第二种遍历方式，可以根据标准算法库的方法
//     for_each(v1.begin(), v1.end(), print<int>);
// }
// void test02()
// {
//     vector<EXM::Person> vp;
//     vp.push_back(EXM::Person("李德康", 18, 185));
//     vp.push_back(EXM::Person("白文超", 20, 175));
//     vp.push_back(EXM::Person("唐家胜", 30, 160));
//     vp.push_back(EXM::Person("胡文杰", 40, 150));
//     vp.push_back(EXM::Person("杨嘉琦", 50, 140));
//     // for(vector<EXM::Person>::iterator it = vp.begin();it!=vp.end();it++)
//     // {
//     //     cout<<"姓名:"<<it->GetName()<<" 年龄:"<<it->GetAge()<<" 身高:"<<it->GetHight()<<endl;
//     // }
//     for_each(vp.begin(), vp.end(), print<EXM::Person>);
// }
// void test03()
// {
//     vector<EXM::Person *> vp;
//     EXM::Person p1("李德康", 18, 185);
//     EXM::Person p2("白文超", 20, 175);
//     EXM::Person p3("唐家胜", 30, 160);
//     EXM::Person p4("胡文杰", 40, 150);
//     vp.push_back(&p1);
//     vp.push_back(&p2);
//     vp.push_back(&p3);
//     vp.push_back(&p4);
//     for (vector<EXM::Person *>::iterator it = vp.begin(); it != vp.end(); it++)
//     {
//         cout << **it << endl;
//     }
// }
// int main()
// {
//     clock_t start_time, end_time;
//     start_time = clock(); // 获取开始执行时间
//     // test01();
//     // test02();
//     test03();
//     system("pause");
//     end_time = clock();
//     double Times = (double)(end_time - start_time);
//     return 0;
// }