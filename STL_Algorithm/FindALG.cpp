// #include <iostream>
// #include <string>
// #include <map>
// #include <vector>
// #include <ctime>
// #include <cstdlib>
// #include <algorithm> // 包含头文件
// #include <functional>
// #include "commen.hpp"
// // 常用查找算法  查找内置数据类型
// void test01()
// {
//     vector<int> v = {2, 3, 15, 19, 2, 31, 10, 6, 7};
//     vector<int>::iterator it = find(v.begin(), v.end(), 3);
//     if (it == v.end())
//     {
//         cout << "未查找到该元素" << endl;
//     }
//     else
//         cout << "该元素位置为:" << it - v.begin() << endl;
// }
// // 对于自定义数据类型
// void test02()
// {
//     vector<Person> Per_v;
//     Per_v.emplace_back("李德康", 18);
//     Per_v.emplace_back("白文超", 19);
//     Per_v.emplace_back("胡文杰", 20);
//     Per_v.emplace_back("唐家胜", 23);
//     Per_v.emplace_back("杨嘉琦", 30);
//     Per_v.emplace_back("牟小牛", 21);
//     print(Per_v);
//     Person Pfind("牟小牛", 20);
//     vector<Person>::iterator it = find(Per_v.begin(), Per_v.end(), Pfind);
//     if (it == Per_v.end())
//     {
//         cout << "未查到 " << Pfind << endl;
//     }
//     else
//         cout << Pfind << " 位于:" << it - Per_v.begin() << endl;
// }
// // find_if
// void test03()
// {
//     vector<int> v = {2, 3, 15, 19, 2, 31, 10, 6, 7};
//     auto _findIf = [](int a)
//     {
//         if (a > 5)
//             return true;
//         else
//             return false;
//     };
//     vector<int>::iterator it = find_if(v.begin(), v.end(), _findIf);
//     if (it == v.end())
//     {
//         cout << "未查找到该元素" << endl;
//     }
//     else
//         cout << "该元素位置为:" << it - v.begin() << endl;
// }
// void test04()
// {
//     vector<Person> Per_v;
//     Per_v.emplace_back("李德康", 18);
//     Per_v.emplace_back("白文超", 19);
//     Per_v.emplace_back("胡文杰", 20);
//     Per_v.emplace_back("唐家胜", 23);
//     Per_v.emplace_back("杨嘉琦", 30);
//     Per_v.emplace_back("牟小牛", 21);
//     print(Per_v);
//     Person Pfind("牟小牛", 20);
//     auto _findIf = [](const Person &p)
//     {
//         if (p._age > 20)
//         {
//             return true;
//         }
//         else
//             return false;
//     };
//     vector<Person>::iterator it = find_if(Per_v.begin(), Per_v.end(), _findIf);
//     if (it == Per_v.end())
//     {
//         cout << "未查到 " << Pfind << endl;
//     }
//     else
//         cout << *it << " 位于:" << it - Per_v.begin() << endl;
// }
// // adjecent_find() 查找容器内的相邻元素是否相同，如果相同返回第一个迭代器的位置
// void test05()
// {
//     vector<int> v = {2, 15, 15, 19, 2, 2, 10, 6, 7};
//     vector<int>::iterator it_INT = adjacent_find(v.begin(), v.end());
//     if (it_INT == v.end())
//     {
//         cout << "未查找到该元素" << endl;
//     }
//     else
//         cout << "该元素位置为:" << it_INT - v.begin() << endl;
//     vector<Person> Per_v;
//     Per_v.emplace_back("李德康", 18);
//     Per_v.emplace_back("白文超", 19);
//     Per_v.emplace_back("胡文杰", 20);
//     Per_v.emplace_back("唐家胜", 23);
//     Per_v.emplace_back("杨嘉琦", 30);
//     Per_v.emplace_back("牟小牛", 21);
//     Per_v.emplace(Per_v.begin() + 3, Person("二驴子", 30));
//     print(Per_v);
//     Person Pfind("牟小牛", 20);
//     auto _findIf = [](const Person &p)
//     {
//         if (p._age > 20)
//         {
//             return true;
//         }
//         else
//             return false;
//     };

//     vector<Person>::iterator it_Per = adjacent_find(Per_v.begin(), Per_v.end());
//     if (it_Per == Per_v.end())
//     {
//         cout << "未查到相邻重复元素" << endl;
//     }
//     else
//         cout << *it_Per << " 位于:" << it_Per - Per_v.begin() << endl;
// }
// // binary_search()  这里的容器内容必须要是有序的序列
// void test06()
// {
//     vector<int> v = {2, 15, 3, 19, 4, 1, 10, 6, 7};
//     sort(v.begin(), v.end());
//     bool res = binary_search(v.begin(), v.end(), 3); // 返回值为布尔类型,适用于快速查找
//     if (res)
//     {
//         cout << "查到了" << endl;
//     }
//     else
//         cout << "未查到" << endl;
// }
// // count()算法
// void test07()
// {
//     vector<int> v = {3, 15, 3, 19, 4, 3, 10, 3, 7};
//     int num_int = count(v.begin(), v.end(), 3); // 变量名不要与同一作用域下的函数名重名
//                                                 // cout<<"count(3) = "<<num<<endl;
//     vector<Person> Per_v;
//     Per_v.emplace_back("李德康", 18);
//     Per_v.emplace_back("白文超", 19);
//     Per_v.emplace_back("胡文杰", 20);
//     Per_v.emplace_back("唐家胜", 23);
//     Per_v.emplace_back("杨嘉琦", 20);
//     Per_v.emplace_back("牟小牛", 21);
//     Per_v.emplace(Per_v.begin() + 3, Person("二驴子", 30));
//     Person P_test("王麻子", 20);
//     int num_Per = count(Per_v.begin(), Per_v.end(), P_test);
//     cout << "count( P_test(\"王麻子\", 20)) = " << num_Per << endl;
//     auto _countAge20 = [](const Person &p)
//     {
//         if (p._age == 20)
//         {
//             return true;
//         }
//         else
//             return false;
//     };
//     int num_PerIf = count_if(Per_v.begin(), Per_v.end(), _countAge20);
//     cout << "年龄为20的数量：" << num_PerIf << endl;
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
//     test07();
//     end_time = clock();
//     double Times = (double)(end_time - start_time) / CLOCKS_PER_SEC;
//     cout << "程序运行" << Times << "s" << endl;
//     system("pause");
//     return 0;
// }