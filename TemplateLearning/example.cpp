// #include <iostream>
// #include <string>
// #include <time.h>
// #include <cstdlib>
// #include "example.hpp"
// using namespace std;
// const int NUMBER = 5;
// void test01()
// {
//     // myArry<int> arr1(10);
//     int capacity;
//     cin >> capacity;
//     myArry<int> arr2(capacity);
//     for (int i = 0; i < capacity; i++)
//     {
//         arr2.push_back(EXM::GenerateNum<int>(2, 7));
//         // cout<<"arr.Size = "<<arr2.GetSize()<<endl;
//         // cout<<"arr.Capacity = "<<arr2.GetCapacity()<<endl;
//     }
//     // cout<<endl;
//     // for (int i = 0; i < capacity; i++)
//     // {
//     //     arr2.remove();
//     //     cout<<"arr.Size = "<<arr2.GetSize()<<endl;
//     //     cout<<"arr.Capacity = "<<arr2.GetCapacity()<<endl;
//     // }
//     arr2.print();
//     // arr2.remove();
//     // arr2.print();
//     // myArry<int>arr1;
//     // arr1 = arr2;
//     // arr1.print();
//     for (int i = 0; i < arr2.GetSize(); i++)
//     {
//         cout << arr2[i] << endl;
//     }
// }
// void test02()
// {
//     myArry<EXM::Person> C239(NUMBER);
//     C239.push_back(EXM::Person("李德康", 18, 185));
//     C239.push_back(EXM::Person("白文超", 80, 165));
//     C239.push_back(EXM::Person("胡文杰", 20, 165));
//     C239.push_back(EXM::Person("唐家胜", 30, 165));
//     C239.push_back(EXM::Person("杨嘉琦", 40, 165));
//     for_each(C239.begin(), C239.end(), printf);
// }
// void test03()
// {
//     Array<EXM::Person> C239;
//     C239.push_back(EXM::Person("李德康", 18, 185));
//     C239.push_back(EXM::Person("白文超", 80, 165));
//     C239.push_back(EXM::Person("胡文杰", 20, 165));
//     C239.push_back(EXM::Person("唐家胜", 30, 165));
//     C239.push_back(EXM::Person("杨嘉琦", 40, 165));
//     C239.insert(EXM::Person("牟小牛", 40, 165), 7);
//     for_each(C239.begin(), C239.end(), printf);
//     cout << "c239成员数：" << C239.size() << endl;
// }
// void test04()
// {
//     Array<EXM::Person> C239; // 自定义的Array必须提供begin()与end()函数，并且返回值相同
//     C239.push_back(EXM::Person("李德康", 18, 185));
//     C239.push_back(EXM::Person("白文超", 80, 165));
//     C239.push_back(EXM::Person("胡文杰", 20, 165));
//     C239.push_back(EXM::Person("唐家胜", 30, 165));
//     C239.push_back(EXM::Person("杨嘉琦", 40, 165));
//     C239.insert(EXM::Person("牟小牛", 40, 165), 7);
//     for (auto p : C239) // 如需要更改容器里的内容，必须以引用的方式定义遍历变量
//     {
//         p.SetAge(10);
//         p.SetHight(30);
//         p.SetName("无名氏");
//     }
//     // for (EXM::Person p : C239)
//     // {
//     //     cout << p << endl;
//     // }
//     C239[0] = EXM::Person("王康", 49, 130);
//     // cout<<C239<<endl;
//     for (auto p : C239) // 如需要更改容器里的内容，必须以引用的方式定义遍历变量
//     {
//         cout << p << endl;
//     }
// }

// int main()
// {
//     clock_t start_time, end_time;
//     start_time = clock(); // 获取开始执行时间
//     // test01();
//     // test02();
//     // test03();
//     // test04();
//     const EXM::Person p("张三", 30, 130);
//     cout << p << endl;
//     system("pause");
//     end_time = clock();
//     double Times = (double)(end_time - start_time);
//     return 0;
// }