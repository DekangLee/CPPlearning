// #include <iostream>
// #include <string>
// #include <time.h>
// using namespace std;
// //
// class Animal
// {
//     friend class Cat; // 子类作为父类的友元在子类里面可以对父类的私有属性进行操作
//     friend void test01();

// public:
//     virtual void speak() = 0;

// private:
//     string m_A;
//     Animal()
//     {
//         m_A = "Animal";
//         cout << "Animal的构造函数" << endl;
//     }
//     //    virtual ~Animal()   // 父类虚析构的好处是当父类指针需要释放时可以走子类的析构代码
//     //     {
//     //         cout << "Animal的析构函数" << endl;
//     //     }
//     virtual ~Animal() = 0;
// };
// Animal::~Animal()
// {
//     cout << "Animal的纯析构函数" << endl;
// }
// class Cat : public Animal
// {
//     friend void test01();

// public:
//     void speak()
//     {
//         cout << "小猫" << *m_Name << "在说话" << endl;
//     }
//     Cat()
//     {
//     }
//     Cat(string name) // 事实上子类对象在构造的时候要调用父类的构造函数
//     {
//         m_A = name;
//         Animal::m_A = "白文超";
//         m_Name = new string(name);
//         cout << "Cat的有参构造" << endl;
//     }
//     ~Cat()
//     {
//         if (m_Name != NULL)
//         {
//             delete m_Name;
//             m_Name = NULL;
//         }
//         cout << "Cat的析构函数" << endl;
//     }
//     void setName(string name) // 父类指针指向子类只能进行同名属性的操作，其余属性不能通过父类指针进行调用
//     {
//         m_A = name;
//     }
//     Cat &operator=(const string &s)
//     {
//         m_A = s;
//         return *this;
//     }

// private:
//     string *m_Name = NULL; // 防止m_Name变成野指针
//     string m_A;
// };
// void test01()
// {
//     Animal *animal = new Cat("Tom");
//     Cat cat1;
//     cat1 = "miaomiao";
//     // Animal *anima2;  // 并没有实例化对象，仅仅是声明了一个Animal类型的指针
//     animal->speak();
//     cout << animal->m_A << endl;
//     cout << "Name of cat1 :" << cat1.m_A << endl;
//     delete animal;
//     cout << "Size of Animal = " << sizeof(Animal) << endl;
//     cout << "Size of Cat = " << sizeof(Cat) << endl;
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