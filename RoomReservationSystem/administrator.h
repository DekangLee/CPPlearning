#ifndef __ADMINISTRATOR__
#define __ADMINISTRATOR__
#include <vector>
#include <algorithm>
#include <conio.h>
#include "identity.h"
#include "student.h"
#include "teacher.h"
#include "computerRoom.h"
#include <string>
#include "globalFile.h"
#include <fstream>
using namespace std;
class administrator : public identity
{
public:
    administrator();
    administrator(int id, string name, string pwd);
    virtual void showMenu();  // 
    // 添加账号
    void addPerson();
    // 账户信息
    void showPerson();
    // 修改账户信息
    void alterPerson();
    // 查看机房信息
    void showRoom();
    // 清空预约记录
    void clearRcoder();
    // 初始化student 与 teacher容器
    void initVector();
    // 检查是否有重复
    bool checkRepeat(int id, int type);
    // 更新学生信息
    void updateStu();
    // 更新教师信息
    void updateTea();
    int checkPwd();
    vector<student> sVec;
    vector<teacher> tVec;
    vector<computerRoom>compVec;
};
void adminMenu(identity *person);
void AdnimGetPwd(string &str);
#endif