// #include <iostream>
// #include <string>
// #include <map>
// #include <vector>
// #include <ctime>
// #include <cstdlib>
// #include <algorithm>
// using namespace std;
// class Add
// {
// public:
//     Add()
//     {
//         this->count = 0;
//     }
//     int operator()(int a, int b)
//     {
//         this->count++;
//         return a + b;
//     }
//     int count; // count的作用可以记录该仿函数被调用多少次，对于普通函数只能通过静态变量的方法来实现记录函数调用次数
// };
// class Print
// {
// public:
//     Print()
//     {
//         this->count = 0;
//     }
//     void operator()(const string &str)
//     {
//         this->count++;
//         cout << str << endl;
//     }
//     int count;
// };
// void test01()
// {
//     // Add myAdd;
//     // cout << "1+2=" << myAdd(1, 2) << endl;
//     Print myPrint;
//     myPrint("Hello world !");
//     myPrint("Hello world !");
//     myPrint("Hello world !");
//     myPrint("Hello world !");
//     myPrint("Hello world !");
//     cout<<"count = "<<myPrint.count<<endl;
// }
// // 函数对象可以作为参数传入
// void DoPrint(Print &p,string str)
// {
//     p(str);
// }
// void test02()
// {
//     Print myPrint;
//     DoPrint(myPrint,"Hello C++!");
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
//     system("pause");
//     end_time = clock();
//     double Times = (double)(end_time - start_time);
//     cout << "程序运行" << Times << "s" << endl;
//     return 0;
// } 