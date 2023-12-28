// #include <iostream>
// #include <string>
// using namespace std;
// // class Java
// // {
// // public:
// //     void Header()
// //     {
// //         cout << "首页、公开课、登录、注册......." << endl;
// //     }
// //     void Footer()
// //     {
// //         cout << "帮助中心、交流合作、站内地图......" << endl;
// //     }
// //     void left()
// //     {
// //         cout << "Python Java C++  .........." << endl;
// //     }
// //     void content()
// //     {
// //         cout << "Java 页面内容" << endl;
// //     }
// // };
// // class Python
// // {
// // public:
// //     void Header()
// //     {
// //         cout << "首页、公开课、登录、注册......." << endl;
// //     }
// //     void Footer()
// //     {
// //         cout << "帮助中心、交流合作、站内地图......" << endl;
// //     }
// //     void left()
// //     {
// //         cout << "Python Java C++  .........." << endl;
// //     }
// //     void content()
// //     {
// //         cout << "Python 页面内容" << endl;
// //     }
// // };
// // class Cpp
// // {
// // public:
// //     void Header()
// //     {
// //         cout << "首页、公开课、登录、注册......." << endl;
// //     }
// //     void Footer()
// //     {
// //         cout << "帮助中心、交流合作、站内地图......" << endl;
// //     }
// //     void left()
// //     {
// //         cout << "Python Java C++  .........." << endl;
// //     }
// //     void content()
// //     {
// //         cout << "cpp 页面内容" << endl;
// //     }
// // };
// class BasePage
// {
// public:
//     void Header()
//     {
//         cout << "首页、公开课、登录、注册......." << endl;
//     }
//     void Footer()
//     {
//         cout << "帮助中心、交流合作、站内地图......" << endl;
//     }
//     void left()
//     {
//         cout << "Python Java C++  .........." << endl;
//     }
// };
// // 继承的好处，可以减少重复代码
// // 语法 子类 ：继承方式 父类
// // 子类也称为派生类，父类也称为基类
// class Java : public BasePage
// {
// public:
//     void content()
//     {
//         cout << "Java 页面内容" << endl;
//     }
// };
// class Python : public BasePage
// {
// public:
//     void content()
//     {
//         cout << "Python 页面内容" << endl;
//     }
// };
// class Cpp : public BasePage
// {
// public:
//     void content()
//     {
//         cout << "Cpp 页面内容" << endl;
//     }
// };
// void test01()
// {
//     Java JavaObj;
//     Python PythonObj;
//     Cpp cppObj;
//     JavaObj.Header();
//     JavaObj.Footer();
//     JavaObj.left();
//     JavaObj.content();
//     PythonObj.content();
//     cppObj.content();
// }
// int main()
// {
//     test01();
//     system("pause");
//     return 1;
// }