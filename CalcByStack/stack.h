#pragma once
//顺序栈的实现--模板类
#include <iostream>
#define MaxSize 64

template <typename T>class Stack {
private:
// 数据域
	int _size;												//栈的长度
	T* element;												//保存一个栈的每一项数据
	int topone;												//topone指向的是存放元素的下一个位置
	int bottom;
public:
// 构造，(复制构造)，析构
	Stack() { _size = 0; element = new T[MaxSize]; topone = bottom = 0; }		//自动执行顺序栈的初始化工作
	~Stack() { delete[] element; }
// 只读操作接口
	int getsize()const { return _size; }
	bool empty()const { return !_size; }					//栈为空，返回0，栈不空，返回1
	T& top()const;										//查看栈顶元素
	bool legal()const { return topone < MaxSize; }			//判断是否超过界
	void display()const;								//主要用于调试
// 可写操作接口
	T& push(T a);										//入栈
	T& pop();											//出栈
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
