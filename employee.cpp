#include"employee.h"

Employee::Employee(int id, string name, int dId)//写构造函数
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}

void Employee::showInfo()
{
	cout << "职工编号为：" << this->m_Id<<endl;
	cout << "职工姓名为：" << this->m_Name<<endl;
	cout << "岗位为：" << this->getDeptName() << endl;
	cout << "岗位职责：勤勤恳恳当牛马" << endl;
	cout << endl;
}

string Employee::getDeptName()
{
	return string("员工");
}