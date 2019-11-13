#include "Queue.h"

void Queue::display() const					//����debug
{
	for (int i = rear; i < front; i++)
	{
		cout << element[i] << ends;
	}
}

int Queue::enqueue(customer e)						//��Ӳ���,����Ԫ��e���
{
	expand();
	element[front] = e.window;
	element[front+1] = e.time;
	front = front + 2;
	_size++;
	return front;
}

int Queue::dequeue()						//���Ӳ���
{
	rear = rear + 2;
	_size--;
	return rear;
}

void Queue::clear()							//��ն���
{
	for (int i = 0; i < _size; i++) {
		dequeue();
	}
}

bool Queue::expand()						//���е����ݲ���������ֵΪ1������Ҫ���ݣ�����ֵΪ0������Ҫ����
{
	if (_size + 1 > maxsizenow) {
		maxsizenow = maxsizenow < 1;
		int* oldele = element;
		element = new int[maxsizenow];
		for (int i = 0; i < _size; i++) {
			element[i] = oldele[i];
		}
		return 1;
	}
	return 0;

}

void Queue::frontdec() {
	//cout << element[front - 1] << endl;
	element[rear + 1]--;
	//cout << element[front - 1] << endl;
}