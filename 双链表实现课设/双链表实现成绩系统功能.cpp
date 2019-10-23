// 双链表实现成绩系统功能.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 29、输入10个职工的信息，每个职工含有成员名为“职工号、姓名、基本工资、生活补贴、水电费、房租、实发工资、工资排名”，分别编写六个函数求：
//(1)输入一个职工的职工号，查询该职工的信息并输出，若不存在显示没找到。
//(2)输入一个新职工的信息，按职工号顺序将该职工的信息插入后输出。
//(3)输入一个已存在职工的姓名信息，删除该职工的信息后输出。
//(4)求每个职工的实发工资（实发工资 = 基本工资 + 生活补贴 - 水电费 - 房租）；
//(5)求所有职工基本工资、生活补贴、水电费、房租、实发工资的总和并输出；
//(6)对所有职工的信息按实发工资升序排序，并填写工资排名后输出；

#include <iostream>
#include <string>
#include <fstream>
#include "List.h"
using namespace std;
#define wholenumber 10

int main()
{
	List STAFF;			//形成一个空双链表
	ifstream fin("data.txt");
	for (int i = 0; i < wholenumber; i++) {
		Node* temp = STAFF.insertAsFirst(i + 1);
		//读入数据
		fin >> temp->name >> temp->WageBasic >> temp->Welfare >> temp->Utilities >> temp->Rent;
		temp->WageReal = temp->WageBasic + temp->Welfare - temp->Utilities - temp->Rent;
		temp->WageRank = 0;
	}
	fin.close();


	


	//用户界面，主菜单
	int choice;
	char c;
	do {
		system("cls");
	printf("*********************************************");
	printf("\n\t\t职工信息管理系统\n");
	cout << "\t(1)查询职工信息" << endl;
	cout << "\t(2)添加新职工信息" << endl;
	cout << "\t(3)删除已有职工" << endl;
	cout << "\t(4)职工的实发工资信息表" << endl;
	cout << "\t(5)职工各项工资统计" << endl;
	cout << "\t\t请输入使用功能前的编号" << endl;
	printf("*********************************************\n");
	cin >> choice;
	switch (choice) {
	case 1://查询职工信息
	{int n;
	cout << "请输入想要查询的员工编号" << endl;
	cin >> n;
	Node* p = STAFF.find(n);
	if (p == NULL) cout << "查询的员工编号不存在" << endl;
	else {
		printf("┌──────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐\n");
		printf("│编  号│姓    名│基本工资│生活补贴│水 电 费│房    租│实发工资│工资排名│\n");
		p->show();
		printf("└──────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┘\n");
	}
	break;
	}
	case 2://添加新职工信息
	{int number;
	cout << "请输入该员工的编号" << endl;
	cin >> number;
	Node* temp = STAFF.insertAsLast(number);
	cout << "请输入该员工的其他基本信息" << endl;
	cout << "包括如下五项，姓名、基本工资、生活补贴、水电费、房租" << endl;
	cin >> temp->name >> temp->WageBasic >> temp->Welfare >> temp->Utilities >> temp->Rent;
	temp->WageReal = temp->WageBasic + temp->Welfare - temp->Utilities - temp->Rent;
	temp->WageRank = 0;
	STAFF.display();
	break;
	}
	case 3://删除已有职工
	{
		string name;
	cout << "请输入需要删除的姓名" << endl;
	cin >> name;
	Node* p = STAFF.find(name);
	if (p == NULL) cerr << "error" << endl;
	else {
		STAFF.remove(p);
		STAFF.display();
	}
	
	break;
	}
	case 4:	//职工的实发工资信息表
		//算出WageRank
	{STAFF.sort();
	Node* temp = STAFF.last();
	for (int i = 0; i < STAFF.size(); i++) {
		temp->WageRank = i + 1;
		temp = temp->pred;
	}
	STAFF.display();
	break;
	}
	case 5://职工各项工资统计
	{STAFF.display();
	double Wage_sum = 0, Utility_sum = 0, Walfare_sum = 0, Rent_sum = 0, WageReal_sum = 0;
	for (Node* p = STAFF.first(); p != STAFF.last(); p = p->succ) {
		Wage_sum += p->WageBasic;
		Utility_sum += p->Utilities;
		Rent_sum += p->Rent;
		Walfare_sum += p->Welfare;
		WageReal_sum += p->WageReal;
	}
	printf("│  总和│\t│%-8.2lf│%-8.2lf│%-8.2lf│%-8.2lf│%-8.2lf│        │\n", Wage_sum, Walfare_sum, Utility_sum, Rent_sum, WageReal_sum);
	printf("└──────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┘\n");
	break;
	}
	default:cout << "输入有误，请重新输入" << endl;
	}

	cout << "是否需要继续进行有关操作" << endl;
	cin >> c;
	} while (c == 'y');

	return 0;
}