#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <ctime>
#include <cstdlib>
#include <algorithm> // 包含头文件
#include <functional>
#include <numeric>
#include "commen.hpp"
void myPrint(int num)
{
    cout<<num<<" ";
}
// 常用的算术生成算法
void test01()
{
    vector<int> v;
    for (int i = 0; i < 5; i++)
    {
        v.push_back(GenNum(0, 20));
    }
    print(v);
    int sum = accumulate(v.begin(), v.end(), 0);
    cout << "sum = " << sum << endl;
}
// fill算法
void test02()
{
    vector<int> v;
    v.resize(10);
    print(v);
    fill(v.begin(), v.end(), 3);
    print(v);
}
// set集合算法
void test03()
{
    vector<int> v1;
    vector<int> v2;
    vector<int> Tarv;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(GenNum(0, 10));
        v2.push_back(GenNum(0, 10));
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    cout << "v1 :" << v1 << endl;
    cout << "v2 :" << v2 << endl;
    Tarv.resize(min(v1.size(), v2.size()));
    vector<int>::iterator itEnd = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), Tarv.begin()); // 必须是有序序列
    auto _fprint = [](int num)
    {
        cout << num << " ";
    };
    for_each(Tarv.begin(), itEnd, _fprint);
}
void test04()
{
    set<int> set1;
    set<int> set2;
    set<int> Tars;
    for (int i = 0; i < 10; i++)
    {
        set1.emplace(GenNum(0, 10));
        set1.emplace(GenNum(0, 10));
    }
    cout << "set1 :" << set1 << endl;
    cout << "set2 :" << set2 << endl;
    // set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), Tars.begin()); // set 容器的迭代器仅可以访问不可以修改
    cout << "Tars :" << Tars << endl;
}
// 求两个容器的并集union
void test05()
{
    vector<int> v1;
    vector<int> v2;
    vector<int> Tarv;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(GenNum(0, 10));
        v2.push_back(GenNum(0, 10));
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    cout << "v1 :" << v1 << endl;
    cout << "v2 :" << v2 << endl;
    Tarv.resize(v1.size() + v2.size());
    vector<int>::iterator itEnd = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), Tarv.begin());
    auto _fprint = [](const int &num)
    {
        cout << num << " ";
    };
    for_each(Tarv.begin(), itEnd, _fprint);
}
// 求两个容器的差集
void test06()
{
    vector<int> v1;
    vector<int> v2;
    vector<int> Tarv;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(GenNum(0, 10));
        v2.push_back(GenNum(0, 10));
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    cout << "v1 :" << v1 << endl;
    cout << "v2 :" << v2 << endl;
    Tarv.resize(v1.size());
    vector<int>::iterator itEnd = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), Tarv.begin());
    for_each(Tarv.begin(), itEnd, myPrint);
    cout<<endl;
}
int main()
{
    clock_t start_time, end_time;
    start_time = clock(); // 获取开始执行时间
    // test01();
    // test02();
    // test03();
    // test04();
    // test05();
    test06();
    // test07();
    end_time = clock();
    double Times = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    cout << "程序运行" << Times << "s" << endl;
    system("pause");
    return 0;
}