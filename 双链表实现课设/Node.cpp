#include "Node.h"
void Node::InsertAsPred(int const& e)		//e在当前节点之前插入
{
	Node* p = new Node(e, pred, this);
	this->pred->succ = p;
	this->pred = p;
}

void Node::InsertAsSucc(int const& e) {		//e在当前节点之后插入
	Node* p = new Node(e, this, succ);
	this->succ->pred = p;
	this->succ = p;
}


void Node::show() {
	cout << "├──────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤\n";
	printf("│%6d│", number);
	printf("%8s", name.c_str());
	printf("│%8.2lf│%8.2lf│%8.2lf│%8.2lf│%8.2lf│%8d│\n", WageBasic, Welfare, Utilities, Rent, WageReal, WageRank);
}

void Node::copy(Node* a, Node* b) {
	a->name = b->name; a->WageBasic = b->WageBasic;
	a->Welfare = b->Welfare; a->Utilities = b->Utilities;
	a->Rent = b->Rent; a->WageReal = b->WageReal;
	a->WageRank = b->WageRank;
}