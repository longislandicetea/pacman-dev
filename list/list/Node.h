#pragma once
#include<iostream>

class Node
{
public:
	Node(){}
	Node(int _entry,Node* link = NULL)
	{
		entry = _entry;
		next = link;
	}
	Node*& Next(){ return next;}
	int Entry(){return entry;}
	~Node(){}
private:
	int entry;
	Node* next;
	
};