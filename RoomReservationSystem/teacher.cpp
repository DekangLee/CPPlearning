#include "teacher.h"
teacher::teacher()
{
}
teacher::teacher(int id, string name, string pwd)
{
    this->m_id = id;
    this->m_name = name;
    this->m_pwd = pwd;
}
void teacher::showMenu()
{
    system("cls");
    cout << "====================欢迎" << this->m_name << "老师使用系统===================" << endl;
    cout << "\t\t ----------------------------" << endl;
    cout << "\t\t|                            |" << endl;
    cout << "\t\t|        1. 查看预约         |" << endl;
    cout << "\t\t|                            |" << endl;
    cout << "\t\t|        2. 审核预约         |" << endl;
    cout << "\t\t|                            |" << endl;
    cout << "\t\t|        0. 注销登录         |" << endl;
    cout << "\t\t|                            |" << endl;
    cout << "\t\t ----------------------------" << endl;
    cout << "输入您的选择：";
}
// 查看预约
void teacher::showOrder()
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
// 审核预约
void teacher::verifyOrder()
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
    int number = 1;
    vector<int> v_num;
    cout << "  --------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < _order.m_size; i++)
    {

        int date = atoi(_order.m_orderData[i]["date"].c_str());
        string status = "状态:审核中";

        if (_order.m_orderData[i]["status"] == "1")
        {
            cout << number;
            cout << " |学号:" << _order.m_orderData[i]["stuId"];
            cout << "\t|姓名:" << _order.m_orderData[i]["stuName"];
            cout << "\t|预约时间:" << week[date] << " ";
            cout << "\t|时间段:" << (_order.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
            cout << "\t|机房:" << _order.m_orderData[i]["room"];
            cout << "\t|" << status << "\t|" << endl;
            number++;
            v_num.push_back(i);
        }
    }
    cout << "  --------------------------------------------------------------------------------------" << endl;
    cout << "请输入审核的编号(输0退出):";
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
                cout << "\t\t\t请输入审核操作:" << endl;
                cout << "\t\t\t ----------------" << endl;
                cout << "\t\t\t|  1. 审核通过   |" << endl;
                cout << "\t\t\t|  2. 审核不通过 |" << endl;
                cout << "\t\t\t ----------------" << endl;
                cout << "输入您的选择:";
                int select = -1;
                while (true)
                {
                    cin>>select;
                    if (select == 1 || select == 2)
                    {
                        if (select == 1)
                        {
                            _order.m_orderData[v_num[select - 1]]["status"] = "2";
                        }
                        else if (select == 2)
                        {
                            _order.m_orderData[v_num[select - 1]]["status"] = "-1";
                        }
                        _order.updateOrder();
                        cout << "审核操作成功！" << endl;
                        break;
                    }
                    else if (select == 0)
                    {
                        cout << "退出审核中！" << endl;
                        Sleep(700);
                        system("cls");
                        return;
                    }
                    else
                    {
                        cout<<"输入错误！请重新输入"<<endl;
                    }
                }
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
void teacherMenu(identity *person)
{
    int select = -1;
    teacher *te = (teacher *)person;
    while (true)
    {
        person->showMenu();
        cin >> select;
        switch (select)
        {
        case 1: // 查看预约
            te->showOrder();
            break;
        case 2: // 审核预约
            te->verifyOrder();
            break;
        case 0:
            delete te;
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