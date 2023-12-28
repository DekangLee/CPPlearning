#pragma once // 防止头文件被重复包含
#include <iostream>
#include <string>
#include "worker.h"
using namespace std;
class Boss : public Worker
{
public:
    Boss(int ID, string Name, int DeptID);
    virtual void ShowInfo();
    virtual string GetDeptName();
};