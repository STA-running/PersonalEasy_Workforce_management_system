#include"boss.h"

Boss::Boss(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId=dId;
}

void Boss::showInfo()
{
	cout << "ְ�����Ϊ��" << this->m_Id << endl;
	cout << "ְ������Ϊ��" << this->m_Name << endl;
	cout << "��λΪ��" << this->getDeptName() << endl;
	cout << "��λְ�����ǣ�" << endl;
	cout << endl;
}

string Boss::getDeptName()
{
	return string("ɴ��");
}