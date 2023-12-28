#pragma once
#include<iostream>
#include <string>
using namespace std;
class computerRoom
{
public:
    computerRoom();
    computerRoom(int id, int Maxnum);
    int getId() const;
    int getNum() const;
    void setId(int id);
    void setNum(int Maxnum);
private:
    int m_RoomId;
    int m_MaxNum;
};
