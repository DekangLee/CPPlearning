#include "administrator.h"
administrator::administrator()
{
}
administrator::administrator(int id, string name, string pwd)
{
    // 初始化
    this->m_id = id;
    this->m_name = name;
    this->m_pwd = pwd;
    this->initVector();
}
void administrator::initVector()
{
    this->sVec.clear();
    this->sVec.clear();
    ifstream ifs1(StudentFile, ios::in);
    if (!ifs1.is_open())
    {
        cout << "打开文件失败" << endl;
        return;
    }
    student s;
    while (ifs1 >> s.m_id && ifs1 >> s.m_name && ifs1 >> s.m_pwd)
    {
        this->sVec.push_back(s);
    }
    ifstream ifs2(TeacherFile, ios::in);
    if (!ifs2.is_open())
    {
        cout << "打开文件失败" << endl;
        return;
    }
    teacher t;
    while (ifs2 >> t.m_id && ifs2 >> t.m_name && ifs2 >> t.m_pwd)
    {
        this->tVec.push_back(t);
    }
    // cout<<"学生数量:"<<this->sVec.size()<<endl;
    // cout<<"教师数量:"<<this->tVec.size()<<endl;
}
bool administrator::checkRepeat(int id, int type)
{
    if (type == 1)
    {
        for (auto student : this->sVec)
        {
            if (student.m_id == id)
                return true;
        }
    }
    else if (type == 2)
    {
        for (auto teacher : this->tVec)
        {
            if (teacher.m_id == id)
                return true;
        }
    }
    return false;
}
void administrator::showMenu()
{
    system("cls");
    cout << "=====================欢迎管理员" << this->m_name << "登录====================" << endl;
    cout << "\t\t -----------------------------" << endl;
    cout << "\t\t|                             |" << endl;
    cout << "\t\t|          1. 添加账号        |" << endl;
    cout << "\t\t|                             |" << endl;
    cout << "\t\t|          2. 查看账号        |" << endl;
    cout << "\t\t|                             |" << endl;
    cout << "\t\t|          3. 更改信息        |" << endl;
    cout << "\t\t|                             |" << endl;
    cout << "\t\t|          4. 查看机房        |" << endl;
    cout << "\t\t|                             |" << endl;
    cout << "\t\t|          5. 清空预约        |" << endl;
    cout << "\t\t|                             |" << endl;
    cout << "\t\t|          0. 注销登录        |" << endl;
    cout << "\t\t|                             |" << endl;
    cout << "\t\t -----------------------------" << endl;
    cout << "输入您的选择：";
} //
// 添加账号
void administrator::addPerson()
{
    system("cls");
    if (this->checkPwd() == -1)
    {
        return;
    }
    system("cls");
    int select;
    string filename;
    cout << "\t\t ----------------------" << endl;
    cout << "\t\t|                      |" << endl;
    cout << "\t\t|      1. 添加学生     |" << endl;
    cout << "\t\t|                      |" << endl;
    cout << "\t\t|      2. 添加教师     |" << endl;
    cout << "\t\t|                      |" << endl;
    cout << "\t\t ----------------------" << endl;
    cout << "输入您的选择：";
    string tip;
    string errortip;
    do
    {
        cin >> select;
        if (select == 1)
        {
            // 对学生文件操作
            filename = StudentFile;
            tip = "请输入学号：";
            errortip = "学号重复，请重新输入：";
            break;
        }
        else if (select == 2)
        {
            // 对教师文件操作
            filename = TeacherFile;
            tip = "请输入职工编号：";
            errortip = "编号重复，请重新输入：";
            break;
        }
        else if (select == 0)
        {
            cout << "退出！" << endl;
            system("pause");
            system("cls");
            return;
        }
        else
        {
            cout << "输入错误请重新输入，输0退出！" << endl;
        }
    } while (select != 1 || select != 2 || select != 0);
    ofstream ofs(filename, ios::out | ios::app);
    int id;
    string name;
    string pwd;
    do
    {
        cout << tip, cin >> id;
        if (this->checkRepeat(id, select))
        {
            cout << errortip << endl;
        }

    } while (this->checkRepeat(id, select));

    cout << "请输入姓名：", cin >> name;
    cout << "请输入密码：", cin >> pwd;
    ofs << id << " " << name << " " << pwd << endl;
    this->initVector();
    cout << "操作成功" << endl;
    system("pause");
    system("cls");
    return;
}
// 账户信息
void administrator::showPerson()
{
    system("cls");
    if (this->checkPwd() == -1)
    {
        return;
    }
    system("cls");
    this->initVector();
    int select;
    cout << "\t\t -------------------------" << endl;
    cout << "\t\t|                         |" << endl;
    cout << "\t\t|      1. 查看学生信息    |" << endl;
    cout << "\t\t|                         |" << endl;
    cout << "\t\t|      2. 查看教师信息    |" << endl;
    cout << "\t\t|                         |" << endl;
    cout << "\t\t -------------------------" << endl;
    cout << "输入您的选择：";
    cin >> select;
    if (select == 1)
    {
        cout << "学生信息如下:" << endl;
        for (auto student : this->sVec)
        {
            cout << "number:" << student.m_id << " name:" << student.m_name << " password:" << student.m_pwd << endl;
        }
    }
    else if (select == 2)
    {
        cout << "教师信息如下：" << endl;
        for (auto teacher : this->tVec)
        {
            cout << "number:" << teacher.m_id << " name:" << teacher.m_name << " password:" << teacher.m_pwd << endl;
        }
    }
    else
    {
        cout << "输入错误！" << endl;
    }
    system("pause");
    system("cls");
    return;
}
void administrator::alterPerson()
{
    system("cls");
    if (this->checkPwd() == -1)
    {
        return;
    }
    system("cls");
    int select1;
    cout << "\t\t -------------------------" << endl;
    cout << "\t\t|                         |" << endl;
    cout << "\t\t|      1. 修改学生信息    |" << endl;
    cout << "\t\t|                         |" << endl;
    cout << "\t\t|      2. 修改教师信息    |" << endl;
    cout << "\t\t|                         |" << endl;
    cout << "\t\t -------------------------" << endl;
    cout << "输入您的选择：";
    while (true)
    {
        cin >> select1;
        if (select1 == 1)
        {
            system("cls");
            int number = 1;
            for (auto student : this->sVec)
            {
                cout << number << " 学号:" << student.m_id << "\t姓名:" << student.m_name << "\t密码:" << student.m_pwd << endl;
                number++;
            }
            cout << "输入需要修改的序号:";
            int select2;
            while (true)
            {
                cin >> select2;
                if (select2 >= 1 && select2 <= this->sVec.size())
                {
                    system("cls");
                    int select3;
                    cout << "\t\t -------------------------" << endl;
                    cout << "\t\t|      1. 修改学生学号    |" << endl;
                    cout << "\t\t|      2. 修改学生姓名    |" << endl;
                    cout << "\t\t|      3. 修改学生密码    |" << endl;
                    cout << "\t\t|      0. 删除学生信息    |" << endl;
                    cout << "\t\t -------------------------" << endl;
                    cout << "输入您的选择：";
                    cin >> select3;
                    switch (select3)
                    {
                    case 1:
                    {
                        int id;
                        cout << "请输入新的学号:";
                        cin >> id;
                        this->sVec[select2 - 1].m_id = id;
                        this->updateStu();
                        cout << "学号更新成功！" << endl;
                        system("pause");
                        break;
                    }
                    case 2:
                    {
                        string name;
                        cout << "请输入新的姓名:";
                        cin >> name;
                        this->sVec[select2 - 1].m_name = name;
                        this->updateStu();
                        cout << "姓名更新成功！" << endl;
                        system("pause");
                        break;
                    }
                    case 3:
                    {
                        string pwd;
                        cout << "请输入新的密码:";
                        cin >> pwd;
                        this->sVec[select2 - 1].m_pwd = pwd;
                        this->updateStu();
                        cout << "密码更新成功！" << endl;
                        system("pause");
                        break;
                    }
                    case 0:
                    {
                        char verify;
                        cout << "确认是否删除[Y/N]:";
                        while (true)
                        {
                            if (verify == 'Y' || verify == 'N')
                            {
                                if (verify == 'Y')
                                {
                                    this->sVec.erase(this->sVec.begin() + select2 - 1);
                                    cout << "删除成功！" << endl;
                                    system("pause");
                                    system("cls");
                                    break;
                                }
                                else if (verify == 'N')
                                {
                                    break;
                                }
                            }
                            else
                            {
                                cout << "输入有误，请重新输入:";
                            }
                        }
                        break;
                    }
                    default:
                    {
                        cout << "输入有误，正在退出！";
                        for (int i = 0; i < 5; i++)
                        {
                            cout << "-";
                            cout << (i + 1) * 20 << "%";
                            Sleep(200);
                            cout << "\b\b\b" << endl;
                        }
                        break;
                    }
                    }
                    break;
                }
                else if (select2 == 0)
                {
                    cout << "正在退出";
                    for (int i = 0; i < 5; i++)
                    {
                        cout << "-";
                        cout << (i + 1) * 20 << "%";
                        Sleep(200);
                        cout << "\b\b\b" << endl;
                    }
                    break;
                }
                else
                {
                    cout << "输入错误请重新输入:";
                }
            }

            break;
        }
        else if (select1 == 2)
        {
            system("cls");
            int number = 1;
            for (auto teacher : this->tVec)
            {
                cout << number << " 职工编号:" << teacher.m_id << "\t姓名:" << teacher.m_name << "\t密码:" << teacher.m_pwd << endl;
                number++;
            }
            cout << "输入需要修改的序号:";
            int select2;
            while (true)
            {
                cin >> select2;
                if (select2 >= 1 && select2 <= this->tVec.size())
                {
                    system("cls");
                    int select3;
                    cout << "\t\t -------------------------" << endl;
                    cout << "\t\t|      1. 修改教师编号    |" << endl;
                    cout << "\t\t|      2. 修改教师姓名    |" << endl;
                    cout << "\t\t|      3. 修改教师密码    |" << endl;
                    cout << "\t\t|      0. 删除教师信息    |" << endl;
                    cout << "\t\t -------------------------" << endl;
                    cout << "输入您的选择：";
                    cin >> select3;
                    switch (select3)
                    {
                    case 1:
                    {
                        int id;
                        cout << "请输入新的职工编号:";
                        cin >> id;
                        this->tVec[select2 - 1].m_id = id;
                        this->updateTea();
                        cout << "职工编号更新成功！" << endl;
                        system("pause");
                        break;
                    }
                    case 2:
                    {
                        string name;
                        cout << "请输入新的姓名:";
                        cin >> name;
                        this->tVec[select2 - 1].m_name = name;
                        this->updateTea();
                        cout << "姓名更新成功！" << endl;
                        system("pause");
                        break;
                    }
                    case 3:
                    {
                        string pwd;
                        cout << "请输入新的密码:";
                        cin >> pwd;
                        this->tVec[select2 - 1].m_pwd = pwd;
                        this->updateTea();
                        cout << "密码更新成功！" << endl;
                        system("pause");
                        break;
                    }
                    case 0:
                    {
                        char verify;
                        cout << "确认是否删除[Y/N]:";
                        while (true)
                        {
                            if (verify == 'Y' || verify == 'N')
                            {
                                if (verify == 'Y')
                                {
                                    this->tVec.erase(this->tVec.begin() + select2 - 1);
                                    cout << "删除成功！" << endl;
                                    system("pause");
                                    system("cls");
                                    break;
                                }
                                else if (verify == 'N')
                                {
                                    break;
                                }
                            }
                            else
                            {
                                cout << "输入有误，请重新输入:";
                            }
                        }
                        break;
                    }
                    default:
                        cout << "输入有误，正在退出！" << endl;
                        Sleep(1000);
                        break;
                    }
                break;
                }
                else if (select2 == 0)
                {
                    cout << "正在退出";
                    for (int i = 0; i < 5; i++)
                    {
                        cout << "-";
                        cout << (i + 1) * 20 << "%";
                        Sleep(200);
                        cout << "\b\b\b" << endl;
                    }
                    break;
                }
                else
                {
                    cout << "输入错误请重新输入" << endl;
                }
            }
            break;
        }
        else
        {
            cout << "输入错误，请重新输入" << endl;
        }
    }
    // system("pause");
    // system("cls");
}
void administrator::updateStu()
{
    ofstream ofs(StudentFile, ios::trunc);
    for (auto student : this->sVec)
    {
        ofs << student.m_id << " " << student.m_name << " " << student.m_pwd << endl;
    }
    ofs.close();
}
void administrator::updateTea()
{
    ofstream ofs(TeacherFile, ios::trunc);
    for (auto teacher : this->tVec)
    {
        ofs << teacher.m_id << " " << teacher.m_name << " " << teacher.m_pwd << endl;
    }
    ofs.close();
}
// 查看机房信息
void administrator::showRoom()
{
    system("cls");
    if (this->checkPwd() == -1)
    {
        return;
    }
    system("cls");
    ifstream ifs(RoomFile, ios::in);
    if (!ifs.is_open())
    {
        cout << "打开文件失败" << endl;
        return;
    }
    computerRoom compRoom;
    int id;
    int Maxnum;
    while (ifs >> id && ifs >> Maxnum)
    {
        compRoom.setId(id);
        compRoom.setNum(Maxnum);
        this->compVec.push_back(compRoom);
    }
    auto _fprint = [](const computerRoom &compRoom)
    {
        cout << "id :" << compRoom.getId() << " MaxnNum :" << compRoom.getNum() << endl;
    };
    for_each(this->compVec.begin(), this->compVec.end(), _fprint);
    system("pause");
    system("cls");
}
// 清空预约记录
void administrator::clearRcoder()
{
    cout << "是否清空预约记录[Y/N]:";
    char ch;
    do
    {
        cin >> ch;
        if (ch != 'Y' && ch != 'N')
        {
            cout << "请重新输入:";
        }
    } while (ch != 'Y' && ch != 'N');
    if (ch == 'Y')
    {
        ofstream ofs1(OrderFile, ios::trunc);
        ofs1.close();
        cout << "清空成功！" << endl;
    }
    system("pause");
    system("cls");
}
int administrator::checkPwd()
{
    string pwd;
    while (true)
    {
        cout << "请输入密码：";
        // cin>>pwd;
        AdnimGetPwd(pwd);
        if (pwd == this->m_pwd)
        {
            return 1;
        }
        else if (pwd == "0")
        {
            cout << "正在退出";
            for (int i = 0; i < 5; i++)
            {
                cout << "-";
                cout << (i + 1) * 20 << "%";
                Sleep(200);
                cout << "\b\b\b" << endl;
            }
            return -1;
        }
        else
        {
            cout << "密码错误！(输0退出)" << endl;
        }
    }
}
void adminMenu(identity *person)
{
    int select;
    administrator *admin = (administrator *)person;
    while (true)
    {
        person->showMenu();
        cin >> select;
        switch (select)
        {
        case 1: // 添加账号
            // cout << "添加账号" << endl;
            admin->addPerson();
            break;
        case 2: // 查看账号
            // cout << "查看账号" << endl;
            admin->showPerson();
            break;
        case 3: // 修改信息
            admin->alterPerson();
            break;
        case 4: // 查看机房
            // cout << "查看机房" << endl;
            admin->showRoom();
            break;
        case 5: // 清空预约
            // cout << "清空预约" << endl;
            admin->clearRcoder();
            break;
        case 0:
            delete admin;
            cout << "欢迎下次使用" << endl;
            system("pause");
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
void AdnimGetPwd(string &str)
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