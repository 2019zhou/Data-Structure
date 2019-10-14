// polynomial.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// polynomial

#include <iostream>
#include "_polynomial.h"
using namespace std;

int main()
{
	//for test
	int a[20] = { 3,4,5};		//Coefficient for list one
	int b[20] = { 1,2,4 };		//exponent for list one
	int c[20] = { 1,4,1 };			//Coefficient for list two
	int d[20] = { 1,2,3 };			//exponent for list two
	
	//将List 1以链表形式存放
	Node<int>* HeadOne = NULL;
	for (int i = 0; a[i] != 0 || b[i] != 0; i++) {
		Node<int>* P = new Node<int>;
		P->coefficient = a[i];
		P->exponent = b[i];
		P->next = HeadOne;
		HeadOne = P;
	}

	//将List 2以链表形式存放
	Node<int>* HeadTwo = NULL;
	for (int i = 0; c[i] != 0 || d[i] != 0; i++) {
		Node<int>* P = new Node<int>;
		P->coefficient = c[i];
		P->exponent = d[i];
		P->next = HeadTwo;
		HeadTwo = P;
	}

	cout << "This is raw list" << endl;;
	display(HeadOne);
	display(HeadTwo);

	//显示简单相加的结果
	cout << "显示简单相加的结果" << endl;
	Node<int>* HeadThree = NULL;
	adding(HeadOne,HeadTwo,HeadThree);
	display(HeadThree);

	//显示两个式子相乘的结果
	cout << "显示两个式子相乘的结果" << endl;
	Node<int>* HeadFour = NULL;
	//display(HeadOne);
	//display(HeadTwo);
	multiply(HeadOne, HeadTwo, HeadFour);
	display(HeadFour);

	cout << "显示合并同类项之后的结果" << endl;
	combine_likeitems(HeadFour);
	display(HeadFour);

	deleting(HeadOne);
	deleting(HeadTwo);
	deleting(HeadThree);
	deleting(HeadFour);
	
	return 0;
}
