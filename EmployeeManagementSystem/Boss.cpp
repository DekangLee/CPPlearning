#include "Boss.h"
Boss ::Boss(int ID, string Name, int DeptID)
{
    m_ID = ID;
    m_Name = Name;
    m_DeptID = DeptID;
}
void Boss::ShowInfo()
{
    cout << "员工编号: " << m_ID << "\t职工姓名: " << m_Name << "\t\t岗位: " << this->GetDeptName() << "\t\t岗位职责:给经理分配任务" << endl;
}
string Boss::GetDeptName()
{
    return string("BOSS");
}