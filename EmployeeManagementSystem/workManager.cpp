#include "workManager.h"
WorkManager::WorkManager()
{
    // 1、文件不存在
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    if (!ifs.is_open())
    {
        // cout << "文件不存在" << endl;
        this->m_EmpNum = 0;
        this->m_EmpArry = NULL;
        this->m_FileIsEmpty = true;
        return;
    }
    char ch;
    ifs >> ch;
    if (ifs.eof())
    {
        // cout << "文件数据为空" << endl;
        this->m_EmpNum = 0;
        this->m_EmpArry = NULL;
        this->m_FileIsEmpty = true;
        return;
    }
    this->m_EmpNum = this->getEmpNumber();
    this->m_EmpArry = new Worker *[this->m_EmpNum]; // 开辟内存空间
    this->Init_Emp();                               // 将数据存入数组
    this->m_FileIsEmpty = false;
    // for (int i = 0; i < this->m_EmpNum; i++)
    // {
    //     cout << this->m_EmpArry[i]->m_ID << " " << this->m_EmpArry[i]->m_Name << " " << this->m_EmpArry[i]->m_DeptID << endl;
    // }

    // cout << "职工人数为" << this->m_EmpNum << endl;
}

WorkManager::~WorkManager()
{
    if (this->m_EmpArry != NULL)
    {
        for (int i = 0; i < this->m_EmpNum; i++)
        {
            if (this->m_EmpArry[i] != NULL)
            {
                delete this->m_EmpArry[i];
                this->m_EmpArry[i] = NULL;
            }
        }
        delete[] this->m_EmpArry;
        this->m_EmpArry = NULL;
    }
}
void WorkManager::showMemu()
{
    cout << "******************************************" << endl;
    cout << "*********  欢迎使用职工管理系统  *********" << endl;
    cout << "************* 0.退出管理程序 *************" << endl;
    cout << "************* 1.增加职工信息 *************" << endl;
    cout << "************* 2.显示职工信息 *************" << endl;
    cout << "************* 3.删除离职职工 *************" << endl;
    cout << "************* 4.修改职工信息 *************" << endl;
    cout << "************* 5.查找职工信息 *************" << endl;
    cout << "************* 6.按照编号排序 *************" << endl;
    cout << "************* 7.清空所有信息 *************" << endl;
    cout << endl;
}
void WorkManager::exitSystem()
{
    cout << "欢迎下次使用" << endl;
    system("pause");
    exit(0);
}
void WorkManager::AddWorker()
{
    cout << "请输入加入职工的数量:";
    int addNum = 0;
    cin >> addNum;
    if (addNum > 0)
    {
        int newSize = this->m_EmpNum + addNum;
        Worker **newSpace = new Worker *[newSize];
        // 将原来的数据存储至新空间
        if (this->m_EmpArry != NULL)
        {
            for (int i = 0; i < this->m_EmpNum; i++)
            {
                newSpace[i] = m_EmpArry[i];
            }
        }

        // 添加新数据
        for (int i = 0; i < addNum; i++)
        {
            int ID;
            string name;
            int depnum;
            cout << "输入第" << i + 1 << "个新员工的编号:";
            // 防止员工编号重复
            bool flag = false;
            do
            {
                flag = false;
                cin >> ID;
                for (int i = 0; i < this->m_EmpNum; i++)
                {
                    if (this->m_EmpArry[i]->m_ID == ID)
                    {
                        flag = true;
                        break;
                    }
                }
                if (flag)
                {
                    cout << "编号重复请重新输入：";
                }
            } while (flag);
            cout << "输入第" << i + 1 << "个新员工的姓名:";
            cin >> name;
            cout << "1、普通职工" << endl;
            cout << "2、部门经理" << endl;
            cout << "3、公司老板" << endl;
            cout << "输入第" << i + 1 << "个新员工的部门:";
            cin >> depnum;
            Worker *Worker = NULL;
            switch (depnum)
            {
            case 1:
                Worker = new Employee(ID, name, depnum);
                break;
            case 2:
                Worker = new Maneger(ID, name, depnum);
                break;
            case 3:
                Worker = new Boss(ID, name, depnum);
                break;
            default:
                cout << "输入有误" << endl;
                break;
            }
            newSpace[this->m_EmpNum + i] = Worker;
        }
        // 释放原有的内存空间
        delete[] this->m_EmpArry;
        // 将新空间的地址赋值给this->m_EmpArry
        this->m_EmpArry = newSpace;
        // 更新新的职工人数
        this->m_EmpNum += addNum;
        this->m_FileIsEmpty = false;
        cout << "添加成功!" << endl;
        this->save();
    }
    else
    {
        cout << "输入有误!" << endl;
    }
    system("pause");
    system("cls");
}
void WorkManager::save()
{
    ofstream ofs;
    ofs.open(FILENAME, ios::out);
    for (int i = 0; i < this->m_EmpNum; i++)
    {
        ofs << this->m_EmpArry[i]->m_ID << " " << this->m_EmpArry[i]->m_Name << " " << this->m_EmpArry[i]->m_DeptID << endl;
    }
    ofs.close();
}
int WorkManager::getEmpNumber()
{
    ifstream ifs;
    int ID;
    string name;
    int DeptID;
    ifs.open(FILENAME, ios::in);
    int num = 0;
    Worker *Worker = NULL;
    while (ifs >> ID && ifs >> name && ifs >> DeptID)
    {
        num++;
    }
    ifs.close();
    return num;
}
void WorkManager::Init_Emp()
{
    ifstream ifs;
    int ID;
    string name;
    int DeptID;
    ifs.open(FILENAME, ios::in);

    int index = 0;
    while (ifs >> ID && ifs >> name && ifs >> DeptID)
    {
        Worker *Worker = NULL;
        switch (DeptID)
        {
        case 1:
            Worker = new Employee(ID, name, DeptID);
            break;
        case 2:
            Worker = new Maneger(ID, name, DeptID);
            break;
        case 3:
            Worker = new Boss(ID, name, DeptID);
            break;
        default:
            break;
        }
        this->m_EmpArry[index] = Worker;
        index++;
    }
    ifs.close();
}
void WorkManager::Show_Emp()
{
    if (this->m_FileIsEmpty)
    {
        cout << "文件不存在或者记录为空" << endl;
    }
    else
    {
        for (int i = 0; i < this->m_EmpNum; i++)
        {
            this->m_EmpArry[i]->ShowInfo();
        }
    }
    system("pause");
    system("cls");
}
int WorkManager::MemberIsExist(int id)
{
    int index = -1;
    for (int i = 0; i < this->m_EmpNum; i++)
    {
        if (this->m_EmpArry[i]->m_ID == id)
        {
            index = i;
            break;
        }
    }
    return index;
}
void WorkManager::DeleteWorker()
{
    int id;
    cout << "输入需要删除的员工编号：";
    cin >> id;
    int index = this->MemberIsExist(id);
    if (index < 0)
    {
        cout << "该职工不存在" << endl;
    }
    else
    {
        cout << "查找结果---"
             << " ID:" << this->m_EmpArry[index]->m_ID << " Name:" << this->m_EmpArry[index]->m_Name << " 岗位:"
             << this->m_EmpArry[index]->GetDeptName() << endl;
        cout << "确认删除[Y/N]？  :";
        while (true)
        {
            char ch;
            cin >> ch;
            if (ch == 'Y')
            {
                Worker **newSpace = new Worker *[this->m_EmpNum - 1];
                for (int i = 0; i < this->m_EmpNum; i++)
                {
                    if (i < index)
                    {
                        newSpace[i] = this->m_EmpArry[i];
                    }
                    if (i > index)
                    {
                        newSpace[i - 1] = this->m_EmpArry[i];
                    }
                }
                delete this->m_EmpArry[index];
                delete[] this->m_EmpArry;
                this->m_EmpArry = newSpace;
                this->m_EmpNum -= 1;
                if (this->m_EmpNum == 0)
                    this->m_FileIsEmpty = true;
                cout << "删除成功!" << endl;
                this->save();
                break;
            }
            else if (ch == 'N')
            {
                break;
            }
            else
            {
                cout << endl;
                cout << "输入有误，重新输入:";
            }
        }
    }

    system("pause");
    system("cls");
}
void WorkManager::SortAscend()
{
    if (this->m_FileIsEmpty)
    {
        cout << "文件为空！！" << endl;
        return;
    }
    for (int i = 0; i < this->m_EmpNum; i++)
    {
        for (int j = 0; j < this->m_EmpNum - i - 1; j++)
        {
            if (this->m_EmpArry[j]->m_ID > this->m_EmpArry[j + 1]->m_ID)
            {
                Worker *temp = this->m_EmpArry[j];
                this->m_EmpArry[j] = this->m_EmpArry[j + 1];
                this->m_EmpArry[j + 1] = temp;
            }
        }
    }
    cout << "编号升序排列完成" << endl;
    cout << "是否保存至文件[Y/N]?  :";
    while (true)
    {
        char ch;
        cin >> ch;
        if (ch == 'Y')
        {
            this->save();
            break;
        }
        else if (ch == 'N')
        {
            break;
        }
        else
            cout << "输入有误，请重新输入:";
    }
    system("pause");
    system("cls");
}
void WorkManager::SortDescend()
{
    if (this->m_FileIsEmpty)
    {
        cout << "文件为空！！" << endl;
        return;
    }
    for (int i = 0; i < this->m_EmpNum; i++)
    {
        for (int j = 0; j < this->m_EmpNum - i - 1; j++)
        {
            if (this->m_EmpArry[j]->m_ID < this->m_EmpArry[j + 1]->m_ID)
            {
                Worker *temp = this->m_EmpArry[j];
                this->m_EmpArry[j] = this->m_EmpArry[j + 1];
                this->m_EmpArry[j + 1] = temp;
            }
        }
    }

    cout << "编号降序排列完成" << endl;
    cout << "是否保存至文件[Y/N]?  :";
    while (true)
    {
        char ch;
        cin >> ch;
        if (ch == 'Y')
        {
            this->save();
            break;
        }
        else if (ch == 'N')
        {
            break;
        }
        else
            cout << "输入有误，请重新输入:";
    }
    system("pause");
    system("cls");
}
void WorkManager::Mod_Emp()
{
    if (this->m_FileIsEmpty)
    {
        cout << "文件记录为空" << endl;
        return;
    }
    cout << "请输入需要修改的职工编号:";
    int id;
    cin >> id;
    int index = this->MemberIsExist(id);
    if (index < 0)
    {
        cout << "查无此人！" << endl;
    }
    else
    {
        cout << "查找结果---"
             << " ID:" << this->m_EmpArry[index]->m_ID << " Name:" << this->m_EmpArry[index]->m_Name << " 岗位:"
             << this->m_EmpArry[index]->GetDeptName() << endl;
        delete this->m_EmpArry[index];
        Worker *w = NULL;
        int ID;
        string name;
        int depnum;
        cout << "输入员工的新编号:";
        // 防止员工编号重复
        bool flag = false;
        do
        {
            flag = false;
            cin >> ID;
            for (int i = 0; i < this->m_EmpNum; i++)
            {
                if (this->m_EmpArry[i]->m_ID == ID)
                {
                    flag = true;
                    break;
                }
            }
            if (flag)
            {
                cout << "编号重复请重新输入：";
            }
        } while (flag);
        cout << "输入员工的新姓名:";
        cin >> name;
        cout << "1、普通职工" << endl;
        cout << "2、部门经理" << endl;
        cout << "3、公司老板" << endl;
        cout << "输入员工的新部门:";
        cin >> depnum;
        Worker *Worker = NULL;
        switch (depnum)
        {
        case 1:
            Worker = new Employee(ID, name, depnum);
            break;
        case 2:
            Worker = new Maneger(ID, name, depnum);
            break;
        case 3:
            Worker = new Boss(ID, name, depnum);
            break;
        default:
            cout << "输入有误" << endl;
            break;
        }
        this->m_EmpArry[index] = Worker;
        this->save();
    }
    system("pause");
    system("cls");
}
void WorkManager::Find_Emp()
{
    if (this->m_FileIsEmpty)
    {
        cout << "文件记录为空" << endl;
        return;
    }
    cout << "请输入查找的方式：" << endl;
    cout << "1、按照编号查" << endl;
    cout << "2、按照姓名查" << endl;
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        int id;
        cout << "请输入要查找的职工编号";
        cin >> id;
        int index = this->MemberIsExist(id);
        if (index < 0)
        {
            cout << "查无此人！" << endl;
        }
        else
        {
            cout << "查找结果---"
                 << " ID:" << this->m_EmpArry[index]->m_ID << " Name:" << this->m_EmpArry[index]->m_Name << " 岗位:"
                 << this->m_EmpArry[index]->GetDeptName() << endl;
        }
        break;
    }
    case 2:
    {
        string name;
        cout << "输入要查找职工的姓名" << endl;
        cin >> name;
        int count = 0;
        for (int i = 0; i < this->m_EmpNum; i++)
        {
            if (this->m_EmpArry[i]->m_Name == name)
            {

                cout << "查找结果---"
                     << " ID:" << this->m_EmpArry[i]->m_ID << " Name:" << this->m_EmpArry[i]->m_Name << " 岗位:"
                     << this->m_EmpArry[i]->GetDeptName() << endl;
                count++;
            }
        }
        if (count == 0)
        {
            cout << "查无此人" << endl;
        }
        break;
    }

    default:
        cout << "输入有误！" << endl;
        break;
    }
    system("pause");
    system("cls");
}
void WorkManager::Clean_file()
{
    cout << "是否确认清空？[Y/N]";
    while (true)
    {
        char ch;
        cin >> ch;
        if (ch == 'Y')
        {
            ofstream ofs(FILENAME, ios::trunc);
            ofs.close();
            if (this->m_EmpArry != NULL)
            {
                for (int i = 0; i < this->m_EmpNum; i++)
                {
                    if (this->m_EmpArry[i] != NULL)
                    {
                        delete this->m_EmpArry[i];
                        this->m_EmpArry[i] = NULL;
                    }
                }
                delete[] this->m_EmpArry;
                this->m_EmpArry = NULL;
            }
            this->m_FileIsEmpty = true;
            cout<<"清空成功"<<endl;
            break;
        }
        else if (ch == 'N')
        {
            break;
        }
        else
            cout << "输入有误，请重新输入:";
    }
    system("pause");
    system("cls");
}