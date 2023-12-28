// #include<iostream>
// using namespace std;
// // 对象的初始化和清理
// class Person
// {
//     public:
//     Person()
//     {
//         cout<<"构造函数的调用"<<endl;
//     }
//     Person(int a)
//     {
//         age = a;
//         cout<<"有参构造的调用"<<endl;
//     }
//     Person(const Person &p)
//     {
//         age = p.age;
//         cout<<"拷贝构造的调用"<<endl;
//     }
//     ~Person()
//     {
//         cout<<"析构函数的调用"<<endl;
//     }
//     char age;
//     int number;

// };
// void test1()
// {
//     // 1、括号法
//     // Person p1;
//     // Person p2(10);
//     // Person p3(p2);
//     // 2、显式法
//     Person p1 = Person(10);
//     Person p2 = Person(p1);
//     Person(10); // 匿名对象，执行完当前行，会被系统回收
//     // 切勿用拷贝构造生成匿名对象 Person(p1)===Person P1 报错！


//     // 3、隐式转换法
//     Person p3 =100;
//     cout<<p3.age<<endl;
//     Person p4 =p3;


// }
// void dowork(Person p)
// {
// }
// Person dowork1()
// {
//     Person p(10);
//     return p;
// }
// void test02()
// {
//     Person p(10);
//     dowork(p);
// }
// void test03()
// {
//     Person p1=dowork1();
// }
// int main()
// {
//     test1();
//     // Person(1);
//     cout<<"   "<<endl;
    
    
//     system("pause");
//     return 1;
// }