#include"manager.h"

Manager::Manager(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}

void Manager::showInfo()
{
	cout << "ְ�����Ϊ��" << this->m_Id << endl;
	cout << "ְ������Ϊ��" << this->m_Name << endl;
	cout << "��λΪ��" << this->getDeptName() << endl;
	cout << "��λְ�𣺸��ϰ嵱ţ���·������Ա��" << endl; cout << "ְ�����Ϊ��" << this->m_Id << endl;
	cout << endl;
}

string Manager::getDeptName()
{
	return string("����");
}