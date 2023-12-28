// #include <iostream>
// #include <string>
// using namespace std;
// class Base1
// {
//     friend void test01();

// public:
//     friend void test05();
//     int m_A;
//     static int m_D;
//     Base1()
//     {
//         m_A = 200;
//         // cout << "Base1的默认构造函数" << endl;
//     }
//     Base1(int a) : m_A(10)
//     {
//         // cout << "Base1的有参构造函数" << endl;
//     }
//     ~Base1()
//     {
//         // cout << "Base1的析构函数" << endl;
//     }
//     void func()
//     {
//         cout << "Base1的成员函数func()调用" << endl;
//     }
//     void func(int a)
//     {
//         cout << "Base1的成员函数func(int a)调用" << endl;
//     }

// private:
//     static void func1()
//     {
//         cout << "Base1----->static void func1()" << endl;
//     }

// protected:
//     int m_B;

// private:
//     int m_C;
    
// };
// int Base1::m_D = 21;
// class Derivation1 : public Base1
// {
//      friend void test01();
// public:
//     int m_A;
//     static int m_D;
//     Derivation1()
//     {
//         // m_A = 100;
//         // cout << "Derivation1的默认构造函数" << endl;
//     }
//     ~Derivation1()
//     {
//         // cout << "Derivation1的析构函数" << endl;
//     }
//     void func()
//     {
//         m_A = 10; // 父类的公共权限在子类中是公共权限
//         m_B = 10; // 父类的保护权限在子类中是保护权限
//     }
//     static void func1()
//     {
//         cout << "Derivation1----->static void func1()" << endl;
//     }
// };
// int Derivation1::m_D = 22;
// class Derivation2 : protected Base1
// {
//     friend void test01();
//     void func()
//     {
//         m_A = 10; // 父类的公共权限在子类中是保护权限
//         m_B = 10; // 父类的保护权限在子类中是保护权限
//     }
// };
// class Derivation3 : private Base1
// {
//     friend void test01();
//     void func()
//     {
//         m_A = 10; // 父类的公共权限在子类中是私有权限
//         m_B = 10; // 父类的保护权限在子类中是私有权限
//     }
// };

// void test01()
// {
//     Base1 B;
//     Derivation1 D1;
//     Derivation2 D2;
//     Derivation3 D3;
//     D1.m_A = 10; // 可访问
//     D1.m_B = 10;
//     D1.m_C = 10;
//     cout<< "D1.m_C"<<D1.m_C<<endl;
//     D2.m_A = 10;
//     D2.m_B = 10;
//     D2.m_C = 10;
//     D3.m_A = 20; // 继承并不会继承友元，继承中的权限问题可以通过友元技术解决，层层递进：子类---->父类（友元关系是单向的）
//     D3.m_C = 20;
// }
// // 继承中的对象模型
// void test02()
// {
//     Base1 B;
//     Derivation1 D;
//     cout << "Base' size:" << sizeof(Base1) << endl; // 事实上父类的所有成员属性（除静态成员变量）都会被继承，但是私有属性被编译器隐藏
//     cout << "Derivation1' size:" << sizeof(Derivation1) << endl;
// }
// // 同名成员属性与成员函数的处理，父类中与子类中出现同名的成员，在子类中会将父类的成员隐藏掉
// void test03()
// {
//     // Base1 B;
//     Derivation1 D;
//     D.Base1::func(1); // 对于同名函数加类名作用域会调用父类成员函数
//     cout << "D 作用域下的m_A：" << D.m_A << endl;
//     cout << "Base 作用域下的m_A：" << D.Base1::m_A << endl; // 通过作用域名称调用父类同名属性
// }
// // 静态成员变量与成员函数的处理
// void test04()
// {
//     Base1 B;
//     Derivation1 D;
//     D.Base1::m_D = 23; // 通过作用域名称调用父类同名静态属性
//     cout << "D 作用域下的 static m_D：" << D.m_D << endl;
//     Derivation1 ::m_D = 19;
//     Derivation1::Base1::m_D = 19;
//     cout << "Base 作用域下的static m_D：" << D.Base1::m_D << endl; // 通过作用域名称调用父类同名属性

//     cout << "对象B 的静态成员变量 static m_D：" << B.m_D << endl;
// }
// void test05()
// {
//     Base1 B;
//     Derivation1 D;
//     // B.func1();
//     D.func1();
//     D.Base1::func1();
// }
// int main()
// {
//     test01();
//     // test02();
//     // test03();
//     // test04();
//     // test05();
//     system("pause");
//     return 1;
// }