#pragma once
#include <iostream>
#include <string>
#include "worker.h"
using namespace std;
class Maneger : public Worker
{
public:
    Maneger(int ID, string Name, int DeptID);
    virtual void ShowInfo();
    virtual string GetDeptName();
};