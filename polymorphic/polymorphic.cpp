// #include <iostream>
// #include <string>
// #include <time.h>
// using namespace std;
// // 多态
// class Animal // 动物类
// {
// public:
//     // int m_Age;
//     virtual void speak()
//     {
//         cout << "动物在说话" << endl;
//     }
// };
// // Animal类称为基类,Cat称为派生类
// class Cat : public Animal
// {
// public:
//     void speak()
//     {
//         cout << "小猫在说话喵喵" << endl;
//     }
// };
// class Dog : public Animal
// {
// public:
//     virtual void speak()  // 子类的virtual关键字可写可不写
//     {
//         cout << "小狗在说话汪汪" << endl;
//     }
// };
// // 地址早绑定，在编译阶段确定函数地址
// // 如果想让猫说话就需要地址晚绑定，在运行阶段绑定函数地址
// void DoSpeak(Animal &Animal) // Animal &Animal = cat 允许父类指针指向子类，不需要强制类型转换
// {
//     Animal.speak(); // speak函数的地址不同不能在编译阶段确定函数地址
// }
// void test01()
// {
//     Cat cat;
//     Dog dog;
//     Animal &A1 = cat;
//     A1.speak();  // 父类的指针或引用指向子类
//     Animal A2;
//     int *p;  // x64系统指针为8字节
//     // const Dog &D1 = A2; // 不允许子类指针指向父类
//     // DoSpeak(cat);
//     // DoSpeak(dog);
//     // cout<<"Size of *Animal = "<<sizeof(p)<<endl;
// }
// void test02()
// {
//     cout<<"Size of Animal = "<<sizeof(Animal)<<endl;
// }
// int main()
// {
//     clock_t start_time, end_time;
//     start_time = clock(); // 获取开始执行时间
//     // test01();
//     test02();
//     end_time = clock();
//     double Times = (double)(end_time - start_time) / CLOCKS_PER_SEC;
//     cout << "程序运行时间：" << Times << "s" << endl;
//     system("pause");

//     return 1;
// }