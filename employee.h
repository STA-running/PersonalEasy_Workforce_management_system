#pragma once
#include<iostream>
using namespace std;
#include"worker.h"

//继承员工抽象类，该头文件为普通员工类

class Employee :public Worker//子类继承
{
public:
	//构造函数
	Employee(int id, string name, int dId);

	virtual void showInfo();//显示个人信息
	virtual string getDeptName();//获取岗位职工名称

};