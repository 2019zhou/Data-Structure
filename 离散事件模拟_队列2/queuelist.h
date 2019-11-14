#pragma once
#include <iostream>
using namespace std;

//存储结构使用链表存储

struct customer
{
	int window;			//所在的窗口
	unsigned int time;	//所服务的时间长度
};

struct node {
	//数据
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
	int _size;		//存储队列的规模
	node *front;	//front不放数据
	node *rear;		//rear不放数据
public:
	//构造函数,析构函数
	queuelist() {		//初始化一个空队列
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
	//只读接口
	int size() { return _size; }				//公共的接口
	void display() const;						//用于debug
	node* getfront() const { return front; };//取队头后的第一个元素
	node* getrear() const { return rear; };	//取队尾一个元素
//可写操作					
	node* enqueue(customer e);			//入队操作适合本题目的情境，只能用于customer结构体的入栈
	node* dequeue();						//出队操作
	void clear();						//清空队列
	void frontdec();					//仅用于本题，为了简化结构而写，将front中的数值减少1
};



