// #include <iostream>
// #include <string>
// #include <time.h>
// #include <cstdlib>
// #include <vector> // 亦称为单端数组，可以动态扩展，并非是将原有的空间扩展，无法保证后续空间会被占用，所以要开辟新空间
// #include <algorithm>
// #include "C:\Users\Administrator\Desktop\project-C++\test\TemplateLearning\example.hpp"
// typedef vector<int> VEC_INT;
// typedef Array<int> Array_INT;
// typedef Array<EXM::Person> Array_P;
// typedef Array<string> Array_str;
// using namespace std;
// void print(int elem)
// {
//     cout << elem;
// }
// void test01()
// {
//     vector<VEC_INT> v1;
//     int row = 5, colum = 6;
//     for (int i = 0; i < row; i++)
//     {
//         VEC_INT v_temp;
//         v1.push_back(v_temp);
//         for (int j = 0; j < colum; j++)
//         {
//             v1[i].push_back(EXM::GenerateNum<int>(1, 20));
//         }
//     }
//     // for (vector<VEC_INT>::iterator it1 = v1.begin(); it1 != v1.end(); it1++)
//     // {
//     //     for (VEC_INT::iterator it2 = it1->begin(); it2 != it1->end(); it2++)
//     //     {
//     //         cout << *it2 << "\t";
//     //     }
//     //     cout << endl;
//     // }
//     for (auto a1 : v1)
//     {
//         for (auto a2 : a1)
//         {
//             cout << a2 << "\t";
//         }
//         cout << endl;
//     }
// }
// void test02()
// {
//     Array<Array_INT> v1;
//     int row = 5, colum = 6;
//     Array_INT temp;
//     Array_INT t2 = temp;
//     v1.push_back(temp);
//     for (int i = 0; i < row; i++)
//     {
//         Array_INT v_temp;
//         v1.push_back(v_temp);
//         for (int j = 0; j < colum; j++)
//         {
//             v1[i].push_back(EXM::GenerateNum<int>(1, 20));
//         }
//     }
//     cout << v1 << endl;
//     // cout << v1.size() << endl;
//     // for (auto a1 : v1)
//     // {
//     //     for (auto a2 : a1)
//     //     {
//     //         cout << a2 << "\t";
//     //     }
//     //     cout << endl;
//     // }
//     // Array_INT v2;
//     // for (int i = 0; i < row; i++)
//     // {

//     //     v2.push_back(EXM::GenerateNum<int>(1, 20));
//     // }
//     // Array_INT v3;
//     // for (int i = 0; i < row+3; i++)
//     // {

//     //     v3.push_back(EXM::GenerateNum<int>(1, 20));
//     // }
//     // print(v2);
//     // print(v3);
//     // v3.assign(v2.begin(),v2.end());
//     // print(v3);
// }
// // vector 构造函数
// void test03()
// {
//     vector<int> v1;
//     srand(time(0));
//     for (int i = 0; i < 10; i++)
//     {
//         v1.push_back(EXM::GenerateNum<int>(2, 30));
//     }
//     print(v1);
//     vector<int> v2(v1.begin() + 3, v1.end());
//     print(v2);
//     vector<int> v3(v1); // vector的拷贝构造
//     print(v3);
//     vector<int> v4(6, 100);
//     print(v4);
// }
// void test04() // vextor 的赋值操作
// {
//     vector<int> v1;
//     srand(time(0));
//     for (int i = 0; i < 5; i++)
//     {
//         v1.push_back(EXM::GenerateNum<int>(2, 30));
//     }
//     print(v1);
//     vector<int> v2;
//     for (int i = 0; i < 10; i++)
//     {
//         v2.push_back(EXM::GenerateNum<int>(2, 30));
//     }
//     print(v2);
//     v2.assign(v1.begin(), v1.end()); // assign赋值操作会将原有的数据全覆盖
//     print(v2);
//     v2.assign(10, 100);
//     print(v2);
// }
// // 容器的大小
// void test05()
// {
//     vector<int> v1;
//     srand(time(0));
//     for (int i = 0; i < 10; i++)
//     {
//         v1.push_back(EXM::GenerateNum<int>(2, 30));
//     }
//     print(v1);
//     if (v1.empty())
//     {
//         cout << "v1为空" << endl;
//     }
//     else
//     {
//         cout << "v1不为空" << endl;
//         cout << "v1的容量为：" << v1.capacity() << endl;
//         cout << "v1的大小为：" << v1.size() << endl;
//     }
//     v1.resize(20); // 比之前大用0补齐，比之前小将多余的截取
//     cout << "v1的容量为：" << v1.capacity() << endl;
//     cout << "v1的大小为：" << v1.size() << endl;
//     print(v1);
// }
// // vector 的插入与删除
// void test06()
// {
//     vector<int> v1;
//     cout << "v1的容量为：" << v1.capacity() << endl;
//     cout << "v1的大小为：" << v1.size() << endl;
//     v1.resize(20); // resize相当于预留空间，会补零，并且push_back会从最后往前yi'wei'yi'wei
//     srand(time(0));
//     for (int i = 0; i < 10; i++)
//     {
//         v1.push_back(EXM::GenerateNum<int>(0, 30));
//         // v1.insert(it1, EXM::GenerateNum<int>(0, 30));
//     }
//     cout << "v1的容量为：" << v1.capacity() << endl;
//     cout << "v1的大小为：" << v1.size() << endl;
//     v1.insert(v1.begin() + 1, 20); // 注意参数为迭代器+元素
//     cout << "v1的容量为：" << v1.capacity() << endl;
//     cout << "v1的大小为：" << v1.size() << endl;
//     print(v1);
//     v1.erase(v1.begin()); // 注意参数为迭代器指向的元素位置
//     cout << "v1的容量为：" << v1.capacity() << endl;
//     cout << "v1的大小为：" << v1.size() << endl;
//     print(v1);
//     v1.clear(); // 清空元素
//     cout << "v1的容量为：" << v1.capacity() << endl;
//     cout << "v1的大小为：" << v1.size() << endl;
// }
// void test07()
// {
//     vector<int> v1;
//     srand(time(0));
//     for (int i = 0; i < 100000; i++)
//     {
//         v1.push_back(EXM::GenerateNum<int>(0, 30));
//     }
//     cout << "v1的容量为：" << v1.capacity() << endl;
//     cout << "v1的大小为：" << v1.size() << endl;
//     vector<int> v2;
//     for (int i = 0; i < 10; i++)
//     {
//         v2.push_back(EXM::GenerateNum<int>(0, 30));
//     }
//     v1.resize(3);  // 并不会改变之前容器的容量，导致非常占用内存
//     v1.reserve(3); // 预留空间只在当先空间小于3时才有用
//     cout << "v1的容量为：" << v1.capacity() << endl;
//     cout << "v1的大小为：" << v1.size() << endl;
//     vector<int>(v1).swap(v1); // 运用匿名对象让编译器立马回收内存
//     cout << "v1的容量为：" << v1.capacity() << endl;
//     cout << "v1的大小为：" << v1.size() << endl;
//     // cout<<"交换前："<<endl;
//     // print(v1);
//     // print(v2);
//     // v1.swap(v2);  //  也可以用下面的语法
//     // // v2.swap(v1);
//     // cout<<"交换后："<<endl;
//     // print(v1);
//     // print(v2);
// }
// void test08()
// {
//     vector<int> v;
//     v.reserve(100000);  // 如果预先知道内存大小可以预先预留可以节省时间
//     int count = 0;
//     int *p = nullptr;
//     cout<<"v的默认预留空间大小"<<v.capacity()<<endl;
//     for (int i = 0; i < 100000; i++)
//     {
//         v.push_back(1);
//         if (p != &v[0])
//         {
//             p = &v[0];
//             count++;
//         }
//     }
//     cout << count << endl;
// }
// int main()
// {
//     clock_t start_time, end_time;
//     start_time = clock(); // 获取开始执行时间
//     // test01();
//     // test02();
//     // test03();
//     // test04();
//     // test05();
//     // test06();
//     // test07();
//     test08();
//     system("pause");
//     end_time = clock();
//     double Times = (double)(end_time - start_time);
//     return 0;
// }