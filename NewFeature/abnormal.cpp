// #include <iostream>
// using namespace std;
// int test()
// {
//     int a, b;
//     cout << "Please inpt two numbers:" << endl;
//     cin >> a >> b;
//     if (b == 0)
//         throw bad_exception();
//     return a / b;
// }

// int main()
// {
//     try
//     {
//         int a = test();
//         cout << a << endl;
//     }    //{ }代码块可能不会被执行，所有该区域定义的变量会被销毁
//     catch (exception &e)
//     {
//         cout << e.what() << endl;
//     }

//     return 0;
// }