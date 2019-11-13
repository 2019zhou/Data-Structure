#include "Queue.h"

void Queue::display() const					//用于debug
{
	for (int i = rear; i < front; i++)
	{
		cout << element[i] << ends;
	}
}

int Queue::enqueue(customer e)						//入队操作,并将元素e入队
{
	expand();
	element[front] = e.window;
	element[front+1] = e.time;
	front = front + 2;
	_size++;
	return front;
}

int Queue::dequeue()						//出队操作
{
	rear = rear + 2;
	_size--;
	return rear;
}

void Queue::clear()							//清空队列
{
	for (int i = 0; i < _size; i++) {
		dequeue();
	}
}

bool Queue::expand()						//队列的扩容操作，返回值为1代表需要扩容，返回值为0代表不需要扩容
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