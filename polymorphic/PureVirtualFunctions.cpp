// #include <iostream>
// #include <string>
// #include <time.h>
// using namespace std;
// class AbstractBase
// {
// public:
//     virtual int func() = 0; // 纯虚函数，该类为抽象类，无法创造对象
// };
// class Son1 : public AbstractBase
// {
//     friend void test01();

// public:
//     int func()
//     {
//         cout << "子类重写父类纯虚函数" << endl; // 子类必须重写父类的纯虚函数，否则也无法创造对象
//         return 1;
//     }
// };
// void test01()
// {
//     AbstractBase *abc = new Son1;
//     cout << "Size of Son1 = " << sizeof(AbstractBase) << endl;
//     abc->func();
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