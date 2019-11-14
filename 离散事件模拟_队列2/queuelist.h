#pragma once
#include <iostream>
using namespace std;

//�洢�ṹʹ������洢

struct customer
{
	int window;			//���ڵĴ���
	unsigned int time;	//�������ʱ�䳤��
};

struct node {
	//����
	int windows;
	unsigned int time;
	node* pred;
	node* succ;
	node(customer e, node* t, node* p) { time = e.time, windows = e.window; pred = t; succ = p; }
	node() { windows = -1; time = 0; pred = NULL; succ = NULL; }
};

class queuelist
{
private:
	int _size;		//�洢���еĹ�ģ
	node *front;	//front��������
	node *rear;		//rear��������
public:
	//���캯��,��������
	queuelist() {		//��ʼ��һ���ն���
		front = new node();
		rear = new node();
		rear->pred = front;
		front->succ = rear;
		_size = 0;
	}
	~queuelist() {
		clear();
		delete rear;
		delete front;
	}
	//ֻ���ӿ�
	int size() { return _size; }				//�����Ľӿ�
	void display() const;						//����debug
	node* getfront() const { return front; };//ȡ��ͷ��ĵ�һ��Ԫ��
	node* getrear() const { return rear; };	//ȡ��βһ��Ԫ��
//��д����					
	node* enqueue(customer e);			//��Ӳ����ʺϱ���Ŀ���龳��ֻ������customer�ṹ�����ջ
	node* dequeue();						//���Ӳ���
	void clear();						//��ն���
	void frontdec();					//�����ڱ��⣬Ϊ�˼򻯽ṹ��д����front�е���ֵ����1
};



