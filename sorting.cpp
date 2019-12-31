// sorting.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <iostream>
#include <stdio.h>
using namespace std;

//为方便理解，这里的hi, mi, lo都是前闭后开区间

int a[20] = { 4, 2, 5, 1, 3 };
typedef enum { mergesort, quicksort }sorting;

void merge(int lo, int mi, int hi);
void mergesorting(int lo, int hi)
{
	if (hi - lo < 2)return;
	int mi = (hi + lo) / 2;
	mergesorting(lo, mi);
	mergesorting(mi, hi);
	merge(lo, mi, hi);
}

void merge(int lo, int mi, int hi)
{
	int* A = a + lo;
	int lb = mi - lo;
	int lc = hi - mi;
	int* B = new int[lb];
	for (int i = 0; i < lb; i++) B[i] = A[i];
	int* C = a + mi;
	for (int i = 0, j = 0, k = 0; (j < lb) || (k < lc); ) {
		if ((j < lb) && (!(k < lc) || (B[j] <= C[k]))) A[i++] = B[j++];
		if ((k < lc) && (!(j < lb) || (C[k] <  B[j]))) A[i++] = C[k++];
	}
	delete[] B;
}

int partition(int lo, int hi);
void quicksorting(int lo, int hi)
{
	if (hi - lo < 2)return;
	int pivot = partition(lo, hi - 1);
	quicksorting(lo, pivot);
	quicksorting(pivot, hi);
}

int partition(int lo, int hi)
{
	swap(a[lo], a[lo + rand() % (hi - lo + 1)]);
	int pivot = a[lo];
	while (lo < hi)
	{
		while ((lo < hi) && pivot <= a[hi])hi--;
		a[lo] = a[hi];
		while ((lo < hi) && a[lo] <= pivot)lo++;
		a[hi] = a[lo];
	}
	a[lo] = pivot;
	return lo;
}

int main() {

	printf("sorting methods: \n");
	sorting sort;
	sort = quicksort;
	switch (sort) {
	case mergesort: 
		mergesorting(0, 5); 
		cout << "mergesort result:" << endl;
		break;
	case quicksort: 
		quicksorting(0, 5); 
		cout << "quicksort result" << endl;
		break;
	default: cout << "something went wrong, reset please" << endl;
	}
	for (int i = 0; i < 5; i++)
		cout << a[i] << ends;
	cout << endl;
	return 0;
}
//开始出错因为判断没有加上括号
//注意规定的区间，前闭后开, 所以数组的输入参数必须是0， 5