#pragma once//保证头文件制备编译一次
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

	//构造函数
	WorkerManager();

	//保存数据到文件中
	void save();
	bool m_FileIsEmpty;//判断文件是否为空

	int get_EmpNum();
	void init_Emp();

	//展示菜单
	void Show_Menu();

	//展示职工信息
	void Show_Emp();

	int m_EmpNum;//记录职工人数
	
	Worker** m_EmpArray;//职工数组指针，指向数组
	
	//添加职工
	void Add_Emp();

	//判断职工是否存在
	int IsExit(int id);

	//删除职工
	void Del_Emp();

	//修改职工
	void Mod_Emp();

	//查找职工
	void Find_Emp();

	//对职工进行排序
	void Sort_Emp();

	//清空文件
	void Clean_File();

	//退出程序
	void exitSystem();

	//析构函数
	~WorkerManager();
};
