// #include <iostream>
// #include <string>
// #include <set>
// #include <time.h>
// #include <cstdlib>
// #include <algorithm>
// #include "C:\Users\Administrator\Desktop\project-C++\CPPlearning\TemplateLearning\example.hpp"
// pair<string, int> get(string name, int age)
// {
//     pair<string, int> pair1 = make_pair(name, age);
//     return pair1;
// }
// class compare
// {
// public:
//     bool operator()(int first, int second)
//     {
//         return first > second;
//     }
//     bool operator()(const EXM::Person &p1, const EXM::Person &p2)
//     {
//         if (p1.GetAge() > p2.GetAge())
//         {
//             return true;
//         }
//         else if (p1.GetAge() == p2.GetAge())
//         {
//             if (p1.GetHight() > p2.GetHight())
//             {
//                 return true;
//             }
//             else
//                 return false;
//         }
//         else
//             return false;
//     }
// };
// void test01()
// {
//     set<int> set1;
//     set<int> set2;
//     for (int i = 0; i < 100; i++)
//     {
//         set1.insert(EXM::GenerateNum<int>(15, 20)); // 数据默认升序,并且没有重复的值
//         set2.insert(EXM::GenerateNum<int>(10, 15));
//     }
//     printf("set1:\n");
//     print(set1);
//     printf("set2:\n");
//     print(set2);
//     set<int>::iterator it = set1.begin();
//     cout << *(++it) << endl;
//     if (set1.find(18) == set1.end()) // find的返回值为迭代器，如果不存在则为.end()
//     {
//         cout << "不存在该元素" << endl;
//     }
//     else
//         cout << *set1.find(1) << endl;
//     set1.swap(set2); // 容器互换
//     printf("set1:\n");
//     print(set1);
//     printf("set2:\n");
//     print(set2);
// }
// // set的删除操作
// void test02()
// {
//     set<int> set1;
//     for (int i = 0; i < 10; i++)
//     {
//         set1.insert(EXM::GenerateNum<int>(1, 20));
//     }
//     print(set1);
//     cout << "-------------------" << endl;
//     set1.erase(++set1.begin());
//     print(set1);
//     // 重载版本
//     cout << "-------------------" << endl;
//     set1.erase(10);
//     print(set1);
// }
// // set的查找与统计
// void test03()
// {
//     multiset<int> multiset1;
//     set<int> set1;
//     for (int i = 0; i < 10; i++)
//     {
//         multiset1.insert(EXM::GenerateNum<int>(15, 20));
//         set1.insert(EXM::GenerateNum<int>(15, 20));
//     }
//     print(multiset1);
//     printf("multiset1.find(18):");
//     cout << *multiset1.find(18) << endl;
//     printf("set1.find(18):");
//     cout << *set1.find(18) << endl;
//     printf("multiset1.count(15):");
//     printf("%d\n", multiset1.count(15));
//     printf("set1.count(15):");
//     printf("%d\n", set1.count(15)); // 对于set而言统计结果为0/1
// }
// // set与multiset的区别
// void test04()
// {
//     multiset<int> multiset1;
//     set<int> set1;
//     for (int i = 0; i < 20; i++)
//     {
//         multiset1.insert(EXM::GenerateNum<int>(15, 20));
//         set1.insert(EXM::GenerateNum<int>(15, 20));
//     }
//     cout << "set1.size()" << set1.size() << endl;
//     cout << "multiset1.size()" << multiset1.size() << endl;
//     pair<set<int>::iterator, bool> pair1;
//     pair1 = set1.insert(18); // set.insert()有返回值 重复数据插入失败
//     if (pair1.second)
//     {
//         cout << "successfully insert 18" << endl;
//     }
//     else
//         cout << "eorr insert 18" << endl;
// }
// // pair 的创建(不需要包含头文件)
// void test05()
// {
//     pair<string, int> p1("Tom", 20);
//     cout << "Name:" << p1.first << " Age:" << p1.second << endl;
//     pair<string, int> p2 = make_pair("Jerry", 12);
//     cout << "Name:" << p2.first << " Age:" << p2.second << endl;
//     pair<string, int> p3 = get("Spack", 20);
//     cout << "Name:" << p3.first << " Age:" << p3.second << endl;
// }
// // set 容器的排序
// void test06()
// {
//     // set 容器要在insert之前定义排序规则
//     // auto compare = [](int a, int b)
//     // {
//     //     return a > b;
//     // };
//     multiset<int, compare> multiset1;
//     set<int, compare> set1;
//     for (int i = 0; i < 20; i++)
//     {
//         multiset1.insert(EXM::GenerateNum<int>(15, 20));
//         set1.insert(EXM::GenerateNum<int>(15, 20));
//     }
//     printf("multiset1:\n");
//     print(multiset1);
//     printf("set1:\n");
//     print(set1);
// }
// // set 存放自定义数据类型进行排序
// void test07()
// {
//     // auto comparePerson = [](EXM::Person &p1, EXM::Person &p2)
//     // {
//     //     if (p1.GetHight() < p2.GetHight())
//     //         return true;
//     //     else if (p1.GetHight() == p2.GetHight())
//     //     {
//     //         if (p1.GetAge() > p2.GetAge())
//     //             return true;
//     //         else
//     //             return false;
//     //     }
//     //     else
//     //         return false;
//     // };
//     set<EXM::Person, compare> Person_set;  // 经测试这里的compare 必须用类型名，用lambda表达式不行
//     Person_set.insert(EXM::Person("李德康", 18, 185));
//     Person_set.insert(EXM::Person("白文超", 80, 155));
//     Person_set.insert(EXM::Person("胡文杰", 20, 165));
//     Person_set.insert(EXM::Person("唐家胜", 20, 175));
//     Person_set.insert(EXM::Person("杨嘉琦", 40, 165));
//     // Person_set.insert("牟小牛", 23, 150);
//     print(Person_set);
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
//     test07();
//     system("pause");
//     end_time = clock();
//     double Times = (double)(end_time - start_time);
//     return 0;
// }