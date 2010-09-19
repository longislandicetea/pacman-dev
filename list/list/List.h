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
		current = NULL;
	}
	List(List& copy);
	bool Empty();
	int Size() { return count;}
	void Insert(int pos,int entry);
	void Remove(int pos);
	void Clear();
	void Retrieve(int pos,int& x);
	void Reverse();
	void Print();
	~List(){}
protected:
	int count;
	mutable int currentPos;
	Node* head ;
	mutable Node* current;
	void setPosition(int pos) const;
};

