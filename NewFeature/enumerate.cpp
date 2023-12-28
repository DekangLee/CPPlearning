// #include <iostream>
// #include <string>
// using namespace std;
// #define ONE 1;
// enum Week
// {
//     one,
//     tow,
//     three,
//     four,
//     five,
//     six,
//     seven

// };
// void test01()
// {
//     enum Week today = one;
//     cout << Week::one<<endl;;
//     cout<< today<<endl;
// }
// void test02()
// {
//     auto a  = 1;  //auto类型必须赋初值  类似模板函数的自动推导
//     a = 2.1;
//     auto a1(10);
//     int i(10);
//     int &b = a;
//     const float &c = b;
//     int &d = b;
//     cout<<sizeof(a)<<endl;
//     cout<<b<<endl;
// }
// void test03()
// {
//     int arr[]  = {0,2,1,3,5,7};
//     for(auto i:arr)
//     {
//         cout<<i<<endl;
//     }
// }
// int main()
// {
//     // test01();
//     // test02();
//     test03();
//     system("pause");
//     return 0;
// }