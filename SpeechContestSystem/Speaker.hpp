#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
class Speaker
{
public:
    Speaker()
    {
        m_name = " ";
        m_score[0] = 0;
        m_score[1] = 0;
    }
    Speaker(string name)
    {
        m_name = name;
        m_score[0] = 0;
        m_score[1] = 0;
    }
    string m_name;
    double m_score[2];
};
template <class T>
void print(const vector<T> &v)
{
    for (auto elem : v)
    {
        cout << elem << " ";
    }
    cout << endl;
}
template <class T1, class T2>
void print(const map<T1, T2> &m)
{
    for (auto elem : m)
    {
        cout << elem.second << endl;
    }
}