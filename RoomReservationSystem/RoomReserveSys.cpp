#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include "student.h"
#include "teacher.h"
#include "administrator.h"
#include "identity.h"
#include "globalFile.h"
using namespace std;
void getPwd(string &str);
// void test();
void Login(string filename, int type)
{
    // 父类指针指向子类
    identity *person = nullptr;
    // test(); // 初始化文件
    ifstream ifs(filename, ios::in);
    if (!ifs.is_open())
    {
        cout << "文件打开失败" << endl;
        ifs.close();
        return;
    }
    int id = -1;
    string name;
    string pwd;
    if (type == 1)
    {
        cout << "请输入您的学号：";
        cin >> id;
    }
    else if (type == 2)
    {
        cout << "请输入您的职工号：";
        cin >> id;
    }
    else if (type == 3)
    {
        cout << "请输入您的账号：";
        cin >> id;
    }
    if (!cin.good())
    {
        cout << "输入非法!请输入数字" << endl;
        Sleep(1000);
        return;
    }

    // 输入姓名
    cout << "请输入您的姓名：";
    cin >> name;
    cout << "请输入您的密码：";
    // cin >> pwd;
    getPwd(pwd);
    int fid = -1;
    string fname = " ";
    string fpwd = " ";
    if (type == 1)
    {
        // 学生身份认证与操作
        bool flag = false;
        while (ifs >> fid && ifs >> fname && ifs >> fpwd)
        {
            if (fid == id && fname == name && fpwd == pwd)
            {
                flag = true;
                person = new student(id, name, pwd);
                // cout<<"认证成功！"<<endl;
                break;
            }
            // cout << "id: " << fid << " name: " << fname << " pwd: " << fpwd << endl;
        }
        if (flag)
        {
            system("cls");
            cout << "认证成功！欢迎" << ((student *)person)->m_name << "同学进入机房预约系统" << endl;
            Sleep(1000);
            studentMenu(person);
        }
        else
        {
            cout << "认证失败！" << endl;
            system("pause");
            system("cls");
            return;
        }

        // system("pause");
    }
    else if (type == 2)
    {
        // 教师身份认证与操作
        bool flag = false;
        while (ifs >> fid && ifs >> fname && ifs >> fpwd)
        {
            if (fid == id && fname == name && fpwd == pwd)
            {
                flag = true;
                person = new teacher(id, name, pwd);
                // cout<<"认证成功！"<<endl;
                break;
            }
            // cout << "id: " << fid << " name: " << fname << " pwd: " << fpwd << endl;
        }
        if (flag)
        {
            system("cls");
            cout << "认证成功！欢迎" << ((teacher *)person)->m_name << "老师进入机房预约系统" << endl;
            Sleep(1000);
            teacherMenu(person);
        }
        else
        {
            cout << "认证失败！" << endl;
            system("pause");
            system("cls");
            return;
        }
    }
    else if (type == 3)
    {
        // 管理员身份认证与操作
        bool flag = false; // 认证成功标志
        while (ifs >> fid && ifs >> fname && ifs >> fpwd)
        {
            if (fid == id && fname == name && fpwd == pwd)
            {
                flag = true;
                person = new administrator(id, name, pwd);
                // cout<<"认证成功！"<<endl;
                break;
            }
            // cout << "id: " << fid << " name: " << fname << " pwd: " << fpwd << endl;
        }
        if (flag)
        {
            system("cls");
            cout << "认证成功！欢迎管理员" << ((administrator *)person)->m_name << "进入机房预约系统" << endl;
            Sleep(1000);
            adminMenu(person);
        }
        else
        {
            cout << "认证失败！" << endl;
            system("pause");
            system("cls");
            return;
        }
    }
    else
    {
        cout << "输入有误！" << endl;
        system("pause");
        system("cls");
        return;
    }
}
int main()
{
    int select;
    // cin>>select;
    while (true)
    {
        cout << "\t\t\t|=====欢迎使用机房预约系统====|" << endl;
        cout << "\t\t\t|--------请输入您的身份-------|" << endl;
        cout << "\t\t\t|-----------------------------|" << endl;
        cout << "\t\t\t|                             |" << endl;
        cout << "\t\t\t|         1. 学生代表         |" << endl;
        cout << "\t\t\t|                             |" << endl;
        cout << "\t\t\t|         2. 老    师         |" << endl;
        cout << "\t\t\t|                             |" << endl;
        cout << "\t\t\t|         3. 管 理 员         |" << endl;
        cout << "\t\t\t|                             |" << endl;
        cout << "\t\t\t|         0. 退    出         |" << endl;
        cout << "\t\t\t|                             |" << endl;
        cout << "\t\t\t|-----------------------------|" << endl;
        cout << "\t\t\t|=============================|" << endl;
        cout << "输入您的选择：";
        cin >> select;
        switch (select)
        {
        case 1:
            Login(StudentFile, 1);
            break;
        case 2:
            Login(TeacherFile, 2);
            break;
        case 3:
            Login(AdminFile, 3);
            break;
        case 0:
        {
            cout << "欢迎下次使用,正在退出";
            for (int i = 0; i < 10; i++)
            {
                cout << "--";
                cout << (i + 1) * 10 << "%";
                Sleep(500);
                printf("\b\b\b");
            }
            cout << endl;
            cout << "Bey ^-^ ^-^ ^-^ Bey";
            Sleep(900);
            return 0;
            break;
        }
        default:
            cout << "输入有误请重新输入！" << endl;
            system("pause");
            system("cls");
            break;
        }
    }
    // system("pause");
    return 0;
}
void getPwd(string &str)
{
    char ch;
    int index = 0;
    char password[31];
    while ((ch = _getch()) != '\r')
    {
        if (ch != '\b')
        {
            printf("*");
            password[index++] = ch;
        }
        else
        {
            printf("\b \b");
            index--;
        }
    }
    password[index] = '\0';
    str = password;
    cout << endl;
}