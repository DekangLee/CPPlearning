#include <iostream>
#include <string>
#include <map>
#include <time.h>
#include <cstdlib>
#include <algorithm>
#include "example.hpp"
// template<typename T1,typename T2>
// void printf(const map<T1,T2> &map1)
// {
//    for(typename::map<T1,T2>::const_iterator it= map1.begin();it!=map1.end();it++)
//    {
//     cout<<"key:"<<(*it).first<<" value:"<<(*it).second<<endl;
//    }
// }
// template<class T1,class T2>
// void printf(const map<T1,T2> &map1)
// {
//    for(class::map<T1,T2>::const_iterator it= map1.begin();it!=map1.end();it++)
//    {
//     cout<<"key:"<<(*it).first<<" value:"<<(*it).second<<endl;
//    }
// }
class compare
{
public:
    bool operator()(int a, int b)
    {
        return a > b;
    }
};
template <class T1, class T2>
void printf(const map<T1, T2> &map1)
{
    for (auto it = map1.begin(); it != map1.end(); it++) // 最简单省事的办法直接用auto声明变量
    {
        cout << "key:" << (*it).first << " value:" << (*it).second << endl;
    }
}
// void print(const map<string, int> &map1)
// {
//     for (map<string, int>::const_iterator it = map1.begin(); it != map1.end(); it++)
//     {
//         cout << "key:" << (*it).first << " value:" << (*it).second << endl;
//     }
// }
void print(const map<string, int> &map1)
{
    for (map<string, int>::const_iterator it = map1.begin(); it != map1.end(); it++)
    {
        cout << "key:" << (*it).first << " value:" << (*it).second << endl;
    }
}
void test01()
{
    map<string, int> map1; // 默认构造  会按照key值自动排序
    map1.insert(pair<string, int>("李德康", 18));
    map1.insert(pair<string, int>("白文超", 28));
    map1.insert(pair<string, int>("胡文杰", 38));
    map1.insert(pair<string, int>("唐家胜", 29));
    map1.insert(pair<string, int>("杨嘉琦", 125));
    map1.insert(pair<string, int>("李德康", 125)); // 存在pair返回值，来判断是否插入成功
    printf("map1:\n");
    printf(map1);
    map<string, int> map2(map1); // 拷贝构造
    printf("map2:\n");
    print(map2);
    map<string, int> map3;
    map3 = map2;
    printf("map3:\n");
    print(map3);
}
// map的大小和交换
void test02()
{
    map<int, int> map1;
    map1.insert(pair<int, int>(1, 10));
    map1.insert(pair<int, int>(2, 20));
    map1.insert(pair<int, int>(3, 30));
    map1.insert(pair<int, int>(4, 40));
    map1.insert(pair<int, int>(5, 50));
    map1.insert(pair<int, int>(6, 60));
    // cout<<"Size of map1:"<<map1.size()<<endl;
    if (map1.empty())
    {
        cout << "map1为空" << endl;
    }
    else
        cout << "Size of map1:" << map1.size() << endl;
    printf(map1);
    map<int, int> map2;
    map2.swap(map1);
    cout << "map2:" << endl;
    printf(map2);
}
// map的插入与删除
void test03()
{
    map<int, int> map1;
    map1.insert(pair<int, int>(1, 10));
    map1.insert(make_pair(2, 20));
    map1.emplace(3, 30);
    map1[4] = 40; // 常用该方法通过key访问value
    printf(map1);
    cout << "-------------" << endl;
    // 删除
    map1.erase(map1.begin()); // 输入迭代器
    printf(map1);
    cout << "-------------" << endl;
    map1.erase(3); // 传入key值
    printf(map1);
}
// map容器的查找
void test04()
{
    map<int, int> map1;
    map1.insert(pair<int, int>(1, 10));
    map1.insert(pair<int, int>(2, 20));
    map1.insert(pair<int, int>(3, 30));
    map1.insert(pair<int, int>(4, 40));
    map1.insert(pair<int, int>(5, 50));
    map1.insert(pair<int, int>(6, 60));
    map<int, int>::iterator res = map1.find(40); // 查找输入为键值，输出为迭代器
    if (res != map1.end())
    {
        cout << "key:" << (*res).first << " value:" << (*res).second << endl;
    }
    else
        cout << "未查到"
             << " key:" << (*res).first << " value:" << (*res).second << endl;
}
// map容器的排序
void test05()
{
    map<int, int, compare> map1; // compare使得map1按照键值从大到小排序
    map1.insert(pair<int, int>(1, 10));
    map1.insert(pair<int, int>(2, 20));
    map1.insert(pair<int, int>(3, 30));
    map1.insert(pair<int, int>(4, 70));
    map1.insert(pair<int, int>(5, 50));
    map1.insert(pair<int, int>(6, 60));
    const map<int, int, compare> map2 = map1;
    for (map<int, int>::const_iterator it = map2.begin(); it != map2.end(); ++it) // 这里需要注意const_itreator为一种类型，不可以认为等同于const iterator
    {
        cout << "key:" << (*it).first << " value:" << (*it).second << endl;
    }
    // printf(map2);
}
int main()
{
    clock_t start_time, end_time;
    start_time = clock(); // 获取开始执行时间
    // test01();
    // test02();
    // test03();
    // test04();
    test05();
    // test06();
    // test07();
    end_time = clock();
    double Times = (double)(end_time - start_time);
    cout << Times << endl;
    return 0;
}