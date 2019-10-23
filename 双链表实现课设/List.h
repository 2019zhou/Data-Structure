#pragma once
#include "Node.h"

class List							//���ɵ������࣬��װ������Ĺ��ܵ�
{
private:
	int _size;			//��ģ
	Node* header;		//ͷ
	Node* trailer;		//β
protected:
	int	clear();											//������нڵ�,����ֵ��ԭ��������ĳ���
	//void merge(Node*&, int, List&, Node*, int);			//�鲢
	//void selectionSort(Node*, int);						//�Դ�p��ʼ������n���ڵ�ѡ������
	//void insertionSort(Node*, int);						//�Դ�p��ʼ������n���ڵ��������
public:
 // ���캯��
	List();													//ʵ������ĳ�ʼ��
 // ��������
	~List();												//�ͷţ�����ͷ��β�ڱ����ڵģ����нڵ�

 // ֻ�����ʽӿ�
	int size() const { return _size; }						//��ģ
	bool empty() const { return _size <= 0; }				//�п�
	Node* first() const { return header->succ; }			//�׽ڵ�λ��
	Node* last() const { return trailer->pred; }			//ĩ�ڵ�λ��
	bool valid(Node* p)										//�ж�λ��p�Ƿ����Ϸ�
	{
		return p && (trailer != p) && (header != p);
	}														//��ͷ��β�ڵ��ͬ��NULL
	int disordered() const;									//�ж��б��Ƿ�������(���������Ĭ��Ϊ�Ӵ�С) 0�����Ѿ�����1����û������
	Node* find(int const& e) const							//�����б����
	{
		return find(e, _size, trailer);
	}
	Node* find(int const& e, int n, Node* p) const;			//�������
	Node* find(string const& name);							//������Ϊ���ұ�׼����
	Node* selectMax(Node* p, int n);						//��p����n-1�������ѡ�������
	Node* selectMax() { return selectMax(header->succ, _size); } //���������
 // ��д���ʽӿ�
	Node* insertAsFirst(double const& e);					//��e�����׽ڵ����
	Node* insertAsLast(double const& e);					//��e����ĩ�ڵ����
	Node* insertA(Node* p, double const& e);				//��e����p�ĺ�̲���
	Node* insertB(Node* p, double const& e);				//��e����p��ǰ������
	void remove(Node* p);									//ɾ���Ϸ�λ��p���Ľڵ�,���ر�ɾ���ڵ�
	void sort();										    //�б����������ڱ���Ϊʵ��������������
 // ����debug
	void display();
};

/*������������
��1���������� ���ʺϣ�
��2��ð������ ���ʺϣ�
��3��ϣ������ ���ʺϣ�
��4��ѡ������ ���ʺϣ�
��5���������� �����ʺϣ�
��6���ϲ����� �����ʺϣ�
��7���������� �����ʺϣ�
��8�������� �����ʺϣ�*/