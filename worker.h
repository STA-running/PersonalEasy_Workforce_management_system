#pragma once
#include<iostream>
#include<string>
using namespace std;

//��ͷ�ļ�ΪԱ��������Ķ��壬�Ѹ���ְλ��Ա������Ϊһ����
class Worker
{
public:
	//��ʾ������Ϣ
	virtual void showInfo() = 0;//���麯������ɳ�����

	//��ȡ��λ����
	virtual string getDeptName() = 0;

	int m_Id;//ְ�����
	string m_Name;//ְ������
	int m_DeptId;//Ա�����ڲ������Ʊ��

};
