#pragma once
#include<iostream>
using namespace std;
#include"worker.h"

//�̳�Ա�������࣬��ͷ�ļ�Ϊ��ͨԱ����

class Employee :public Worker//����̳�
{
public:
	//���캯��
	Employee(int id, string name, int dId);

	virtual void showInfo();//��ʾ������Ϣ
	virtual string getDeptName();//��ȡ��λְ������

};