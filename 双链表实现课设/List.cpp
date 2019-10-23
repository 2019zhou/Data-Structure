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
	clear();			//�������
	delete header;
	delete trailer;
}

void List::remove(Node*p)		//ɾ���Ϸ�λ��p���Ľڵ�
{
	Node*temp = p;
	p->pred->succ = p->succ;
	p->succ->pred = p->pred;
	delete temp;
	_size--;
}

int	List::clear()						//����������ǲ�����header��trailer
{
	int old = _size;
	while (_size > 0) remove(header->succ);
	return old;
}

int List::disordered() const									//�ж��б��Ƿ�������
{
	Node*temp = header->succ;
	while (temp->succ != trailer) {
		if (temp->number > temp->succ->number) {
			return 0;
		}
	}
	return 1;
}

Node*List::find(int const& e, int n, Node*p) const	//�����������,p�ڵ��n��ǰ����
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

Node*List::selectMax(Node*p, int n)					//��p����n-1�������ѡ�������
{
	Node*temp = p;										//����ʹ��p��������Ԫ�أ��������ֱ�ӷ���p
	while (n--) {
		if (temp->number > p->number)
			p = temp;
	}
	return p;
}

void List::display()
{
	printf("���������������Щ����������������Щ����������������Щ����������������Щ����������������Щ����������������Щ����������������Щ�����������������\n");
	printf("����  �ũ���    �����������ʩ��������ˮ �� �ѩ���    �⩦ʵ�����ʩ�����������\n");
	Node*temp = header->succ;
	for (int i = 0; i < _size; i++) {
		temp->show();
		temp = temp->succ;
	}
	printf("���������������ة����������������ة����������������ة����������������ة����������������ة����������������ة����������������ة�����������������\n");
}

Node* List::insertAsFirst(double const& e)						//��e�����׽ڵ����
{
	Node* p = new Node(e, header, header->succ);
	header->succ = p;
	p->succ->pred = p;
	_size++;
	return p;
}

Node*List::insertAsLast(double const& e)					//��e����ĩ�ڵ����
{
	Node*p = new Node(e, trailer->pred, trailer);
	trailer->pred = p;
	p->pred->succ = p;
	_size++;
	return p;
}

Node*List::insertA(Node*p, double const& e)				//��e����p�ĺ�̲���
{
	p->InsertAsSucc(e);
	_size++;
	return p->succ;
}

Node*List::insertB(Node*p, double const& e)				//��e����p��ǰ������
{
	p->InsertAsPred(e);
	//p->pred = p->succ;								//�������û�������ԣ�ֻ��Ϊ�˽��bug��д
	_size++;
	return p->pred;
}

void List::sort()										//�б���������,ʵ��������������
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


//�����¼ 
//p = temp->succ,p��ȷʹ���˸��ƹ��캯������������temp->succ��ֵ������p���������У��������е�ֻ��һ��ֻ��number��Ա�Ľڵ�
//pֻ��һ���ֲ�����������ȫ�ֱ���
//����������㸴�ƣ���ǳ�㸴�Ƶ����⣬Ӧ���Ǹ��Ƶ�ʱ�򣬱�����Ĭ����ǳ�㸴��
//em... ��Ϊ��ֵ���������Ͳ�����ø��ƹ��캯��������
//���Ըɴ��Լ�дһ��copy����
