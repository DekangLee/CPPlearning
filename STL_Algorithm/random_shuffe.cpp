// #include <iostream>
// #include <string>
// #include <map>
// #include <vector>
// #include <ctime>
// #include <cstdlib>
// #include <algorithm> // 包含头文件
// #include <functional>
// #include "commen.hpp"
// ostream &operator<<(ostream &cout, const vector<int> &elem)
// {
//     for (auto a : elem)
//     {
//         cout << a << " ";
//     }
//     return cout;
// }
// template<class T1, class T2>
// vector<T1> operator*(const vector<T1> &v , T2 num)
// {
//     vector<T1>res;
//     for(auto elem:v)
//     {
//         res.push_back(elem*num);
//     }
//     return res;
// }
// template<class T1, class T2>
// vector<T1> operator*(T2 num , const vector<T1> &v)
// {
//     vector<T1>res;
//     for(auto elem:v)
//     {
//         res.push_back(elem*num);
//     }
//     return res;
// }
// // 排序算法-洗牌
// void test01()
// {
//     vector<int> v;
//     for (int i = 0; i < 10; i++)
//     {
//         v.push_back(i);
//     }
//     print(v);
//     cout << "----------------" << endl;
//     random_shuffle(v.begin(), v.end());
//     print(v);
//     vector<Person> Per_v;
//     Per_v.emplace_back("李德康", 18);
//     Per_v.emplace_back("白文超", 19);
//     Per_v.emplace_back("胡文杰", 20);
//     Per_v.emplace_back("唐家胜", 23);
//     Per_v.emplace_back("杨嘉琦", 20);
//     Per_v.emplace_back("牟小牛", 21);
//     random_shuffle(Per_v.begin(), Per_v.end());
//     print(Per_v);
// }
// // 常用排序算法--merge
// void test02()
// {
//     vector<int> v1 = {2, 1, 3, 10, 4, 19, 2};
//     vector<int> v2 = {4, 1, 3, 5, 12, 4};
//     vector<int> v_target;
//     v_target.resize(v1.size() + v2.size()); // 这里需要将目标容器的大小重置
//     sort(v1.begin(), v1.end());
//     sort(v2.begin(), v2.end());
//     merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v_target.begin()); // 原容器需要是两个顺序相同的有序容器
//     print(v_target);
// }
// void test03()
// {
//     vector<int> v1 = {2, 1, 3, 10, 4, 19, 2};
//     reverse(v1.begin(), v1.end());
//     print(v1);
// }
// // copy算法
// void test04()
// {
//     vector<int> v1 = {2, 1, 3, 10, 4, 19, 2};
//     vector<int> v2;
//     v2.resize(v1.size());
//     copy(v1.begin() + 1, v1.end(), v2.begin());
//     print(v2);
// }
// // replace算法
// void test05()
// {
//     vector<int> v1 = {2, 1, 3, 10, 4, 19, 2};
//     replace(v1.begin(), v1.end(), 2, -2); // 无返回值。原位操作
//     print(v1);
//     auto _replaceIF = [](int elem)
//     {
//         if (elem > 4)
//             return true;
//         else
//             return false;
//     };
//     replace_if(v1.begin(), v1.end(), _replaceIF, 5);
//     cout << "replace_if(>4->5)" << endl;
//     print(v1);
//     vector<int> v2 = {2, 1, 3, 10, 4, 19, 2};
//     vector<int> res;
//     res.resize(v2.size());
//     // replace_copy(v2.begin(), v2.end(), res.begin(), 1, -2); // 存在返回值，并且不是原位操作，并不会改变输入容器的值
//     replace_copy_if(v1.begin(), v1.end(), res.begin(), _replaceIF, 5);
//     cout << "v2:" << v2 << endl;
//     cout << "res:" << res << endl;
// }
// // swap算法实现同种类型的容器互换
// void test06()
// {
//     vector<int> v1 = {2, 1, 3, 10, 4, 19, 2};
//     vector<int> v2 = {3, 10, 4, 2};
//     cout << "交换前：" << endl;
//     cout << "v1:" << v1 << endl;
//     cout << "v2:" << v2 << endl;
//     swap(v1, v2);
//     cout << "交换后：" << endl;
//     cout << "v1:" << v1 << endl;
//     cout << "v2:" << v2 << endl;
// }
// void test07()
// {
//     vector<int> v1 = {2, 1, 3, 10, 4, 19, 2};
//     vector<int>res = 2.1*v1;
//     cout<<"res: "<< res<<endl;
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