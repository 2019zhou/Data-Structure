//.h�еľ���ʵ��
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

void adding(Node<int>* A, Node<int>* B, Node<int>*& C)	//ʵ�ֵ�����һ�����������������������֮��
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

void multiply(Node<int>* A, Node<int>* B,Node<int>* & C)	//ʵ�ֵ���������������
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

void combine_likeitems(Node<int>* &L)				//���֮�����ϲ�ͬ����
{
	Node<int>* tmp1 = L;
	Node<int>* tmp2 = L;
	Node<int>* tmp3 = L;
	while (tmp1) {
		for (tmp2 = tmp1->next, tmp3 = tmp1; tmp2 != NULL; tmp2 = tmp2->next, tmp3 = tmp3->next) {
			if (tmp1->exponent == tmp2->exponent) {
				tmp1->coefficient = tmp1->coefficient + tmp2->coefficient;
				//��tmp_2����ڵ�ɾ��
				tmp3->next = tmp2->next;
				delete tmp2;	//���壬tmp2���ĵ�ַû�䣬���������Ѿ���������
				tmp2 = tmp3->next;
			}
		}
		tmp1 = tmp1->next;
	}
}
