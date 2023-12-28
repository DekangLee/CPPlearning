// #include<iostream>
// using namespace std;
// int foo()
// {
//    return 10; 
// }
// double goo()
// {
//     return 2.1;
// }
// int hoo(int a, int b)
// {
//     return a+b;
// }
// int add(int a,int b)
// {
//     return a+b;
// }
// int sub(int a,int b)
// {
//     return a-b;
// }
// void caculate(int a, int b,int (*f)(int,int))
// {
//     cout<<f(a,b)<<endl;
// }
// int main()
// {
//     int a=1;
//     int b=2;
//     int (*funpoint1)()=foo;
//     int (*funpoint2)(int,int)=hoo;

//     cout<<funpoint1()<<endl;
//     cout<<funpoint2(2,3)<<endl;
//     caculate(2,3,add);
//     caculate(2,3,sub);
//     std::swap(a,b);
//     cout<<a<<"  "<<b<<endl;
//     system("pause");
//     return 0;
// }