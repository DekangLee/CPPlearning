#include "employee.h"
Employee ::Employee(int ID, string Name, int DeptID)
{
    m_ID = ID;
    m_Name = Name;
    m_DeptID = DeptID;
}
void Employee::ShowInfo()
{
    cout << "员工编号: " << m_ID << "\t职工姓名: " << m_Name << "\t\t岗位: " << this->GetDeptName() << "\t\t岗位职责:完成经理交下的任务" << endl;
}
string Employee::GetDeptName()
{
    return string("员工");
}