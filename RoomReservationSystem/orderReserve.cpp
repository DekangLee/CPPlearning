#include "orderReserve.h"
order::order()
{
    ifstream ifs(OrderFile, ios::in);
    string name;    // 学生姓名
    string date;    // 时间
    string interval; // 时间段
    string stuId;   // 学号
    string room;    // 机房号
    string status;  // 预约状态
    this->m_size = 0;
    while (ifs >> date && ifs >> interval && ifs >> stuId && ifs >> name && ifs >> room && ifs >> status)
    {
        // cout << date << " " << interve << " " << stuId << " " << name << " " << room << " " << status << endl;
        string key;
        string value;
        map<string, string> m;
        int pos = date.find(":");
        key = date.substr(0, pos);
        value = date.substr(pos + 1, -1);
        m.insert(make_pair(key, value));
        pos = interval.find(":");
        key = interval.substr(0, pos);
        value = interval.substr(pos + 1, -1);
        m.insert(make_pair(key, value));
        pos = stuId.find(":");
        key = stuId.substr(0, pos);
        value = stuId.substr(pos + 1, -1);
        m.insert(make_pair(key, value));
        pos = name.find(":");
        key = name.substr(0, pos);
        value = name.substr(pos + 1, -1);
        m.insert(make_pair(key, value));
        pos = room.find(":");
        key = room.substr(0, pos);
        value = room.substr(pos + 1, -1);
        m.insert(make_pair(key, value));
        pos = status.find(":");
        // cout<<"status:"<<status<<endl;
        // cout<<"pos:"<<pos<<endl;
        key = status.substr(0, pos);
        value = status.substr(pos + 1, -1);
        m.insert(make_pair(key, value));
        this->m_orderData.insert(make_pair(this->m_size, m));
        this->m_size++;
    }
    // for (auto _m1 : this->m_orderData)
    // {
    //     cout << _m1.first << ":";
    //     for (auto _m2 : _m1.second)
    //     {
    //         cout << _m2.first << ":" << _m2.second << " ";
    //     }
    //     cout << endl;
    // }
}
// 更新预约记录
void order::updateOrder()
{
    if (this->m_size == 0)
    {
        return;
    }
    else
    {
        ofstream ofs(OrderFile, ios::trunc);
        for (int i = 0; i < this->m_size; i++)
        {
            // date:1 interval:1 stuId:1 stuName:李德康 room:2 status1
            ofs << "date:" << this->m_orderData[i]["date"] << " ";
            ofs << "interval:" << this->m_orderData[i]["interval"] << " ";
            ofs << "stuId:" << this->m_orderData[i]["stuId"] << " ";
            ofs << "stuName:" << this->m_orderData[i]["stuName"] << " ";
            ofs << "room:" << this->m_orderData[i]["room"] << " ";
            ofs << "status:" << this->m_orderData[i]["status"] << " ";
        }
        ofs<<endl;
        ofs.close();
    }
}