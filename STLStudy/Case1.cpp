// #include <iostream>
// #include <string>
// #include <map>
// #include <vector>
// #include <ctime>
// #include <cstdlib>
// #include <algorithm>
// using namespace std;
// #define CHEHUA 1
// #define MEISHU 2
// #define YANFA 3
// // class Worker; 这种声明不行！！！！！
// class Worker
// {
// public:
//     string m_name;
//     int m_salary;
//     Worker(){};
//     Worker(string name, int salary)
//     {
//         m_name = name;
//         m_salary = salary;
//     }
// };
// ostream &operator<<(ostream &cout, const Worker &worker)
// {
//     cout << "name:" << worker.m_name << " salary:" << worker.m_salary;
//     return cout;
// }
// template <class T>
// void print(T elem)
// {
//     for (auto a : elem)
//     {
//         cout << a << endl;
//     }
// }
// void print(const multimap<int, Worker> &group)
// {
//     for (auto elem : group)
//     {
//         cout << "Department:" << elem.first << " Person:" << elem.second << endl;
//     }
// }

// void createWorker(vector<Worker> &v)
// {
//     string nameSeed = "ABCDEFGHJKLM";
//     for (int i = 0; i < 10; i++)
//     {
//         string name = "员工";
//         name += nameSeed[i];
//         int salary = rand() % 500 + 500;
//         v.push_back(Worker(name, salary));
//     }
// }
// void workerGroup(vector<Worker> &v, multimap<int, Worker> &group)
// {
//     srand(time(0));
//     for (auto member : v)
//     {
//         int dep = rand() % 3 + 1;
//         group.insert(make_pair(dep, member));
//     }
// }
// void showGroup(const multimap<int, Worker> &group)
// {
//     auto it = group.find(CHEHUA);
//     int count = group.count(CHEHUA);
//     int index = 0;
//     cout << "--------------------" << endl;
//     for (; it != group.end() && index < count; it++, index++)
//     {
//         cout << "策划部门：" << it->second << endl;
//     }
//     it = group.find(MEISHU);
//     count = group.count(MEISHU);
//     index = 0;
//     cout << "--------------------" << endl;
//     for (; it != group.end() && index < count; it++, index++)
//     {
//         cout << "美术部门：" << it->second << endl;
//     }
//     it = group.find(YANFA);
//     count = group.count(YANFA);
//     index = 0;
//     cout<<"--------------------"<<endl;
//     for (; it != group.end() && index < count; it++, index++)
//     {
//         cout << "研发部门：" << it->second << endl;
//     }
// }
// void test01()
// {
//     vector<Worker> v;
//     createWorker(v);
//     print(v);
//     multimap<int, Worker> group;
//     workerGroup(v, group);
//     showGroup(group);
//     // print(group);
// }
// int main()
// {
//     clock_t start_time, end_time;
//     start_time = clock(); // 获取开始执行时间
//     test01();
//     // test02();
//     // test03();
//     // test04();
//     // test05();
//     // test06();
//     // test07();
//     end_time = clock();
//     double Times = (double)(end_time - start_time)/CLOCKS_PER_SEC;
//     cout << "程序运行" << Times << "s" << endl;
//     system("pause");
//     return 0;
// }