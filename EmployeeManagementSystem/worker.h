#pragma once // 防止头文件被重复包含
#include <iostream>
#include <string>
using namespace std;
class Worker
{
public:
    virtual void ShowInfo() = 0;
    virtual string GetDeptName() = 0;
    int m_ID;
    string m_Name;
    int m_DeptID;
};