#pragma once

template <typename T>struct Node {
	T coefficient;
	T exponent;
	Node* next;
};

void display(Node<int>* L);
void deleting(Node<int>* L);						//ɾ������������ֹ�ڴ�й¶
void adding(Node<int>* A, Node<int>* B, Node<int>*& C);	//ʵ�ֵ�����һ�����������������������֮��
//û�������ϵķ�����ԭ�����ϵķ��������˿ռ��ռ�У�������ɾ�������ʱ���޷��ܺõ�ɾ������Ϊ�����������ǻ���ǰ�����������ɣ����ɾ����Щ������ɾ��2�εĽ���������ɾ��������ڴ�й¶
void multiply(Node<int>* A, Node<int>* B,Node<int>*& C);	//ʵ�ֵ���������������
void combine_likeitems(Node<int>* &L);			//���֮�����ϲ�ͬ����
//void deletingitem(Node<int>*& L, Node<int>* P);		//�ںϲ�ͬ�����������Ҫ