#pragma once
#include <iostream>
#include <string>
using namespace std;

struct Node	//�������������
{
	//���ݳ�Ա
	int number;
	string name;
	double WageBasic;		//��������
	double Welfare;			//�����
	double Utilities;		//ˮ���
	double Rent;			//����
	double WageReal;		//ʵ������
	int WageRank;		//��������
	//ָ��
	Node* pred;
	Node* succ;
	//���캯��
	Node() {			//����header ��trailer���ԣ�����Ҫ��������
		name = 'h';			WageBasic = 0;		Welfare = 0;
		Utilities = 0;		Rent = 0;			WageReal = 0;
		WageRank = -1;
	}
	Node(int e, Node* p = NULL, Node* s = NULL) :number(e), pred(p), succ(s) {//�����ڵ�
		name = 'h';			WageBasic = 0;		Welfare = 0;
		Utilities = 0;		Rent = 0;			WageReal = 0;
		WageRank = -1;
	}	
	//�����ӿ�
	void InsertAsPred(int const& e);
	void InsertAsSucc(int const& e);
	void show();
	void copy(Node* a, Node* b);
};

