#include<iostream>

class Node
{
public:
	Node(int _entry, Node* _back = NULL, Node* _next = NULL);
	Node*& Next();
	Node*& Back();
	int Entry();
	~Node();
private:
	int entry;
	Node* next;
	Node* back;
};