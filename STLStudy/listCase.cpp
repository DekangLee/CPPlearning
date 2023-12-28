// #include <iostream>
// #include <string>
// #include <list>
// #include <time.h>
// #include <cstdlib>
// #include <algorithm>
// #include "C:\Users\Administrator\Desktop\project-C++\CPPlearning\TemplateLearning\example.hpp"
// void test01()
// {
//     list<EXM::Person> L1;
//     L1.push_back(EXM::Person("李德康", 18, 185));
//     L1.push_back(EXM::Person("白文超", 80, 185));
//     L1.push_back(EXM::Person("胡文杰", 20, 165));
//     L1.push_back(EXM::Person("唐家胜", 30, 165));
//     L1.push_back(EXM::Person("杨嘉琦", 40, 165));
//     L1.emplace_back("牟小牛", 23, 150);
//     print(L1);
//     auto comparePerson = [](EXM::Person &p1, EXM::Person &p2)
//     {
//         if (p1.GetHight() < p2.GetHight())
//             return true;
//         else if (p1.GetHight() == p2.GetHight())
//         {
//             if (p1.GetAge() > p2.GetAge())
//                 return true;
//             else
//                 return false;
//         }
//         else
//             return false;
//     };
//     L1.sort(comparePerson); // 对于自定义数据类型我们需要指定排序规则
//     cout << "排序后------------------------------" << endl;
//     print(L1);
//     list<EXM::Person> L2(L1);
//     list<EXM::Person>L3;
//     L3 = L1;
// }
// int main()
// {
//     clock_t start_time, end_time;
//     start_time = clock(); // 获取开始执行时间
//     test01();
//     // test02();
//     // test03();
//     // test04();
//     // test05();
//     // test06();
//     // test07();
//     // test08();
//     // CompCase();
//     system("pause");
//     end_time = clock();
//     double Times = (double)(end_time - start_time);
//     return 0;
// }