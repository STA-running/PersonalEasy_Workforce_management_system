#include"workerManager.h"
#include"worker.h"


WorkerManager::WorkerManager()//利用构造函数创建对象
{
	ifstream ifs;//判断文件是否为空
	ifs.open(FILENAME, ios::in);//读文件
	if (!ifs.is_open())
	{
		//文件不存在
		cout << "文件不存在" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	else {
		//文件存在，但是没有任何记录，文件为空
		char ch;
		ifs >> ch;
		if (ifs.eof())
		{
			cout << "该文件为空" << endl;
			this->m_EmpNum = 0;
			this->m_EmpArray = NULL;
			this->m_FileIsEmpty = true;
			ifs.close();
			return;
		}else {
			//文件存在，并且有记录
			int num = get_EmpNum();
			cout << "职工人数为：" << num << '\n';
			this->m_EmpNum = num; 

			//开辟空间
			this->m_EmpArray = new Worker * [this->m_EmpNum];
			
			init_Emp();
			//将文件中的数据存到数组中
			//测试代码
			/*
			this->init_Emp();

			for (int i = 0; i < this->m_EmpNum; i++)
			{
				cout << this->m_EmpArray[i]->m_Id << ' '
					<< this->m_EmpArray[i]->n_Name << ' '
					<< this->m_EmpArray[i]->m_DeptId << endl;
			} 
			*/
		}
	}
}

void WorkerManager::Show_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "该文件不存在或者为空" << endl;
	}
	else {
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			//利用多态调用接口
			this->m_EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}

int WorkerManager::IsExit(int id)
{
	int idx = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{
			idx = i;
			break;
		}
	}
	return idx;
}

void WorkerManager::Del_Emp()
{
	
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在，无法删除" << endl;
		return;
	}
	else {
		cout << "请输入你要删除职工的编号id" << endl;
		int id=0;
		cin >> id;
		int idx = this->IsExit(id);
		if (id != -1)
		{
			for (int i = id; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;
			this->save();
			cout << "success！" << endl;
		}else {
			cout << "没有这个人哦~" << endl;
			return;
		}
	}
	system("pause");
	system("cls");
	 
}
//修改职工
void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)cout << "文件不存在或者文件为空" << endl;
	else {
		cout << "请输入职工编号" << endl;
		int id;
		cin >> id;
		int ret = this->IsExit(id);
		if (ret != -1)//如果存在该职工，进行修改
		{
			delete this->m_EmpArray[ret];
			int newId = 0;
			string newName = "";
			int dSelect = 0;
			cout << "已经查询到" << id << "号员工，现在请输入新的职工号" << endl;
			cin >> newId;
			cout << "请输入新的名字" << endl;
			cin >> newName;
			cout << "请输入岗位：" << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(newId, newName, dSelect);
				break;
			case 2:
				worker = new Manager(newId, newName, dSelect);
				break;
			case 3:
				worker = new Boss(newId, newName, dSelect);
				break;
			default:
				cout << "what are you doing?" << endl;
				cout << "我不准你这次修改！" << endl;
				break;
			}
			if (worker != NULL)
			{
				this->m_EmpArray[ret] = worker;
				cout << "修改成功" << this->m_EmpArray[ret]->m_DeptId << endl;
				this->save();//保存到文件中
			}
		}
		else {
			cout << "查无此人！" << endl;
		}
	}
	system("pause");
	system("cls");
}


void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);

	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << ' '
			<< this->m_EmpArray[i]->m_Name << ' '
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}
	ofs.close();
}

int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int num = 0;//统计人数
	while (ifs>>id&&ifs>>name&&ifs>>dId)
	{
		num++;
	}
	return num;
}


//展示菜单
void WorkerManager::Show_Menu()
{
	cout << "************************************" << endl;
	cout << "****欢迎使用该职工管理系统杂鱼~*****" <<endl;
	cout << "***********0.退出管理系统***********" << endl;
	cout << "***********1.添加职工信息***********" << endl;
	cout << "***********2.显示职工信息***********" << endl;
	cout << "***********3.删除离职职工***********" << endl;
	cout << "***********4.修改职工信息***********" << endl;
	cout << "***********5.查找职工信息***********" << endl;
	cout << "***********6.按照编号排序***********" << endl;
	cout << "***********7.清空所有文档***********" << endl;
	cout << "************************************" << endl;
	cout << endl;
}

void WorkerManager::Add_Emp()
{
	cout << "请输入添加员工的数量" << endl;
	int addnum = 0;
	cin >> addnum;

	if (addnum > 0)
	{
		//计算空间大小
		int newSize = this->m_EmpNum + addnum;//this指WM这个类

		//开辟空间
		Worker** newSpace = new Worker * [newSize];//数组的每个单位存的都是职工类指针
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		for (int i = 0; i < addnum; i++)
		{
			int id;
			string name;
			int dSelect;//部门选择

			cout << "请输入第" << i + 1 << "个新职工编号：" << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个新职工姓名：" << endl;
			cin >> name;
			
			cout << "请选择职工岗位：" << endl;
			cout << "1.普通员工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			out:
			cin >> dSelect;

			Worker* worker = NULL;//实例化

			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 1);
				break;
			case 3:
				worker = new Boss(id, name, 1);
				break;
			default:
				cout << "呃呃，请重新输入" << endl;
				goto out;
				break;
			}   
			//new出来了，保存到数组中
			newSpace[this->m_EmpNum + i] = worker;
		}
		delete[] this->m_EmpArray;//全部移到newSpace里面了，老数组应该被释放掉
		
		//更改新空间的指向和人数
		this->m_EmpArray = newSpace;
		this->m_EmpNum = newSize;
		this->m_FileIsEmpty = false;//不为空

		cout << "success！" << endl;
		this->save();//保存数据
	}
	else {
		cout << "你是纱布吗？" << endl;
	}
	system("pause");
	system("cls");
}

//查找职工
void WorkerManager::Find_Emp()
{
	if (this->m_FileIsEmpty)cout << "文件不存在或者文件为空" << endl;
	else {
		cout << "请输入你需要查找的方式" << endl;
		cout << "1.按职工编号查找" << endl;
		cout << "2.按职工姓名查找" << endl;

		int select = 0;
		cin >> select;

		if (select == 1)//编号查找
		{
			cout << "请输入你需要查找的id" << endl;
			int id;
			cin >> id;
			int ret = IsExit(id);
			if (ret != -1)
			{
				cout << "success！" <<endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else {
				cout << "查无此人" << endl;
			}
		}
		else if(select==2){
			string name;
			cout << "请输入要查找的姓名" << endl;
			cin >> name;

			bool flag = false;//是否成功查找的标志
			for (int i = 0; i < m_EmpNum; i++)
			{
				if (m_EmpArray[i]->m_Name == name)
				{
					cout << "success!" << endl;
					flag = true;
					this->m_EmpArray[i]->showInfo();
				}
			}
			if (flag == false)
			{
				cout << "查无此人" << endl;
			}

		}
		else {
			cout << "输入有误" << endl;
		}
	}
	system("pause");
	system("cls");
}

//对职工进行排序
void WorkerManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者为空" << endl;
	}
	else {
		cout << "请选择排序方式" << endl;
		cout << "1.按照职工号升序" << endl;
		cout << "2.按照职工号降序" << endl;

		int select = 0;
		cin >> select;

		for (int i = 0; i < m_EmpNum; i++)
		{
			int minOrMax = i;
			for (int j = i + 1; j < m_EmpNum; j++)
			{
				if (select == 1)//升序
				{
					if (m_EmpArray[minOrMax]->m_Id > m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
				else {
					if (m_EmpArray[minOrMax]->m_Id < m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
			}
			if (i != minOrMax)
			{
				Worker* temp = m_EmpArray[i];
				m_EmpArray[i] = m_EmpArray[minOrMax];
				m_EmpArray[minOrMax] = temp;
			}
		}
		cout << "sort_success!" << endl;
		this->save();
		cout << "排序结果为：" << endl;
		this->Show_Emp();
	}
	//system("pause");
	//system("cls");
}

void WorkerManager::Clean_File()
{
	cout << "确认清空？" << endl;
	cout << "1.确认" << endl;
	cout << "2.返回" << endl;

	int select = 0;
	cin >> select;
	if (select == 1)
	{
		cout << "真的吗真的吗" << endl;
		cout << "确认之后再输入1" << endl;
		cin >> select;
		if (select == 1)select = 3;
		else select = 2;

	}

	if (select == 3)
	{
		//打开模式ios::trunc 如果存在，删除文件重新创建

		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < m_EmpNum; i++)
			{
				if (this->m_EmpArray[i] != NULL)
				{
					delete this->m_EmpArray[i];
				}
			}
			this->m_EmpNum = 0;
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_FileIsEmpty = true;
		}
		cout << "success!" << endl;
	}
	system("pause");
	system("cls");
}


void WorkerManager::exitSystem()
{
	cout << "欢迎下次再使用该系统哦杂鱼~" << endl;
	//system("pause");
	exit(0);
}

void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;
	int idx = 0;

	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;
		if (dId == 1)
		{
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2) {
			worker = new Manager(id, name, dId);
		}
		else {
			worker = new Boss(id, name, dId);
		}
		this->m_EmpArray[idx++] = worker;
	}
}


WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray == NULL)
	{
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}

