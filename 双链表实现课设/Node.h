#pragma once
#include <iostream>
#include <string>
using namespace std;

struct Node	//建立所需的链表
{
	//数据成员
	int number;
	string name;
	double WageBasic;		//基本工资
	double Welfare;			//生活补贴
	double Utilities;		//水电费
	double Rent;			//房租
	double WageReal;		//实发工资
	int WageRank;		//工资排名
	//指针
	Node* pred;
	Node* succ;
	//构造函数
	Node() {			//对于header 和trailer而言，不需要放入数据
		name = 'h';			WageBasic = 0;		Welfare = 0;
		Utilities = 0;		Rent = 0;			WageReal = 0;
		WageRank = -1;
	}
	Node(int e, Node* p = NULL, Node* s = NULL) :number(e), pred(p), succ(s) {//其他节点
		name = 'h';			WageBasic = 0;		Welfare = 0;
		Utilities = 0;		Rent = 0;			WageReal = 0;
		WageRank = -1;
	}	
	//操作接口
	void InsertAsPred(int const& e);
	void InsertAsSucc(int const& e);
	void show();
	void copy(Node* a, Node* b);
};

