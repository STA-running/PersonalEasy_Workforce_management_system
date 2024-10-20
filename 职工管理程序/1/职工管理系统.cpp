#include<iostream>//基础输入输出流
using namespace std;
#include"workerManager.h"//含有WorkerManager类
#include"worker.h"
#include"employee.h"
#include"boss.h"
#include"manager.h"


//该程序用来测试员工多态是否编写正确
void test()
{
	Worker* worker = NULL;
	worker = new Employee(1, "张三", 1);
	worker->showInfo();
	delete worker;

	worker = new Manager(2, "李四", 2);
	worker->showInfo();
	delete worker;

	worker = new Boss(3, "王五", 3);
	worker->showInfo();
	delete worker;
}


int main()
{
	WorkerManager wm;//实例化
	while (true)
	{
		wm.Show_Menu();
		int choice = 0;
		cout << "请进行操作" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:
			wm.exitSystem();
			break;
		case 1:
			wm.Add_Emp();
			break;
		case 2:
			wm.Show_Emp();
			break;
		case 3:
			wm.Del_Emp();
			//wm.IsExit(1);
			break;
		case 4:
			wm.Mod_Emp();
			break;
		case 5:
			wm.Find_Emp();
			break;
		case 6:
			wm.Sort_Emp();
			break;
		case 7:
			wm.Clean_File();
			break;
		default:
			cout << "杂鱼怎么连数字都输不对杂鱼~" << endl;
			system("pause");
			system("cls");
			break;
		}


	}
	
	system("pause");
	return 0;
}