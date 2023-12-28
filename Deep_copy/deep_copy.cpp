// #include <iostream>
// #include <string>
// using namespace std;
// // class Person
// // {
// // public:
// //     string Name;

// // protected:
// //     string car="奔驰";

// // private:
// //     int pass_word=53854;

// // public:
// //     void show()
// //     {
// //         cout << Name << "的" << car << "密码是：" << pass_word << endl;
// //     }
// // };
// class Person
// {
// private:
//     /* data */
//     string m_Name;
//     int m_Age;
//     string m_Lover;

// public:
//     int *m_high;
//     Person(/* args */)
//     {
//         cout << "Perosn默认构造函数调用" << endl;
//     }
//     Person(int age, int high = 180) : m_Age(10), m_Name("ldk")
//     {
//         m_Age = age;
//         m_high = new int;
//         *m_high = high;
//         cout << "Perosn有参构造函数调用" << endl;
//     }
//     Person(const Person &p)
//     {
//         m_Age = p.m_Age;
//         m_high = new int;
//         *m_high = *p.m_high;
//     }
//     void setName(string name)
//     {
//         m_Name = name;
//     }
//     string getName()
//     {
//         return m_Name;
//     }
//     int getAge()
//     {
//         return m_Age;
//     }
//     void setLover(string Lover)
//     {
//         m_Lover = Lover;
//     }
//     void setAge(int age)
//     {
//         if (age < 0 || age > 150)
//         {
//             m_Age = 0;
//             cout << "输入年龄有误" << endl;
//         }
//         else
//             m_Age = age;
//     }
//     void func(Person p)
//     {
//         p.getName();
//     }
//     ~Person()
//     {
//         if (m_high != NULL)
//         {
//             delete m_high;
//             m_high = NULL;
//         }
//     }
// };
// // void test01()
// // {
// //     Person p1(19,190);
// //     // p1.setAge(10);
// //     cout<<"p1的年龄："<<p1.getAge()<<"p1的身高："<<*p1.m_high<<endl;
// //     Person p2(p1);
// //     cout<<"p2的年龄："<<p2.getAge()<<"p2的身高："<<*p2.m_high<<endl;
// //     cout<<*p2.m_high<<endl;

// // }
// void test02()
// {
//     Person p1(1);
//     cout << "p1的姓名" << p1.getName() << endl;
//     cout << "p1的身高" << *p1.m_high << endl;
// }
// int main()
// {

//     test02();
//     system("pause");
//     return 1;
// }