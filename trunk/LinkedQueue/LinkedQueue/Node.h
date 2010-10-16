#pragma once
#include<iostream>

class Node
{
public:
	Node()
	{
		next = NULL;
	}
	Node(int item, Node *add_on = NULL)
	{
		entry = item;
		next = add_on;
	}

	Node*& Next()
	{
		return next;
	}
	int Entry()
	{
		return entry;
	}
private:
	int entry;
	Node* next;
};