#pragma once
#include <iostream>
#include <string.h>										//�����ڳ�ʼ������
using namespace std;

const int MaxSize = 20;

template <typename T>class SequenceList {
private:
	int _size;												//��ĳ���
	T* element;												//����һ�����ÿһ������
	int MaxSizeNow;											//��ǰ���������
public:
	SequenceList() { _size = 0; MaxSizeNow = MaxSize; element = NULL; }//�Զ�ִ��˳���ĳ�ʼ������
	void Input();
	int expand();											//�Զ�����Ƿ���Ҫ���ݣ�Ȼ�󷵻ص�ǰ���������
	int Insert(T x);										//��x���뵽L�в�ʹL���ǵ��������
	int ListLength() { return _size; }						//дһ������Ľ����ĿListLength(L)���㷨��
	void Remove(int i, int j);								//ɾ��rank��i��j������Ԫ��
	T* RemoveDup();											//дһ�㷨����������ֵ�ظ��Ľ��ɾ����ʹ���õĽ�����������н���ֵ������ͬ��
	T* RemoveSpe(T x, T y);									//дһ�㷨��һ����������Aɾ��ֵ��x��y(x��y)֮�������Ԫ��(ע�⣺x��y�Ǹ����Ĳ��������Ժͱ��е�Ԫ����ͬ��Ҳ���Բ�ͬ)��
	T* MergeRequired(SequenceList<T> & sec, SequenceList<T> & third);//��A��B��������Ԫ��ֵ��������ĵ�����
															//дһ�㷨��A��B�鲢Ϊ����Ԫ��ֵ�ݼ�����ĵ�����C���Է����㷨��ʱ�临�Ӷȡ�
	void display();											//��Ҫ���ڵ��ԣ��鿴���
	~SequenceList() {delete[] element;}
};

template <typename T>
void SequenceList<T>::Input()							//�Զ�ִ��˳���ĳ�ʼ������
{
	element = new T[MaxSize];
	memset(element, 0, MaxSize);
	int i = 0;
	int x;
	cout << "����˳���ĳ���:" << endl;
	cin >> x;
	cout << "������˳����ÿһ��:" << endl;
	T temp;
	while (x--) {										//�������ﻹ���������
		cin >> temp;
		element[i] = temp;
		_size++;
		i++;
	}
	if (_size > MaxSize) expand();
	MaxSizeNow = expand();
}

template <typename T>
int SequenceList<T>::Insert(T x)						//��x���뵽L�в�ʹL���ǵ��������
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
T* SequenceList<T>::RemoveDup()							//дһ�㷨����������ֵ�ظ��Ľ��ɾ����ʹ���õĽ�����������н���ֵ������ͬ��
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
void SequenceList<T>::Remove(int a, int b)				//�Ƴ���rankΪa��rankΪb������element
{
	for (int i = 0; b + i + 1 < _size; i++)
		element[a + i] = element[b + i + 1];
	_size = _size - (b - a + 1);
}

template <typename T>
T* SequenceList<T>::RemoveSpe(T x, T y)					//дһ�㷨��һ����������Aɾ��ֵ��x��y(x��y)֮�������Ԫ��(ע�⣺x��y�Ǹ����Ĳ��������Ժͱ��е�Ԫ����ͬ��Ҳ���Բ�ͬ)��
{
	int temp1 = 0, temp2 = 0;							//�ֱ��¼x,y������Ԫ�ص�rank
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
T* SequenceList<T>::MergeRequired(SequenceList<T> & sec, SequenceList<T> & third)	//��A��B��������Ԫ��ֵ��������ĵ�����дһ�㷨��A��B�鲢Ϊ����Ԫ��ֵ�ݼ�����ĵ�����C���Է����㷨��ʱ�临�Ӷȡ�
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
void SequenceList<T>::display()							//��Ҫ���ڵ��ԣ��鿴���
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
		MaxSizeNow <<= 1;		//�������ݷ�ʽʹ�ø��Ӷȱ�����o(log(n))
		T* oldele = element;
		element = new T[MaxSizeNow];
		for (int i = 0; i < _size; i++) {
			element[i] = oldele[i];
		}
		//display();				//���ڵ���
		delete[] oldele;
	}
	return MaxSizeNow;
}