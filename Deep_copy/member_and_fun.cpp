// #include <iostream>
// #include <string>
// using namespace std;
// class Person
// {
// public:
// int age=9;
// void fun(int age)
// {
//     if(this == NULL)
//     {
//         return;
//     }      // 提高代码的健壮性，防止对象指针为空指针
//     this->age=age;
// }
// Person& addAge(const Person &p)
// {
//     this->age+=p.age;
//     return *this;
// }
// void showAge()
// {
//     cout<<"空指针调用"<<endl;
// }

// private:
// };
// void test01()
// {
//     Person p1,p2;
//     p1.fun(19);
//     p2.fun(19);
//     p1.addAge(p1).addAge(p2); // 链式编程思想，与cout一样
//     cout<<p1.age<<endl;

// }
// void test02()
// {
//     Person *p = NULL;
//     p->fun(20);
//     p->showAge();
// }
// int main()
// {

//     // test01();
//     test02();
//     system("pause");
//     return 1;
// }
//测试代码二:
// #include<iostream>
// using namespace std;

// bool compare(int a,int b){
//     cout<<"compare(int,int)"<<endl;
//     return a>b;
// }

// bool compare(float a,float b){
//     cout<<"compare(float,float)"<<endl;
//     return a>b;
// }

// int main(){
//     float a=10.1;
//     float b=20.2;
//     compare(10,20);
//     compare(a,b); 
//     return 0;
// }