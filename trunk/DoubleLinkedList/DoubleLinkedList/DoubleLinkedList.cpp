#include"DoubleLinkedList.h"
#include<iostream>

DoubleLinkedList::DoubleLinkedList()
{
	cnt = 0;
	//currentPos = 0;
	currentPos = -1;
	current = NULL;
}

DoubleLinkedList::DoubleLinkedList(DoubleLinkedList& copy)
{
	cnt = copy.cnt;
	currentPos = copy.currentPos;
	Node *newNode,*oldNode;
	oldNode = copy.current;

	//don't forget if copy.current=NULL!
	if(oldNode == NULL)
		current = NULL;
	else
	{
		newNode = oldNode;
		//must use operator new here.because copy assignment doesn't copy its entry.
		current = new Node(newNode->Entry());
		while(oldNode->Next()!=NULL)
		{
			oldNode = oldNode->Next();
			newNode->Next() = new Node(oldNode->Entry(),newNode);
			newNode = newNode->Next();
		}
		newNode = current;
		oldNode = copy.current;
		while(oldNode->Back()!=NULL)
		{
			oldNode = oldNode->Back();
			newNode->Back() = new Node(oldNode->Entry(),NULL,oldNode->Next());
			newNode = newNode->Back();
		}
	}
}

void DoubleLinkedList::Print()
{
	if(current == NULL)
		return;
	//不能改变current和currentPos的值！
	Node* tmp = current;
	while(tmp->Back()!=NULL)
		tmp = tmp->Back();
	while(tmp!=NULL)
	{
		std::cout<<tmp->Entry()<<std::endl;
		tmp = tmp->Next();
	}
	std::cout<<std::endl;
}

void DoubleLinkedList::setPosition(int pos)
{
	if(pos<0||pos>cnt-1)
		return;
	if(pos<currentPos)
	{
		for(;pos != currentPos;--currentPos)
			current = current->Back();
	}
	else
	{
		for(;pos != currentPos;++currentPos)
			current = current->Next();
	}
}

void DoubleLinkedList::Insert(int pos,int entry)
{
	if(pos<0 || pos>cnt)
		return ;
	
	Node *newNode,*preceding,*following;

	if(pos == 0)
	{
		preceding = NULL;
		if(cnt == 0)
			following = NULL;
		else
		{
			setPosition(0);
			following = current;
		}
	}
	else
	{
		setPosition(pos-1);
		preceding = current;
		following = current->Next();
	}

	newNode = new Node(entry,preceding,following);

	if(newNode == NULL)
		return;
	if(preceding != NULL)
		preceding->Next() = newNode;
	if(following != NULL)
		following->Back() = newNode;

	current = newNode;
	currentPos = pos;
	++cnt;
}

void DoubleLinkedList::Clear()
{
	std::cout<<"clear begin"<<std::endl;

	//don't forget if current=NULL!
	if(current == NULL)
		return;
	Node *p,*q;
	for(p = current->Back();p;p = q)
	{
		q = p->Back();
		delete p;
	}
	for(p = current->Next();p;p = q)
	{
		q = p->Next();
		delete p;
	}
	current = NULL;
	cnt = 0;
	currentPos = -1;
	
	std::cout<<"clear end"<<std::endl;
}

void DoubleLinkedList::Remove(int pos)
{
	setPosition(pos);
	Node *preceding,*following;
	
	if(pos == 0)
	{
		following = current->Next();
		following->Back() = NULL;
		current->Next() = NULL;
	}
	else
	{
		preceding = current->Back();
		following = current->Next();
		preceding->Next() = following;
		following->Back() = preceding;
	}

	delete current;
	current = following;
	--cnt;
}

void DoubleLinkedList::Retrieve(int pos,int& x)
{
	if(pos<0||pos>cnt-1||current == NULL)
		return ;
	setPosition(pos);
	x = current->Entry();
}

bool DoubleLinkedList::Empty()
{
	return cnt == 0;
}

void DoubleLinkedList::Traverse(void(*visit)(int))
{
	Node* tmp = current;
	while(tmp->Back()!=NULL)
		tmp = tmp->Back();
	while(tmp!=NULL)
		(*visit)(tmp->Entry());
}

int DoubleLinkedList::Size()
{
	return cnt;
}

DoubleLinkedList::~DoubleLinkedList()
{
	//use func directly
	std::cout<<"destuctor begin"<<std::endl;
	Clear();
	std::cout<<"destructor end"<<std::endl;
}

