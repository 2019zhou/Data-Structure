#pragma once

template <typename T>struct Node {
	T coefficient;
	T exponent;
	Node* next;
};

void display(Node<int>* L);
void deleting(Node<int>* L);						//删除整个链表，防止内存泄露
void adding(Node<int>* A, Node<int>* B, Node<int>*& C);	//实现的新增一个链表将结果放在新增的链表之中
//没有用书上的方法的原因，书上的方法减少了空间的占有，但是在删除链表的时候无法很好的删除，因为第三个链表是基于前两个建立而成，如果删除有些结点会有删除2次的结果，如果不删，会造成内存泄露
void multiply(Node<int>* A, Node<int>* B,Node<int>*& C);	//实现的是两个链表的相乘
void combine_likeitems(Node<int>* &L);			//相乘之后必须合并同类相
//void deletingitem(Node<int>*& L, Node<int>* P);		//在合并同类项操作中需要