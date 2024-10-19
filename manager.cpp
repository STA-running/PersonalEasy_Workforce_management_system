#include"manager.h"

Manager::Manager(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}

void Manager::showInfo()
{
	cout << "职工编号为：" << this->m_Id << endl;
	cout << "职工姓名为：" << this->m_Name << endl;
	cout << "岗位为：" << this->getDeptName() << endl;
	cout << "岗位职责：给老板当牛马，下发任务给员工" << endl; cout << "职工编号为：" << this->m_Id << endl;
	cout << endl;
}

string Manager::getDeptName()
{
	return string("经理");
}