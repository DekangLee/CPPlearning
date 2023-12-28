#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include<vector>
using namespace std;
ostream &operator<<(ostream &cout, const vector<int> &elem)
{
    for (auto a : elem)
    {
        cout << a << " ";
    }
    return cout;
}
template<class T>
ostream &operator<<(ostream &cout, const set<T> &obj)
{
    for (auto a : obj)
    {
        cout << a << " ";
    }
    return cout;
}
template <class T>
void print(const T &v)
{
    for (auto a : v)
    {
        cout << a << " ";
    }
    cout << endl;
}

int GenNum(int l, int r)
{
    return rand() % (r - l) + l;
}
class Person
{
    friend bool operator == (const Person &p1, const Person &p2);
public:
    Person(string name, int age)
    {
        this->_name = name;
        this->_age = age;
    }
    string _name;
    int _age;
};
ostream &operator<<(ostream &cout, Person p)
{
    cout << "name:" << p._name << " age:" << p._age;
    return cout;
}
void print(const vector<Person> &p)
{
    for(auto a:p)
    {
        cout<<a<<endl;
    }
}
bool operator == (const Person &p1, const Person &p2)
{
    if(p1._name == p2._name && p1._age == p2._age)
    {
        return true;
    }
    else
        return false;
}