#include"employee.h"

Employee::Employee(int id, string name, int dId)//д���캯��
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}

void Employee::showInfo()
{
	cout << "ְ�����Ϊ��" << this->m_Id<<endl;
	cout << "ְ������Ϊ��" << this->m_Name<<endl;
	cout << "��λΪ��" << this->getDeptName() << endl;
	cout << "��λְ�����ڿҿҵ�ţ��" << endl;
	cout << endl;
}

string Employee::getDeptName()
{
	return string("Ա��");
}