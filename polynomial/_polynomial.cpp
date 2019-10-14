//.h中的具体实现
#include <iostream>
#include "_polynomial".h"
using namespace std;


void display(Node<int>* L) {
	Node<int>* P = L;
	while (P != NULL) {
		cout << P->coefficient << "x^" << P->exponent;
		if (P->next != NULL) cout << "+";
		P = P->next;
	}
	cout << endl;
}

void deleting(Node<int>* L) {
	Node<int>* P = L;
	while (P) {
		Node<int>* tmp = P;
		P = P->next;
		delete tmp;
	}
}

void adding(Node<int>* A, Node<int>* B, Node<int>*& C)	//实现的新增一个链表将结果放在新增的链表之中
{
	Node<int>* tmp_A = A;
	Node<int>* tmp_B = B;
	while (tmp_A != NULL && tmp_B != NULL) {
		//display(C);
		if (tmp_A->exponent > tmp_B->exponent) {
			Node<int>* P = new Node<int>;
			P->coefficient = tmp_A->coefficient;
			P->exponent = tmp_A->exponent;
			P->next = C;
			C = P;
			tmp_A = tmp_A->next;
		}
		else if (tmp_A->exponent == tmp_B->exponent) {
			if (tmp_A->coefficient + tmp_B->coefficient != 0) {
			Node<int>* P = new Node<int>;
			P->coefficient = tmp_A->coefficient + tmp_B->coefficient;
			P->exponent = tmp_A->exponent;
			P->next = C;
			C = P;
			tmp_A = tmp_A->next;
			tmp_B = tmp_B->next;
			}
		}
		else {
			Node<int>* P = new Node<int>;
			P->coefficient = tmp_B->coefficient;
			P->exponent = tmp_B->exponent;
			P->next = C;
			C = P;
			tmp_B = tmp_B->next;
		}
	}
	while (tmp_A != NULL) {
		Node<int>* P = new Node<int>;
		P->coefficient = tmp_A->coefficient;
		P->exponent = tmp_A->exponent;
		P->next = C;
		C = P;
		tmp_A = tmp_A->next;
	}
	while (tmp_B != NULL) {
		Node<int>* P = new Node<int>;
		P->coefficient = tmp_B->coefficient;
		P->exponent = tmp_B->exponent;
		P->next = C;
		C = P;
		tmp_B = tmp_B->next;
	}
}

void multiply(Node<int>* A, Node<int>* B,Node<int>* & C)	//实现的是两个链表的相乘
{
	Node<int>* tmp_A = A;
	Node<int>* tmp_B = B;
	while(tmp_A) {
		for (; tmp_B != NULL; tmp_B = tmp_B->next) {
			Node<int>* P = new Node<int>;
			P->coefficient = tmp_B->coefficient * tmp_A->coefficient;
			P->exponent = tmp_B->exponent + tmp_A->exponent;
			P->next = C;
			C = P;
			//display(C);
		}
		tmp_A = tmp_A->next;
		tmp_B = B;
	}
}

void combine_likeitems(Node<int>* &L)				//相乘之后必须合并同类相
{
	Node<int>* tmp1 = L;
	Node<int>* tmp2 = L;
	Node<int>* tmp3 = L;
	while (tmp1) {
		for (tmp2 = tmp1->next, tmp3 = tmp1; tmp2 != NULL; tmp2 = tmp2->next, tmp3 = tmp3->next) {
			if (tmp1->exponent == tmp2->exponent) {
				tmp1->coefficient = tmp1->coefficient + tmp2->coefficient;
				//将tmp_2这个节点删除
				tmp3->next = tmp2->next;
				delete tmp2;	//含义，tmp2出的地址没变，但是数据已经无意义了
				tmp2 = tmp3->next;
			}
		}
		tmp1 = tmp1->next;
	}
}
