#pragma once
#include"Node.h"

class LinkedStack
{
public:
	LinkedStack()
	{
		topNode = NULL;
	}
	bool empty() const
	{
		return topNode == NULL;
	}
	void push(const int item)
	{
		Node* newNode = new Node(item,topNode);
		topNode = newNode;
	}
	void pop()
	{
		topNode = topNode->Next();
	}
	void top(int &item) const
	{
		item = topNode->Entry();
	}
	~LinkedStack(){}
	LinkedStack(const LinkedStack &original)
	{
		topNode = original.topNode;
		Node *now,*origin;
		now = origin = new Node(topNode->Entry());
		while(origin->Next()!=NULL)
		{
			origin = origin->Next();
			//now->Next() = new Node(origin->Entry());
			now = now->Next();
		}
	}
	void operator =(const LinkedStack &original)
	{
		LinkedStack tmp(original);
		topNode = original.topNode;
	}
private:
	Node *topNode;
};