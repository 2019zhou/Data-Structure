// SequenceList.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//顺序表
//实现顺序表的基本功能
//编程序实现1 - 5中的算法。
//1  设顺序表L是递增有序表，试写一算法，将x插入到L中并使L仍是递增有序表。
//2  写一求单链表的结点数目ListLength(L)的算法。
//3  写一算法将单链表中值重复的结点删除，使所得的结果链表中所有结点的值均不相同。
//4  写一算法从一给定的向量A删除值在x到y(x≤y)之间的所有元素(注意：x和y是给定的参数，可以和表中的元素相同，也可以不同)。
//5  设A和B是两个按元素值递增有序的单链表，写一算法将A和B归并为按按元素值递减有序的单链表C，试分析算法的时间复杂度。
//顺序表的存储结构：数组。

#include <iostream>
#include <string.h>
#include "_SequenceList.h"
using namespace std;

int main()
{
	SequenceList<double> List1;
	List1.Input();
	List1.display();
	
	//下面显示链表的长度
	cout << "The length of the list is" << endl;
	cout << List1.ListLength() << endl;
	
	//下面显示插入之后的结果
	double t;
	cout << "输入需要插入的值";
	cin >> t;
	cout << "The result after inserting:" << endl;
	List1.Insert(t);
	List1.display();

	//下面显示删除重复节点之后的结果
	cout << "The result after deleting duplicate ones" << endl;
	List1.RemoveDup();
	List1.display();

	//下面显示从x到y之间的所有元素
	cout << "To delete all the elements between x and y," << endl;
	cout << "(x <= y)input x and y:" << endl;
	int x, y;
	cin >> x >> y;
	List1.RemoveSpe(x, y);
	List1.display();

	//下面显示两递增有序的单链表，并归并为新表
	cout << "To get the merging result of two sequencelist, input the second list2 and List3 " << endl;
	SequenceList<double> List2;
	SequenceList<double> List3;
	List2.Input();
	List3.Input();
	cout << "This is the result of the merging" << endl;
	List1.MergeRequired(List2, List3);
	List3.display();

	return 0;
}