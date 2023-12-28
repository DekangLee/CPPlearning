#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <cstdlib>
#include <vector>
#include <algorithm>
// string 的构造函数
using namespace std;
template <class T>
int substrFind(T obj, const T &sub)
{
    int count = 0;
    while (obj.find(sub) != string::npos)
    {
        obj.erase(obj.find(sub), sub.size());
        count++;
    }
    return count;
}
template <class T>
int substrFind(T obj, const char *sub)
{
    int count = 0;
    string temp;
    temp = sub;
    while (obj.find(temp) != string::npos)
    {
        obj.erase(obj.find(temp), temp.size());
        count++;
    }
    return count;
}
string numberFind(string email)
{
    return email.substr(0, email.find("@"));
}
void test01()
{
    string s1;           // 默认构造
    string s2("李德康"); // 有参构造1
    char c[] = "Hello world !";
    const char *c1 = "How smart you are!";
    // char *c1 = "How smart you are!";  // 需要使用const限定符，否则会警告
    // c1[0] = 'h';  // 不被允许
    string s3(c);
    string s4(2, 'a'); // 注意是'a' 不是"a"!!
    string s5(c1);
    cout << "s1 :" << s1 << endl;
    cout << "s2 :" << s2 << endl;
    cout << "s3 :" << s3 << endl;
    cout << "s4 :" << s4 << endl;
    cout << "s5 :" << s5 << endl;
}
// string 的赋值操作
void test02()
{
    string s1 = "Hello LDK";
    string s2 = s1; // 属于深拷贝
    string &s21 = s2;
    s2[0] = 'h';
    char c[] = "I love c++";
    string s3;
    s3.assign(c);
    string s4;
    s4.assign("Today is good day.", 18);
    string s5;
    s5.append(s4);
    cout << "s1 :" << s1 << endl;
    cout << "s2 :" << s2 << endl;
    cout << "s21 :" << s21 << endl;
    cout << "s3 :" << s3 << endl;
    cout << "s4 :" << s4 << endl;
    cout << "s5 :" << s5 << endl;
}
// string 的拼接
void test03()
{
    string s1("Li");
    cout << "s1 :" << s1 << endl;
    s1 += " Dekang";
    cout << "s1 :" << s1 << endl;
    char c[] = " like playing game.";
    s1.append(c, 0, -1); // -1表示最后一个此用法类似于Python   参数2为截取的初始位置，参数3为截取的个数
    cout << "s1 :" << s1 << endl;
    string s2("--王者农药");
    cout << s1 + s2 << endl;
}
// 字符串的查找与替换
void test04()
{
    string s1 = "abcdefcabc";
    cout << s1.find("ab") << endl;  // 从左往右找
    cout << s1.rfind("ab") << endl; // 从右往左找
    s1.replace(1, 3, "11111");      // 从第一个位置起替换所有的参数
    cout << s1 << endl;
    string s2 = "hlekk";
    s1.replace(1, -1, s2); // -1表示一直到尾部，缺少的部分将会被直接截取掉
    cout << s1 << endl;
}
// 字符串比较
void test05()
{
    string s1 = "hello"; // 字符串比较实际是从左到右比较ASC码值
    string s2 = "hello ";
    if (s1.compare(s2) == 0) //  s1 == s2 返回值为0  实际是用于比较两个字符串是否相等，判断大小的意义不大
    {
        cout << "s1 == s2" << endl;
    }
    else if (s1.compare(s2) == 1) //  s1 > s2 返回值为1
    {
        cout << "s1 > s2" << endl;
    }
    else if (s1.compare(s2) == -1) //  s1 < s2 返回值为-1
    {
        cout << "s1 < s2" << endl;
    }
}
// 字符串访问
void test06()
{
    string s1 = "Hello world!";

    for (int i = 0; i < s1.size(); i++)
    {
        // s1[i]  ='l';
        s1.at(i) = 'd'; // .at()函数的返回值是引用，可以对str读写
    }
    s1.at(1);
    for (auto &a : s1)
    {
        // a = 'd';
        cout << a;
    }
    cout << endl;
}
void test07()
{
    string s1 = "Hello world!";
    s1.insert(1, "F"); // 此处必须是字符串"F" 不能是字符'F'
    cout << "s1 = " << s1 << endl;
    string s2 = "Li Dekang"; // 这里需要注意插入与替换的区别，插入保留原有的字符串，替换不会
    s1.insert(6, s2);
    cout << "s1 = " << s1 << endl;
}
// 截取子串
void test08()
{
    // string s1 = "Hello world!";
    // string subs1 = s1.substr(1, 3); // 这里注意返回值不是引用 是临时变量
    // cout << "substr = " << subs1 << endl;
    string email1 = "372534785@qq.com";
    // cout<<numberFind(email1)<<endl;
    string email2 = email1;
    for (auto a : email2)
    {
        email1.erase(email1.find(a), 1);
    }
    cout << email1.size() << endl;
}
void CompCase()
{
    // ofstream ofs;
    // ofs.open("TestFile.txt",ios::out);
    // if(!ofs.is_open())
    // {
    //     cout<<"打开文件失败"<<endl;
    //     return;
    // }
    // string buff;
    // while((buff=getchar())!=" ")
    // {
    //     ofs<<buff;
    // }
    ifstream ifs;
    ifs.open("TestFile.txt", ios::out);
    if (!ifs.is_open())
    {
        cout << "打开文件失败" << endl;
        return;
    }
    char buff;
    string Filecontent;
    while ((buff = ifs.get()) != EOF)
    {
        string temp;
        temp = buff;
        Filecontent.append(temp);
    }

    cout << Filecontent << endl;
    string sub1 = "ldk";
    cout << substrFind(Filecontent, sub1) << endl;
    // cout<<substrFind(Filecontent,"ldk")<<endl;
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
    // test06();
    // test07();
    // test08();
    // CompCase();
    // string date = "date:123";
    // cout<<date.substr(5,-1)<<endl;
    system("pause");
    end_time = clock();
    double Times = (double)(end_time - start_time);
    return 0;
}