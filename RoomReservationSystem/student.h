#ifndef __STUDENTH__
#define __STUDENTH__
#include "identity.h"
#include "computerRoom.h"
#include "globalFile.h"
#include "orderReserve.h"
#include <string>
#include <vector>
#include <set>
#include <fstream>
#include <windows.h>
using namespace std;
class student : public identity
{
public:
    student();
    student(int id, string name, string pwd);
    virtual void showMenu();
    // 申请预约
    void applyOrder();
    void initStatus();
    // 查看预约
    void showMyOrder();
    void showAllOrder();
    // 取消预约
    void cancelOrder();
    vector<computerRoom>compVec;
};
void teacherMenu(identity *student);
#endif