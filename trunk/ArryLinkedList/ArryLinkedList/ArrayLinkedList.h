#pragma once
#include"Node.h"
#include<iostream>
using namespace std;

const int MAX = 7;

class ArrayLinkedList
{
public:
	ArrayLinkedList()
	{
		head = -1;
		available = -1;
		lastUsed = -1;
		count = 0;
	}
	
	int Size() const
	{
		return count;
	}

	bool Full() const
	{
		return count == MAX;
	}

	bool Empty() const
	{
		return count == 0;
	}

	//find the next first,then delete the current
	void Clear()
	{
		//p,q are both index;
		int p,q;
		for(p = head;p!=-1;p = q)
		{
			q = workspace[p].Next;
			deleteNode(p);
		}
		head = -1;
		count = 0;
	}

	void Traverse(void(*visit)(int x))
	{
		for(int index = head;index!=-1;index = workspace[index].Next)
			(*visit)(workspace[index].Entry);
	}

	void Retrieve(int pos,int& x)
	{
		int index = setPos(pos);
		x = workspace[index].Entry;
	}

	void Replace(int pos,int x)
	{
		int index = setPos(pos);
		workspace[index].Entry = x;
	}

	void Remove(int pos)
	{
		int oldIndex,previous;
		if(pos<0||pos>count)
			return;
		oldIndex = setPos(pos);
		if(pos>0)
		{
			previous = setPos(pos-1);
			workspace[previous].Next = workspace[oldIndex].Next;
		}
		else
			head = workspace[oldIndex].Next;
		deleteNode(oldIndex);
		--count;
	}

	void Insert(int pos,int x)
	{
		int newIndex,previous,following;
		if(pos<0||pos>count)
			return;
		if(pos>0)
		{
			previous = setPos(pos-1);
			following = workspace[previous].Next;
		}
		else
			following = head;
		/*if(newNode()==-1)
			return;*/
		newIndex = newNode();
		workspace[newIndex].Entry = x;
		workspace[newIndex].Next = following;
		if(pos == 0)
			head = newIndex;
		else
			workspace[previous].Next = newIndex;
		++count;
	}

	void Print()
	{
		for(int index = head;index!=-1;index = workspace[index].Next)
			cout<<workspace[index].Entry<<endl;
		cout<<endl;
	}
private:
	int count;
	Node workspace[MAX];
	int available,lastUsed,head;
	int newNode()
	{
		int newIndex;
		if(available!=-1)
		{
			newIndex = available;
			available = workspace[available].Next;
		}
		else if(lastUsed<MAX)
		{
			newIndex = ++lastUsed;
		}
		else
			return -1;
		workspace[newIndex].Next = -1;
		return newIndex;
	}

	void deleteNode(int index)
	{
		//content below has been implemented in Remove(),don't do it again!
		/*int previous;
		if(index == head)
		{
			head = workspace[index].Next;
		}
		else
		{
			previous = setPos(currentPos(index)-1);
			workspace[previous].Next = workspace[index].Next;
		}*/
		workspace[index].Next = available;
		available = index;
	}

	int currentPos(int _index) const
	{
		int i = 0;
		for(int index = head;index!=-1;index = workspace[index].Next,++i)
		{
			if(index == _index)
				return i;
		}
		return -1;
	}

	int setPos(int pos) const
	{
		int index = head;
		for(int i = 0;i<pos;++i)
		{
			index = workspace[index].Next;
		}
		return index;
	}
};