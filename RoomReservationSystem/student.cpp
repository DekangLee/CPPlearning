#include "student.h"
student::student()
{
    this->m_id = -1;
    this->m_name = "";
    this->m_pwd = "";
}
student::student(int id, string name, string pwd)
{
    this->m_id = id;
    this->m_name = name;
    this->m_pwd = pwd;
    this->initStatus();
}
void student::initStatus()
{
    int id;
    int MaxNum;
    ifstream ifs(RoomFile, ios::in);
    if (!ifs.is_open())
    {
        cout << "文件打开失败！" << endl;
        return;
    }
    computerRoom compRoom;
    while (ifs >> id && ifs >> MaxNum)
    {
        compRoom.setId(id);
        compRoom.setNum(MaxNum);
        this->compVec.push_back(compRoom);
    }
}
void student::showMenu()
{
    system("cls");
    cout << "====================欢迎" << this->m_name << "同学使用系统===================" << endl;
    cout << "\t\t ----------------------------" << endl;
    cout << "\t\t|                            |" << endl;
    cout << "\t\t|        1. 申请预约         |" << endl;
    cout << "\t\t|                            |" << endl;
    cout << "\t\t|        2. 查看我的预约     |" << endl;
    cout << "\t\t|                            |" << endl;
    cout << "\t\t|        3. 查看所有预约     |" << endl;
    cout << "\t\t|                            |" << endl;
    cout << "\t\t|        4. 取消预约         |" << endl;
    cout << "\t\t|                            |" << endl;
    cout << "\t\t|        0. 注销登录         |" << endl;
    cout << "\t\t|                            |" << endl;
    cout << "\t\t ----------------------------" << endl;
    cout << "输入您的选择：";
}
// 申请预约
void student::applyOrder()
{
    system("cls");
    cout << "机房开放时间为周一至周五" << endl;
    cout << "请输入预约时间" << endl;
    cout << "\t\t ---------------" << endl;
    cout << "\t\t|    1. 周一    |" << endl;
    cout << "\t\t|    2. 周二    |" << endl;
    cout << "\t\t|    3. 周三    |" << endl;
    cout << "\t\t|    4. 周四    |" << endl;
    cout << "\t\t|    5. 周五    |" << endl;
    cout << "\t\t|    0. 取消    |" << endl;
    cout << "\t\t ---------------" << endl;
    cout << "输入您的选择：";
    int date = 0; // 日期
    set<int> Dateset = {1, 2, 3, 4, 5};
    int interval; // 时间段
    int room;     // 机房号
    while (true)
    {
        cin >> date;
        if (Dateset.count(date))
        {
            // cout<<"预约操作"<<endl;
            // system("pause");
            break;
        }
        else if (date == 0)
        {
            // cout<<"date = "<<date<<endl;

            cout << "正在退出！";
            for (int i = 0; i < 10; i++)
            {
                cout << "%";
                Sleep(500);
            }
            // system("pause");
            system("cls");
            // break;
            return;
        }
        else if (Dateset.find(date) == Dateset.end())
        {
            cout << "输入有误请重新输入,输零退出：";
            // system("pause");
            // system("cls");
        }
    }
    system("cls");
    cout << "请选择时间段" << endl;
    cout << "\t\t ---------------" << endl;
    cout << "\t\t|    1. 上午    |" << endl;
    cout << "\t\t|    2. 下午    |" << endl;
    cout << "\t\t ---------------" << endl;
    cout << "输入您的选择：";
    while (true)
    {
        cin >> interval;
        if (interval == 1 || interval == 2)
        {
            break;
        }
        else if (interval == 0)
        {
            // cout<<"date = "<<date<<endl;
            cout << "正在退出！";
            for (int i = 0; i < 10; i++)
            {
                cout << "%";
                Sleep(500);
            }
            system("cls");
            // break;
            return;
        }
        else
        {
            cout << "输入有误请重新输入,输0退出：";
            // system("pause");
            // system("cls");
        }
    }
    system("cls");
    cout << "请选择机房" << endl;
    cout << "\t\t --------------------" << endl;
    for (const auto &a : this->compVec)
    {
        cout << "\t\t|   "
             << "机房:" << a.getId() << " 容量:" << a.getNum() << "   |" << endl;
    }
    cout << "\t\t --------------------" << endl;
    cout << "输入您的选择：";
    while (true)
    {
        cin >> room;
        if (room >= 1 && room <= this->compVec.size())
        {
            break;
        }
        else if (interval == 0)
        {
            // cout<<"date = "<<date<<endl;
            cout << "正在退出！";
            for (int i = 0; i < 10; i++)
            {
                cout << (i + 1) * 10 << "%";
                Sleep(500);
                printf("\b\b\b");
            }
            system("cls");
            // break;
            return;
        }
        else
        {
            cout << "输入有误请重新输入,输0退出：";
            // system("pause");
            // system("cls");
        }
    }
    cout << "预约成功！审核中" << endl;
    ofstream ofs(OrderFile, ios::app);
    ofs << "date:" << date << " ";
    ofs << "interval:" << interval << " ";
    ofs << "stuId:" << this->m_id << " ";
    ofs << "stuName:" << this->m_name << " ";
    ofs << "room:" << room << " ";
    ofs << "status:" << 1;
    ofs<<endl;
    system("pause");
}
// 查看预约
void student::showMyOrder()
{
    system("cls");
    order _order;
    map<int, string> week = {make_pair(1, "周一"), make_pair(2, "周二"), make_pair(3, "周三"), make_pair(4, "周四"), make_pair(5, "周五")};
    if (_order.m_size == 0)
    {
        cout << "无预约记录" << endl;
        system("pause");
        return;
    }
    for (int i = 0; i < _order.m_size; i++)
    {
        if (this->m_id == atoi(_order.m_orderData[i]["stuId"].c_str()))
        {
            int date = atoi(_order.m_orderData[i]["date"].c_str());
            string status = "状态:";
            if (_order.m_orderData[i]["status"] == "1")
            {
                status += "审核中";
            }
            else if (_order.m_orderData[i]["status"] == "2")
            {
                status += "预约成功";
            }
            else if (_order.m_orderData[i]["status"] == "-1")
            {
                status += "预约失败";
            }
            else if (_order.m_orderData[i]["status"] == "3")
            {
                status += "已取消";
            }
            cout << "\t\t -----------------------" << endl;
            cout << "\t\t|    预约时间:" << week[date] << "\t|" << endl;
            cout << "\t\t|    时间段:" << (_order.m_orderData[i]["interval"] == "1" ? "上午" : "下午") << "\t|" << endl;
            cout << "\t\t|    机房:" << _order.m_orderData[i]["room"] << "\t\t|" << endl;
            cout << "\t\t|    " << status << "\t|" << endl;
            cout << "\t\t -----------------------" << endl;
        }
    }

    system("pause");
    system("cls");
}
void student::showAllOrder()
{
    system("cls");
    order _order;
    if (_order.m_size == 0)
    {
        cout << "无预约记录" << endl;
        system("pause");
        return;
    }
    map<int, string> week = {make_pair(1, "周一"), make_pair(2, "周二"), make_pair(3, "周三"), make_pair(4, "周四"), make_pair(5, "周五")};
    cout << "  --------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < _order.m_size; i++)
    {

        int date = atoi(_order.m_orderData[i]["date"].c_str());
        string status = "状态:";
        if (_order.m_orderData[i]["status"] == "1")
        {
            status += "审核中";
        }
        else if (_order.m_orderData[i]["status"] == "2")
        {
            status += "预约成功";
        }
        else if (_order.m_orderData[i]["status"] == "-1")
        {
            status += "预约失败";
        }
        else if (_order.m_orderData[i]["status"] == "3")
        {
            status += "已取消";
        }
        cout << i + 1;
        cout << " |学号:" << _order.m_orderData[i]["stuId"];
        cout << "\t|姓名:" << _order.m_orderData[i]["stuName"];
        cout << "\t|预约时间:" << week[date] << " ";
        cout << "\t|时间段:" << (_order.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
        cout << "\t|机房:" << _order.m_orderData[i]["room"];
        cout << "\t|" << status << "\t|" << endl;
    }
    cout << "  --------------------------------------------------------------------------------------" << endl;
    system("pause");
}
// 取消预约
void student::cancelOrder()
{
    system("cls");
    order _order;
    if (_order.m_size == 0)
    {
        cout << "无预约记录" << endl;
        system("pause");
        return;
    }
    vector<int> v_num;
    int number = 1;
    cout << "选择需要取消的预约" << endl;
    map<int, string> week = {make_pair(1, "周一"), make_pair(2, "周二"), make_pair(3, "周三"), make_pair(4, "周四"), make_pair(5, "周五")};
    cout << "  --------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < _order.m_size; i++)
    {
        if (this->m_id == atoi(_order.m_orderData[i]["stuId"].c_str()))
        {
            if (_order.m_orderData[i]["status"] == "1" || _order.m_orderData[i]["status"] == "2")
            {
                v_num.push_back(i);
                int date = atoi(_order.m_orderData[i]["date"].c_str());
                string status = "状态:";
                if (_order.m_orderData[i]["status"] == "1")
                {
                    status += "审核中";
                }
                else if (_order.m_orderData[i]["status"] == "2")
                {
                    status += "预约成功";
                }
                else if (_order.m_orderData[i]["status"] == "-1")
                {
                    status += "预约失败";
                }
                else if (_order.m_orderData[i]["status"] == "3")
                {
                    status += "已取消";
                }
                cout << number;
                cout << " |预约时间:" << week[date] << " ";
                cout << "\t|时间段:" << (_order.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
                cout << "\t|机房:" << _order.m_orderData[i]["room"];
                cout << "\t|" << status << "\t|" << endl;
                number++;
            }
        }
    }
    cout << "  --------------------------------------------------------------------------------------" << endl;
    cout << "请输入需要取消的预约编号(输0退出):" << endl;
    int select = 0;
    while (true)
    {
        cin >> select;
        if (select >= 0 && select <= v_num.size())
        {
            if (select == 0)
            {
                break;
            }
            else
            {
                _order.m_orderData[v_num[select - 1]]["status"] = "3";
                _order.updateOrder();
                cout << "取消预约成功！" << endl;
                break;
            }
        }
        else
        {
            cout << "输入有误重新输入" << endl;
        }
    }
    system("pause");
}
void studentMenu(identity *person)
{
    int select = -1;
    student *stu = (student *)person;
    while (true)
    {
        person->showMenu();
        cin >> select;
        switch (select)
        {
        case 1: // 申请预约
            stu->applyOrder();
            break;
        case 2: // 查看我的预约
            stu->showMyOrder();
            break;
        case 3: // 查看所有预约
            stu->showAllOrder();
            break;
        case 4: // 取消预约
            stu->cancelOrder();
            break;
        case 0:
            delete stu;
            cout << "欢迎下次使用,";
            cout << "正在退出！";
            for (int i = 0; i < 10; i++)
            {
                cout << (i + 1) * 10 << "%";
                Sleep(500);
                printf("\b\b\b");
            }
            system("cls");
            return;
            break;
        default:
            cout << "输入有误请重新输入！" << endl;
            system("pause");
            system("cls");
            break;
        }
    }
}