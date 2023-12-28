// #include <iostream>
// using namespace std;
// #include <string>
// // const ostream out = cout;  // 操作无效不能自己定义
// // 加号运算符重载
// class MyInteger
// {
//     friend ostream &operator<<(ostream &cout, MyInteger myInteger);
//     // friend MyInteger &operator++(MyInteger &integer);
//     friend MyInteger operator++(MyInteger &integer,int);

// public:
//     MyInteger()
//     {
//         m_Number = 0;
//     }
//     // 类内函数做后置递增运算符重载
//     // MyInteger operator++(int)
//     // {
//     //     MyInteger temp = *this;
//     //     this->m_Number++;
//     //     return temp;
//     // }
//     // 类内函数做前置递增运算符重载
//     MyInteger &operator++()
//     {
//         ++this->m_Number;
//         return *this;
//     }

// private:
//     int m_Number;
// };
// ostream &operator<<(ostream &cout, MyInteger myInteger)
// {
//     cout << myInteger.m_Number;
//     return cout;
// }
// // 全局函数做前置递增运算符重载
// // MyInteger &operator++(MyInteger &integer)
// // {
// //     integer.m_Number++;
// //     return integer;
// // }
// // 全局函数做后置递增运算符重载
// MyInteger operator++(MyInteger &integer,int) // 占位符用做后置递增重载
// {
//     MyInteger temp = integer; // 按照后置递增的逻辑，先返回值，再做递增
//     integer.m_Number++;
//     return temp;
// }
// void test01()
// {
//     MyInteger myInteger;
//     cout << "递增前" << myInteger << endl;
//     // ++myInteger;
//     cout << "递增后" << ++(++myInteger) << endl;
// }
// void test02()
// {
//     MyInteger myInteger;
//     cout << "递增前" << myInteger << endl;
//     // ++myInteger;
//     cout << "递增后" << myInteger++<< endl;
//     cout << "递增" << myInteger << endl;

// }
// int main()
// {
//     test02();
//     // int a = 0;
//     // cout << "递增前" << a << endl;
//     // // ++myInteger;
//     // cout << "递增后" << a++ << endl;
//     // cout << "递增" << a << endl;

//     system("pause");
//     return 1;
// }