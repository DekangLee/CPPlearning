#include <iostream>
#include "workManager.h"
#include "employee.h"
#include "worker.h"
#include "Boss.h"
#include "manager.h"
using namespace std;

int main()
{
    WorkManager WorkManager;
    // Worker *w1 = new Employee(1, "白文超", 2);
    // w1->ShowInfo();
    // delete w1;
    // w1 = new Maneger(1, "李德康", 2);
    // w1->ShowInfo();
    // delete w1;
    // w1 = new Boss(1, "李德康", 2);
    // w1->ShowInfo();
    // delete w1;

    int choice = 0;
    while (true)
    {
        WorkManager.showMemu();
        cout << "请输入您的选择：";
        cin >> choice;
        switch (choice)
        {
        case 0: // 退出系统
            WorkManager.exitSystem();
            break;
        case 1: // 1.增加职工信息
            WorkManager.AddWorker();
            break;
        case 2: // 2.显示职工信息
            WorkManager.Show_Emp();
            break;
        case 3: // 3.删除离职职工
            WorkManager.DeleteWorker();
            break;
        case 4: // 4.修改职工信息
            WorkManager.Mod_Emp();
            break;
        case 5: // 5.查找职工信息
            WorkManager.Find_Emp();
            break;
        case 6: // 6.按照编号排序
            WorkManager.SortDescend();
            break;
        case 7: // 7.清空所有信息
            WorkManager.Clean_file();
            break;
        default:
        {
            system("cls");
            break;
        }
        }
    }

    system("pause");
    return 1;
}