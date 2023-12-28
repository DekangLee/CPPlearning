#include "manager.h"
Maneger ::Maneger(int ID, string Name, int DeptID)
{
    m_ID = ID;
    m_Name = Name;
    m_DeptID = DeptID;
}
void Maneger::ShowInfo()
{
    cout << "员工编号: " << m_ID << "\t职工姓名: " << m_Name << "\t\t岗位: " << this->GetDeptName() << "\t\t岗位职责:完成BOSS交下的任务,给员工分配任务" << endl;
}
string Maneger::GetDeptName()
{
    return string("经理");
}