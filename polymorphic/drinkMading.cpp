// #include <iostream>
// #include <string>
// #include <time.h>
// using namespace std;
// // 多态案例--制作饮品
// class Dringking
// {
// public:
//     // 煮水
//     virtual void Boil() = 0;
//     // 冲泡
//     virtual void Brew() = 0;
//     // 倒入杯中
//     virtual void PourInCup() = 0;
//     // 加入辅料
//     virtual void PutSomething() = 0;
//     void MakingDrink()
//     {
//         Boil();
//         Brew();
//         PourInCup();
//         PutSomething();
//     }
// };
// class coffee : public Dringking
// {
// public:
//     void Boil()
//     {
//         cout << "煮农夫山泉" << endl;
//     }
//     void Brew()
//     {
//         cout << "冲泡咖啡" << endl;
//     }
//     virtual void PourInCup()
//     {
//         cout << "倒入杯中" << endl;
//     }
//     virtual void PutSomething()
//     {
//         cout << "加入糖块" << endl;
//     }
// };
// class tea : public Dringking
// {
// public:
//     void Boil()
//     {
//         cout << "煮农夫山泉" << endl;
//     }
//     void Brew()
//     {
//         cout << "冲泡茶叶" << endl;
//     }
//     virtual void PourInCup()
//     {
//         cout << "倒入杯中" << endl;
//     }
//     virtual void PutSomething()
//     {
//         cout << "加入柠檬" << endl;
//     }
// };
// void doWork(Dringking *drinking)
// {
//     drinking->MakingDrink();
//     delete drinking;
// }
// void test01()
// {
//     Dringking *drinking = new coffee;
//     doWork(drinking);
//     drinking = new tea;
//      doWork(drinking);
// }
// int main()
// {
//     clock_t start_time, end_time;
//     start_time = clock(); // 获取开始执行时间
//     test01();
//     // test02();
//     end_time = clock();
//     double Times = (double)(end_time - start_time) / CLOCKS_PER_SEC;
//     cout << "程序运行时间：" << Times << "s" << endl;
//     system("pause");

//     return 1;
// }