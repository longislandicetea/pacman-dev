#pragma once
#include"Node.h"
#include<iostream>

class LinkedQueue
{
public:
	LinkedQueue()
	{
		front = rear = NULL;
	}
	bool Empty()
	{
		return front == NULL;
	}
	void Append(int item)
	{
		Node* newNode = new Node(item);
		if(newNode == NULL)
			return;
		if(rear == NULL)
			front = rear = newNode;
		else
		{
			rear->Next() = newNode;
			rear = newNode;
		}
	}
	void Serve()
	{
		if(front == NULL)
			return;
		Node* oldFront = front;
		front = oldFront->Next();
		if(front == NULL)
			rear = NULL;
		delete oldFront;
	}
	void Retrieve(int& item)
	{
		if(front == NULL)
			return;
		item = front->Entry();
	}
	~LinkedQueue()
	{
		Clear();
	}
	LinkedQueue(const LinkedQueue& original)
	{
		front = rear = NULL;
		Node *newNode,*origin;
		newNode = origin = original.front;
		while(origin->Next()!=NULL)
		{
			origin = origin->Next();
			newNode = new Node(origin->Entry());
			newNode = newNode->Next();
		}
	}
	void operator = (const LinkedQueue& original)
	{
		Clear();
		LinkedQueue tmp(original);
		front = tmp.front;
	}
	bool Full()
	{
		return false;
	}
	int Size()
	{
		Node* tmp = front;
		int cnt = 0;
		while(tmp!=NULL)
		{
			tmp = tmp->Next();
			++cnt;
		}
		return cnt;
	}
	void Clear()
	{
		while(!Empty())
			Serve();
	}
	void ServeAndRetrieve(int& item)
	{
		if(front == NULL)
			return;
		item = front->Entry();
		Node* oldFront = front;
		front = oldFront->Next();
		if(front == NULL)
			rear = NULL;
		delete oldFront;
	}
private:
	Node *front,*rear;
};