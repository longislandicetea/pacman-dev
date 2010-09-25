#pragma once
#include"Node.h"

class List
{
public:
	List()
	{
		count = 0;
		head = NULL;
		currentPos = 0;
		current = head;
	}
	List(List& copy);
	Node* GetHead();
	bool Empty();
	int Size() { return count;}
	void Insert(int pos,int entry);
	void Remove(int pos);
	void Clear();
	void Retrieve(int pos,int& x);
	void Reverse();
	void InsertOrder(int insertEntry);
	void Print();
	~List(){}
protected:
	int count;
	mutable int currentPos;
	Node* head ;
	mutable Node* current;
	void setPosition(int pos) const;
};

static bool IsSubset(Node* head1,Node* head2)
{
	Node *p,*q;
	p = head1;
	while(p!=NULL)
	{
		q = head2;
		while(q!=NULL)
		{
			if(p->Entry() == q->Entry())
				break;
			else
				q = q->Next();
		}
		if(q == NULL)
			return false;
		p = p->Next();
	}
	return true;
}

