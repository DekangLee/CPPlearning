#ifndef __TEACHERT__
#define __TEACHERT__
#include "identity.h"
#include <windows.h>
#include <string>
#include "orderReserve.h"
#include <vector>
using namespace std;
class teacher : public identity
{
public:
    teacher();
    teacher(int id, string name, string pwd);
    virtual void showMenu();
    // 查看预约
    void showOrder();
    // 审核预约
    void verifyOrder();

};
void studentMenu(identity *person);
#endif