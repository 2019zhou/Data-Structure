#include "queuelist.h"

void queuelist::display() const					//����debug
{
	node* temp = rear;
	int n = _size;
	while (temp->pred != front&& n-->0)
	{
		temp = temp->pred;
		cout << temp->windows << ends << temp->time << ends;
	}
}

node* queuelist::enqueue(customer e)						//��Ӳ���,����Ԫ��e���
{
	node* p = new node(e, rear->pred, rear);
	rear->pred = p;
	p->pred->succ = p;
	_size++;
	return p;
}

node* queuelist::dequeue()						//���Ӳ���
{
	node* temp = front->succ;
	front->succ = temp->succ;
	front->succ->pred = front;
	delete temp;
	_size--;
	return front->succ;
}

void queuelist::clear()							//��ն���
{
	for (int i = 0; i < _size; i++) {
		dequeue();
	}
}

void queuelist::frontdec() {
	front->succ->time--;
	//cout << front->succ->time << endl;
}
