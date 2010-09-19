#include"Node.h"

Node::Node(int _entry,Node* _back,Node* _next)
{
	entry = _entry;
	next = _next;
	back = _back;
}

int Node::Entry()
{
	return entry;
}

Node*& Node::Next()
{
	return next;
}

Node*& Node::Back()
{
	return back;
}

Node::~Node()
{
}