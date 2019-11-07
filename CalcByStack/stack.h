#pragma once
//˳��ջ��ʵ��--ģ����
#include <iostream>
#define MaxSize 64

template <typename T>class Stack {
private:
// ������
	int _size;												//ջ�ĳ���
	T* element;												//����һ��ջ��ÿһ������
	int topone;												//toponeָ����Ǵ��Ԫ�ص���һ��λ��
	int bottom;
public:
// ���죬(���ƹ���)������
	Stack() { _size = 0; element = new T[MaxSize]; topone = bottom = 0; }		//�Զ�ִ��˳��ջ�ĳ�ʼ������
	~Stack() { delete[] element; }
// ֻ�������ӿ�
	int getsize()const { return _size; }
	bool empty()const { return !_size; }					//ջΪ�գ�����0��ջ���գ�����1
	T& top()const;										//�鿴ջ��Ԫ��
	bool legal()const { return topone < MaxSize; }			//�ж��Ƿ񳬹���
	void display()const;								//��Ҫ���ڵ���
// ��д�����ӿ�
	T& push(T a);										//��ջ
	T& pop();											//��ջ
};

template<typename T>
T& Stack<T>::top()const
{
	return element[topone - 1];
}


template<typename T>
T& Stack<T>::push(T a)
{
	if(legal())
		element[topone++] = a;
	_size++;
	return element[topone -1];
}


template<typename T>
T& Stack<T>::pop()
{
	if (legal())
		topone--;
	_size--;
	return element[topone];
}

template<typename T>
void Stack<T>::display()const
{
	for (int i = bottom; i < topone; i++) {
		std::cout << element[i] << std::ends;
	}
	std::cout << std::endl;
}
