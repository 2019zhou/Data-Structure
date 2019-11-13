#pragma once
#include <iostream>
using namespace std;
#define MaxSize 128

//�洢�ṹ���壬ʹ��һ�����ݣ�ÿ������ԪΪһ���洢������д洢

struct customer
{
	int window;			//���ڵĴ���
	unsigned int time;	//�������ʱ�䳤��
};

class Queue
{
public:
//private:
	int _size;		//�洢���еĹ�ģ
	int* element;	//�洢���е�Ԫ��
	int front;		//front��������
	int rear;		//rear������
	int maxsizenow;
//public:
//���캯��,��������
	Queue() {		//��ʼ��һ���ն���
		element= new int[MaxSize];
		memset(element, 0, MaxSize);
		front = 0;
		rear = 0;
		_size = 0;
		maxsizenow = MaxSize;
	}
	~Queue() {
		clear();
	}
//ֻ���ӿ�
	int size() { return _size; }				//�����Ľӿ�
	void display() const;						//����debug
	int getfront() const { return element[front - 1]; };//ȡ��ͷ��ĵ�һ��Ԫ��
	int getrear() const { return element[rear + 1]; };	//ȡ��βһ��Ԫ��
	bool empty() const { return _size; }		//�ж϶����Ƿ�Ϊ��
//��д����					
	int enqueue(customer e);			//��Ӳ����ʺϱ���Ŀ���龳��ֻ������customer�ṹ�����ջ
	int dequeue();						//���Ӳ���
	void clear();						//��ն���
	bool expand();						//���е����ݲ���,����ֵΪ1������Ҫ���ݣ�����ֵΪ0������Ҫ����
	void frontdec();					//�����ڱ��⣬Ϊ�˼򻯽ṹ��д����front�е���ֵ����1
};

