#include"boss.h"

Boss::Boss(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId=dId;
}

void Boss::showInfo()
{
	cout << "职工编号为：" << this->m_Id << endl;
	cout << "职工姓名为：" << this->m_Name << endl;
	cout << "岗位为：" << this->getDeptName() << endl;
	cout << "岗位职责：你是？" << endl;
	cout << endl;
}

string Boss::getDeptName()
{
	return string("纱布");
}