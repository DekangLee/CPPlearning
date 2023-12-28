#ifndef __IDENTITYH_
#define __IDENTITYH_
#include <iostream>
#include <string>
using namespace std ;
class identity
{
public:
    virtual void showMenu() = 0;
    string m_name;  // 用户名
    string m_pwd;   // 密码
    int m_id;
};
#endif