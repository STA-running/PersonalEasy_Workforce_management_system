#pragma once
#include<iostream>
#include<string>
using namespace std;

//该头文件为员工抽象类的定义，把各种职位的员工抽象为一个类
class Worker
{
public:
	//显示个人信息
	virtual void showInfo() = 0;//纯虚函数，变成抽象类

	//获取岗位名称
	virtual string getDeptName() = 0;

	int m_Id;//职工编号
	string m_Name;//职工姓名
	int m_DeptId;//员工所在部门名称编号

};
