#include "List.h"

List::List() {
	header = new Node;
	trailer = new Node;
	header->pred = NULL;
	header->succ = trailer;
	trailer->pred = header;
	trailer->succ = NULL;
_size = 0;
}

List::~List() {
	clear();			//清空链表
	delete header;
	delete trailer;
}

void List::remove(Node*p)		//删除合法位置p处的节点
{
	Node*temp = p;
	p->pred->succ = p->succ;
	p->succ->pred = p->pred;
	delete temp;
	_size--;
}

int	List::clear()						//清空链表，但是不包括header和trailer
{
	int old = _size;
	while (_size > 0) remove(header->succ);
	return old;
}

int List::disordered() const									//判断列表是否已排序
{
	Node*temp = header->succ;
	while (temp->succ != trailer) {
		if (temp->number > temp->succ->number) {
			return 0;
		}
	}
	return 1;
}

Node*List::find(int const& e, int n, Node*p) const	//无序区间查找,p节点的n个前驱中
{
	if (n > _size) { cout << "illegal input" << endl; return NULL; }
	while (n--) {
		if (p->number == e)
			return p;
		p = p->pred;
	}
	return NULL;
}

Node* List::find(string const& name) {
	Node* temp = header->succ;
	for (int i = 0; i < _size; i++) {
		if (temp->name == name)
			return temp;
		temp = temp->succ;
	}
	return NULL;
}

Node*List::selectMax(Node*p, int n)					//在p及其n-1个后继中选出最大者
{
	Node*temp = p;										//这里使用p放置最大的元素，可以最后直接返回p
	while (n--) {
		if (temp->number > p->number)
			p = temp;
	}
	return p;
}

void List::display()
{
	printf("┌──────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐\n");
	printf("│编  号│姓    名│基本工资│生活补贴│水 电 费│房    租│实发工资│工资排名│\n");
	Node*temp = header->succ;
	for (int i = 0; i < _size; i++) {
		temp->show();
		temp = temp->succ;
	}
	printf("└──────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┘\n");
}

Node* List::insertAsFirst(double const& e)						//将e当作首节点插入
{
	Node* p = new Node(e, header, header->succ);
	header->succ = p;
	p->succ->pred = p;
	_size++;
	return p;
}

Node*List::insertAsLast(double const& e)					//将e当作末节点插入
{
	Node*p = new Node(e, trailer->pred, trailer);
	trailer->pred = p;
	p->pred->succ = p;
	_size++;
	return p;
}

Node*List::insertA(Node*p, double const& e)				//将e当作p的后继插入
{
	p->InsertAsSucc(e);
	_size++;
	return p->succ;
}

Node*List::insertB(Node*p, double const& e)				//将e当作p的前驱插入
{
	p->InsertAsPred(e);
	//p->pred = p->succ;								//这个做法没有普适性，只是为了解决bug而写
	_size++;
	return p->pred;
}

void List::sort()										//列表区间排序,实发工资升序排序
{
	Node*temp = header->succ;
	for (int i = 0; i < _size && temp->succ != trailer; i++) {
		for(int j = 0; j < _size - i && temp->succ != trailer; j++){
			if (temp->WageReal > temp->succ->WageReal) {
				insertB(temp, temp->succ->number);
				//p->show();
				temp->copy(temp->pred, temp->succ);
				remove(temp->succ);
				//display();
				//cout << endl;
			}
			else {temp = temp->succ;}
		}
		temp = header->succ;
		//cout << _size << endl;
	}
}


//错误记录 
//p = temp->succ,p的确使用了复制构造函数复制了所有temp->succ的值，但是p不在链表中，在链表中的只是一个只有number成员的节点
//p只是一个局部变量而不是全局变量
//看起来是深层复制，和浅层复制的问题，应该是复制的时候，编译器默认了浅层复制
//em... 因为赋值操作根本就不会调用复制构造函数。。。
//所以干脆自己写一个copy函数
