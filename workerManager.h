#pragma once//��֤ͷ�ļ��Ʊ�����һ��
#include<iostream>

#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
using namespace std;

#include<fstream>
#define FILENAME "empFILE.text"


class WorkerManager
{
public:

	//���캯��
	WorkerManager();

	//�������ݵ��ļ���
	void save();
	bool m_FileIsEmpty;//�ж��ļ��Ƿ�Ϊ��

	int get_EmpNum();
	void init_Emp();

	//չʾ�˵�
	void Show_Menu();

	//չʾְ����Ϣ
	void Show_Emp();

	int m_EmpNum;//��¼ְ������
	
	Worker** m_EmpArray;//ְ������ָ�룬ָ������
	
	//���ְ��
	void Add_Emp();

	//�ж�ְ���Ƿ����
	int IsExit(int id);

	//ɾ��ְ��
	void Del_Emp();

	//�޸�ְ��
	void Mod_Emp();

	//����ְ��
	void Find_Emp();

	//��ְ����������
	void Sort_Emp();

	//����ļ�
	void Clean_File();

	//�˳�����
	void exitSystem();

	//��������
	~WorkerManager();
};
