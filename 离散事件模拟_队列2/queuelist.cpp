#include "queuelist.h"

void queuelist::display() const					//用于debug
{
	node* temp = rear;
	int n = _size;
	while (temp->pred != front&& n-->0)
	{
		temp = temp->pred;
		cout << temp->windows << ends << temp->time << ends;
	}
}

node* queuelist::enqueue(customer e)						//入队操作,并将元素e入队
{
	node* p = new node(e, rear->pred, rear);
	rear->pred = p;
	p->pred->succ = p;
	_size++;
	return p;
}

node* queuelist::dequeue()						//出队操作
{
	node* temp = front->succ;
	front->succ = temp->succ;
	front->succ->pred = front;
	delete temp;
	_size--;
	return front->succ;
}

void queuelist::clear()							//清空队列
{
	for (int i = 0; i < _size; i++) {
		dequeue();
	}
}

void queuelist::frontdec() {
	front->succ->time--;
	//cout << front->succ->time << endl;
}
