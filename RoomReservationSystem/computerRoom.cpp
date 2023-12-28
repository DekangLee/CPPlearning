#include "computerRoom.h"
computerRoom::computerRoom()
{
    this->m_RoomId = -1;  // 默认值
    this->m_MaxNum = -1;  
}
computerRoom::computerRoom(int id, int Maxnum)
{
    this->m_RoomId = id;
    this->m_MaxNum = Maxnum;
}
int computerRoom::getId() const
{
   return this->m_RoomId;
}
int computerRoom::getNum() const
{
   return this->m_MaxNum;
}
void computerRoom::setId(int id)
{
    this->m_RoomId = id;
}
void computerRoom::setNum(int Maxnum)
{
     this->m_MaxNum = Maxnum;
}
