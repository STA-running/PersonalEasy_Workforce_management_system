#pragma once
#include<iostream>
using namespace std;
#include"worker.h"

//继承员工抽象类，该头文件为经理类

class Manager :public Worker
{
public:
	Manager(int id, string name, int dId);
	
	//显示个人信息
	virtual void showInfo();

	//获取职工岗位信息
	virtual string getDeptName();

};