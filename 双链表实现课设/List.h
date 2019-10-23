#pragma once
#include "Node.h"

class List							//构成的链表类，封装了所需的功能等
{
private:
	int _size;			//规模
	Node* header;		//头
	Node* trailer;		//尾
protected:
	int	clear();											//清除所有节点,返回值是原来的链表的长度
	//void merge(Node*&, int, List&, Node*, int);			//归并
	//void selectionSort(Node*, int);						//对从p开始连续的n个节点选择排序
	//void insertionSort(Node*, int);						//对从p开始连续的n个节点插入排序
public:
 // 构造函数
	List();													//实现链表的初始化
 // 析构函数
	~List();												//释放（包含头、尾哨兵在内的）所有节点

 // 只读访问接口
	int size() const { return _size; }						//规模
	bool empty() const { return _size <= 0; }				//判空
	Node* first() const { return header->succ; }			//首节点位置
	Node* last() const { return trailer->pred; }			//末节点位置
	bool valid(Node* p)										//判断位置p是否对外合法
	{
		return p && (trailer != p) && (header != p);
	}														//将头、尾节点等同于NULL
	int disordered() const;									//判断列表是否已排序(这里的排序默认为从大到小) 0代表已经排序，1代表没有排序
	Node* find(int const& e) const							//无序列表查找
	{
		return find(e, _size, trailer);
	}
	Node* find(int const& e, int n, Node* p) const;			//区间查找
	Node* find(string const& name);							//以名字为查找标准查找
	Node* selectMax(Node* p, int n);						//在p及其n-1个后继中选出最大者
	Node* selectMax() { return selectMax(header->succ, _size); } //整体最大者
 // 可写访问接口
	Node* insertAsFirst(double const& e);					//将e当作首节点插入
	Node* insertAsLast(double const& e);					//将e当作末节点插入
	Node* insertA(Node* p, double const& e);				//将e当作p的后继插入
	Node* insertB(Node* p, double const& e);				//将e当作p的前驱插入
	void remove(Node* p);									//删除合法位置p处的节点,返回被删除节点
	void sort();										    //列表整体排序，在本题为实发工资升序排序
 // 用于debug
	void display();
};

/*关于链表排序
（1）插入排序 （适合）
（2）冒泡排序 （适合）
（3）希尔排序 （适合）
（4）选择排序 （适合）
（5）快速排序 （不适合）
（6）合并排序 （不适合）
（7）基数排序 （不适合）
（8）堆排序 （不适合）*/