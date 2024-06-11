#include <iostream>
#include <string>
#include <time.h>
#include <fstream> // 包含头文件
#include <vector>
#include <regex>
using namespace std;
int regexSplit(string &str, const string str_reg, vector<string> &vect, int pos)
{
    if (pos != -1)
        pos = 0; // pos=0 匹配到的位置，pos=-1匹配位置的前一字串
    regex Pattern(str_reg);
    sregex_token_iterator it(str.begin(), str.end(), Pattern, pos);
    sregex_token_iterator end;
    for (; it != end; it++)
        vect.push_back(*it);
    return vect.size(); // if 0 没有匹配到，else 匹配到的个数
}
// 文本文件写文件
void test01()
{
    ofstream ofs;
    ofs.open("test.xlsx", ios::app);
    ofs << "姓名：李德康" << endl;
    ofs << "性别：男" << endl;
    ofs << "年龄：18" << endl;
    ofs.close();
}
void test02()
{
    ifstream ifs;
    ifs.open("text.txt", ios::in);
    if (!ifs.is_open())
    {

        cout << "文件打开失败!!" << endl;
        return;
    }
    // 第一种读取方式
    // char buff[1024] = {0};
    // while (ifs >> buff)
    // {
    //     cout << buff << endl;
    // }
    // 第二种读取方式
    // char buff[1024] = {0};
    // while (ifs.getline(buff,sizeof(buff)) )
    // {
    //     cout << buff << endl;
    // }
    // 第三种读取方式
    // string buff;
    // while (getline(ifs,buff))
    // {
    //     cout<<buff<<endl;
    // }
    // 第三种读取方式
    string buff;
    while (getline(ifs, buff))
    {
        cout << buff << endl;
    }
    // 第四种读取方式
    // char c;
    // while ((c = ifs.get()) != EOF) // EOF为 End Of File
    // {
    //     cout << c;
    // }

    // ifs.close();
}
void test03()
{
    // char a[5]={0};
    // int i =0;
    // while ((a[i]=getchar())!='\040')
    // {
    //     i++;
    // }
    // cout<<<endl;
}
class Person
{
public:
    char m_Name[64];
    int m_Age;
};
// 二进制文件读写
void test04()
{
    ofstream ofs;
    ofs.open("Person.txt", ios::out | ios::binary);
    vector<Person> P;
    P.push_back(Person{"李四", 18});
    P.push_back(Person{"张三", 16});
    P.push_back(Person{"王五", 27});
    for (auto &ele : P)
    {
        ofs.write((const char *)&ele, sizeof(Person));
    }
    // cout <<
    ofs.close();
}
// 二进制文件读取
void test05()
{
    ifstream ifs;
    ifs.open("Person.txt", ios::out | ios::binary);
    if (!ifs.is_open())
    {
        cout << "打开文件失败" << endl;
        return;
    }
    while (ifs)
    {
        Person p1;
        ifs.read((char *)&p1, sizeof(Person));
        cout << p1.m_Name << "的年龄" << p1.m_Age << endl;
    }
}
void test06()
{
    ifstream ifs;
    ifs.open("workTime.txt", ios::in);
    if (!ifs.is_open())
    {
        cout << "打开文件失败" << endl;
        return;
    }
    vector<string> v_time;
    string buff;
    while (getline(ifs, buff))
    {
        v_time.push_back(buff);
    }
    vector<int> v_temp;
    for (vector<string>::iterator it = v_time.begin(); it != v_time.end(); it++)
    {

        cout << *it << endl;
    }
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
    end_time = clock();
    double Times = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    cout << "程序运行时间：" << Times << "s" << endl;
    // system("pause");

    return 1;
}