#ifndef __ORDERRESERVE__
#define __ORDERRESERVE__
using namespace std;
#include <iostream>
#include <fstream>
#include<map>
#include<string>
#include "globalFile.h"
class order
{
public:
    // 构造函数
    order();
    // 更新预约记录
    void updateOrder();
    // 预约记录条数
    int m_size;
    // 信息
    map<int,map<string, string>> m_orderData;

};
#endif