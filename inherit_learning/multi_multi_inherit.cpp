// #include <iostream>
// #include <string>
// using namespace std;
// class Animal // 动物类
// {
// public:
//     int m_Age;
// };
// // Animal类称为虚基类
// class Sheep : virtual public Animal // 羊类继承动物类 // 利用虚继承来解决菱形继承的问题
// {
// };
// class Tuo : virtual public Animal // 驼类继承动物类
// {
// };
// class SheepTuo : public Sheep, public Tuo // 羊驼类继承羊类和驼类
// {
// };
// void test01()
// {
//     SheepTuo st;
//     Sheep S;
//     Tuo T;
//     S.m_Age = 20;
//     T.m_Age = 30;
//     st.Sheep::m_Age = 18; // 菱形继承可以通过类名作用域来访问成员变量
//     st.Tuo::m_Age = 20;   // 但是问题是只需要一份数据，导致资源浪费
//     cout << "size of SheepTuo = " << sizeof(st) << endl;
//     cout << "Age of Tuo " << T.m_Age << endl;
//     cout << "Age of SheepTuo " << st.m_Age << endl;
// }
// int main()
// {
//     test01();
//     system("pause");
//     return 1;
// }