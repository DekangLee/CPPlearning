#pragma once // 防止头文件被重复包含
#include <iostream>
#include "employee.h"
#include "worker.h"
#include "Boss.h"
#include "manager.h"
#include <fstream>
#define FILENAME "epmFile.txt"
using namespace std;
class WorkManager
{
public:
    WorkManager();
    ~WorkManager();
    void showMemu();
    void exitSystem();
    void AddWorker();
    void save();
    int getEmpNumber();
    void Init_Emp();
    void Show_Emp();
    int MemberIsExist(int id); // 判断职工是否存在，若存在返回职工所在数组的索引，不存在返回-1
    void DeleteWorker();
    void SortAscend();  // 按照编号升序排列
    void SortDescend();
    void Mod_Emp();
    void Find_Emp();
    void Clean_file();
    int m_EmpNum;       // 记录职工人数
    Worker **m_EmpArry; // 职工数组指针
    bool m_FileIsEmpty; // 判断文件是否为空
};