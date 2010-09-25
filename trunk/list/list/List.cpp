#include"List.h"
#include<iostream>
#include<stack>
using namespace std;

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

List::List(List& copy)
{
	count = copy.count;
	Node *now,*oldNode;
	oldNode = copy.head;
	head = oldNode;
	if(oldNode!=NULL)
	{
		now = head = new Node(oldNode->Entry());
		while(oldNode->Next()!=NULL)
		{
			oldNode = oldNode->Next();
			now->Next() = new Node(oldNode->Entry());
			now = now->Next();
		}
	}
	currentPos = 0;
	current = head;
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
	
	if (pos > 0) 
	{
		setPosition(pos-1);
		removedNode = current->Next();
		current->Next() = removedNode->Next();
	}
	else 
	{
		removedNode = head;
		head = head->Next();
		currentPos = 0;
		current = head;
	}
	
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
		Node *next = now->Next();
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

void List::Reverse()
{
	//ÔÝ´æ·¨
	/*List tmp;
	int t;
	for(int i = 0;i<count;++i)
	{
		Retrieve(i,t);
		tmp.Insert(i,t);
	}
	for(int i = 0;i<count;++i)
	{
		Remove(i);
		tmp.Retrieve(tmp.Size()-1-i,t);
		Insert(i,t);
	}*/

	//stack·¨
	stack<int> tmp;
	int cnt = count;
	int t;
	while (cnt--) 
	{
		Retrieve(0,t);
		Remove(0);
		tmp.push(t);
	}
	while (!tmp.empty()) 
	{
		Insert(count,tmp.top());
		tmp.pop();
	}
}

void List::InsertOrder(int insertEntry)
{
	Node *following,*previous,*newNode;
	following = head;
	previous = NULL;
	while(following!=NULL)
	{
		if(insertEntry<following->Entry())
			break;
		previous = following;
		following = following->Next();
	}

	newNode = new Node(insertEntry,following);

	if(previous == NULL)
		head = newNode;
	else
		previous->Next() = newNode;

	++count;
}

Node* List::GetHead()
{
	return head;
}



