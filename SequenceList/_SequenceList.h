#pragma once
#include <iostream>
#include <string.h>										//仅用于初始化数组
using namespace std;

const int MaxSize = 20;

template <typename T>class SequenceList {
private:
	int _size;												//表的长度
	T* element;												//保存一个表的每一项数据
	int MaxSizeNow;											//当前的最大容量
public:
	SequenceList() { _size = 0; MaxSizeNow = MaxSize; element = NULL; }//自动执行顺序表的初始化工作
	void Input();
	int expand();											//自动检查是否需要扩容，然后返回当前的最大容量
	int Insert(T x);										//将x插入到L中并使L仍是递增有序表
	int ListLength() { return _size; }						//写一求单链表的结点数目ListLength(L)的算法。
	void Remove(int i, int j);								//删除rank从i到j的所有元素
	T* RemoveDup();											//写一算法将单链表中值重复的结点删除，使所得的结果链表中所有结点的值均不相同。
	T* RemoveSpe(T x, T y);									//写一算法从一给定的向量A删除值在x到y(x≤y)之间的所有元素(注意：x和y是给定的参数，可以和表中的元素相同，也可以不同)。
	T* MergeRequired(SequenceList<T> & sec, SequenceList<T> & third);//设A和B是两个按元素值递增有序的单链表，
															//写一算法将A和B归并为按按元素值递减有序的单链表C，试分析算法的时间复杂度。
	void display();											//主要用于调试，查看结果
	~SequenceList() {delete[] element;}
};

template <typename T>
void SequenceList<T>::Input()							//自动执行顺序表的初始化工作
{
	element = new T[MaxSize];
	memset(element, 0, MaxSize);
	int i = 0;
	int x;
	cout << "输入顺序表的长度:" << endl;
	cin >> x;
	cout << "请输入顺序表的每一项:" << endl;
	T temp;
	while (x--) {										//可能这里还会出现问题
		cin >> temp;
		element[i] = temp;
		_size++;
		i++;
	}
	if (_size > MaxSize) expand();
	MaxSizeNow = expand();
}

template <typename T>
int SequenceList<T>::Insert(T x)						//将x插入到L中并使L仍是递增有序表
{
	int i = 0;
	for (; i < _size; i++) {
		if (x > element[_size - 1]) i = _size;
		if (x < element[0]) i = 0;
		if (x > element[i] && x <= element[i + 1] || x < element[i] && x >= element[i + 1])
			break;
	}
	if ((++_size) > MaxSize) expand();
	for (int j = _size - 1; j > i + 1; j--) {
		element[j] = element[j - 1];
	}
	element[i + 1] = x;
	return _size;
}

template <typename T>
T* SequenceList<T>::RemoveDup()							//写一算法将单链表中值重复的结点删除，使所得的结果链表中所有结点的值均不相同。
{
	for (int i = 0; i < _size; i++) {
		for (int j = i + 1; j < _size; j++)
			if (element[i] == element[j] && element[i] != element[j + 1]) {
				Remove(i + 1, j);
			}
				
	}
	return element;
}

template <typename T>
void SequenceList<T>::Remove(int a, int b)				//移除从rank为a到rank为b的所有element
{
	for (int i = 0; b + i + 1 < _size; i++)
		element[a + i] = element[b + i + 1];
	_size = _size - (b - a + 1);
}

template <typename T>
T* SequenceList<T>::RemoveSpe(T x, T y)					//写一算法从一给定的向量A删除值在x到y(x≤y)之间的所有元素(注意：x和y是给定的参数，可以和表中的元素相同，也可以不同)。
{
	int temp1 = 0, temp2 = 0;							//分别记录x,y的两个元素的rank
	int i = 0;
	while(i < _size){
		if (element[i] < x && element[i + 1] >= x) {
			temp1 = i + 1;
			break;
		}
		i++;
	}
	while (i < _size) {
		if (element[i] <= y && element[i + 1] > y) {
			temp2 = i;
			break;
		}
		i++;
	}
	//cout << temp1 << endl;
	//cout << temp2 << endl;
	if (i ==_size -1) Remove(temp1, _size - 1);
	if (i < _size -1) Remove(temp1, temp2);
	return element;
}

template <typename T>
T* SequenceList<T>::MergeRequired(SequenceList<T> & sec, SequenceList<T> & third)	//设A和B是两个按元素值递增有序的单链表，写一算法将A和B归并为按按元素值递减有序的单链表C，试分析算法的时间复杂度。
{
	if ((_size + sec._size - 1) >= MaxSize) expand();
	int a = -1;
	int i = _size - 1;
	int j = sec._size - 1;
	while (i >= 0 || j >= 0) {
		if (element[i] > sec.element[j]) {
			third.element[++a] = element[i];
			third._size++;
			i--;
		}
		else {
			third.element[++a] = sec.element[j];
			third._size++;
			j--;
		}
	}
	return element;
}

template <typename T>
void SequenceList<T>::display()							//主要用于调试，查看结果
{
	for (int i = 0; i < _size; i++) {
		cout << element[i] << ends;
	}
	cout << endl;
}

template <typename T>
int SequenceList<T>::expand()
{
	if (_size > MaxSizeNow) {
		MaxSizeNow <<= 1;		//这种扩容方式使得复杂度保持在o(log(n))
		T* oldele = element;
		element = new T[MaxSizeNow];
		for (int i = 0; i < _size; i++) {
			element[i] = oldele[i];
		}
		//display();				//用于调试
		delete[] oldele;
	}
	return MaxSizeNow;
}