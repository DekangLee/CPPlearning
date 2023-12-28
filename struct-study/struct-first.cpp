#include <iostream>
#include <string>
using namespace std;
// 创建结构体
struct student
{
    string name;
    int age;
    int score;
};
void test01(student s)
{
    s.age = 1;
}
void test02(student *s)
{
    s->age = 1;
}
student &test03(student &s)
{
    s.age += 1;
    return s;
}
string operator+(const string &s, int i)
{

    return s + to_string(i);
}
// 内置参数不能用操作符重载
// char &operator+(const char &s1, const char &s2)
// {

//     return s1+s2;
// }
ostream &operator<<(ostream &cout, student &s)
{
    string out = "Age:";
    out = out + s.age;
    out = out + " Name:";
    out = out + s.name;
    out = out + " Score:";
    out = out + s.score;
    cout << out;
    return cout;
}

// char *contact(const char *c1, const char *c2)
// {
// int lenth1 = sizeof(c1);
// int lenth2 = sizeof(c2);
// char *c_temp;

// }
int main()
{
    struct student s1 = {"李德康", 18, 100};
    struct student s2 = {"白文超", 80, 59};
    struct student s3 = {"胡文杰", 90, 59};
    struct student s4 = s1;
    // char *s = contact("hello", "world");
    // cout << s1 << endl;
    cout << s3 << endl;
    int a = 123;
    string s("hello");
    s = s+ a+'*'; // string里的+=号与常规不同！！！！！！！！！！！
    cout << s + a << endl;
    system("pause");
    return 1;
}