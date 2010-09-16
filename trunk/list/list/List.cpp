#include"List.h"
#include<iostream>

void List::setPosition(int pos) const
{
	if(pos<currentPos)
	{
		currentPos = 0;
		current = head;
	}

	for(;currentPos!=pos;++currentPos)
		current = current->Next();
}

void List::Print()
{
	Node* now = head;
	for(int i = 0;i<count;++i)
	{
		std::cout<<(*now).Entry()<<std::endl;
		now = now->Next();
	}
	std::cout << std::endl;
}

void List::Insert(int pos,int entry)
{
	if(pos<0 || pos>count)
		return;

	Node *newNode,*previous,*following;
	
	if(pos>0)
	{
		setPosition(pos-1);
		previous = current;
		following = previous->Next();
	}
	else
	{
		following = head;
	}

	newNode = new Node(entry,following);

	if(newNode == NULL)
		return ;
	if(pos == 0)
	{
		head = newNode;
		current = head;
		currentPos = 0;
	}
	else
		previous->Next() = newNode;
	
	++count;
}

void List::Remove(int pos)
{
	if(pos<0||pos>count-1)
		return ;
	
	Node *removedNode,*previous;
	if (pos > 0) {
		setPosition(pos-1);
		removedNode = current->Next();
		current->Next() = removedNode->Next();
	} else {
		removedNode = head;
		head = head->Next();
	}
	/*setPosition(pos);
	removedNode = current;
	if(pos>0)
	{
		setPosition(pos-1);
	    previous = current;
	    setPosition(pos+1);
	    previous->Next() = current;
	}
	else
	{
		setPosition(1);
		head = current;
	}*/
	
	delete removedNode;
	--count;
}

bool List::Empty()
{
	return head == NULL;
}

void List::Clear()
{
	Node *now = head;
	for(int i = 0;i<count;++i)
	{
		Node * next = now->Next();
		delete now;
		now = next;
	}
	head = NULL;
	count = 0;
}

void List::Retrieve(int pos ,int& x)
{
	if(pos<0||pos>count-1)
		return;
	setPosition(pos);
	x = current->Entry();
}