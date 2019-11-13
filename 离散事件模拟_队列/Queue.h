#pragma once
#include <iostream>
using namespace std;
#define MaxSize 128

//存储结构具体，使用一个数据，每两个单元为一个存储区间进行存储

struct customer
{
	int window;			//所在的窗口
	unsigned int time;	//所服务的时间长度
};

class Queue
{
public:
//private:
	int _size;		//存储队列的规模
	int* element;	//存储队列的元素
	int front;		//front不放数据
	int rear;		//rear放数据
	int maxsizenow;
//public:
//构造函数,析构函数
	Queue() {		//初始化一个空队列
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
//只读接口
	int size() { return _size; }				//公共的接口
	void display() const;						//用于debug
	int getfront() const { return element[front - 1]; };//取队头后的第一个元素
	int getrear() const { return element[rear + 1]; };	//取队尾一个元素
	bool empty() const { return _size; }		//判断队列是否为空
//可写操作					
	int enqueue(customer e);			//入队操作适合本题目的情境，只能用于customer结构体的入栈
	int dequeue();						//出队操作
	void clear();						//清空队列
	bool expand();						//队列的扩容操作,返回值为1代表需要扩容，返回值为0代表不需要扩容
	void frontdec();					//仅用于本题，为了简化结构而写，将front中的数值减少1
};

