#pragma once
#include"Node.h"

class CircularLinkedQueue
{
public:
	CircularLinkedQueue( )
	{
		tail = NULL;
	}
	bool Empty( ) const
	{
		return tail == NULL;
	}
	void Append(int item)
	{
		Node* newNode = new Node(item);
		if(newNode == NULL)//don't ignore
			return;
		if(tail == NULL)//don't ignore
		{
			tail = newNode;
			tail->Next() = tail;
		}
		else
		{
			newNode->Next() = tail->Next();
			tail->Next() = newNode;
			tail = newNode;
		}
	}
	void Serve( )
	{
		if(tail == NULL)
			return;
		Node* oldFront = tail->Next();
		tail->Next() = oldFront->Next();
		delete oldFront;
	}
	void Retrieve(int &item) const
	{
		if(tail == NULL)
			return;
		item = tail->Next()->Entry();
	}
	CircularLinkedQueue(const CircularLinkedQueue &original)
	{
		tail = NULL;//don't ignore
		if(original.tail == NULL)
			return;
		//point to head at first
		Node *oldNode = original.tail->Next();
		//use Append() directly,because it must maintain tail each time
		do
		{
			Append(oldNode->Entry());
			oldNode = oldNode->Next();
		}while(oldNode!=original.tail->Next());
	}
	void operator = (const CircularLinkedQueue &original)
	{
		// clear first
		while(!Empty())
			Serve();
		tail = NULL;//don't ignore
		if(original.tail == NULL)
			return;
		//point to head at first
		Node *oldNode = original.tail->Next();
		//use Append() directly,because it must maintain tail each time
		do
		{
			Append(oldNode->Entry());
			oldNode = oldNode->Next();
		}while(oldNode!=original.tail->Next());
	}
protected:
	Node *tail;
};