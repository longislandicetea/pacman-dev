#pragma once
#include<iostream>
#include"Node.h"

const int MAX = 7;

typedef int index;

class List
{
public:
	List()
	{
		count = 0;
		available = lastUsed = current = previous = -1;
		currentPos = -1;
	}

	void Insert(int pos,int x)
	{
		if(pos<0||pos>MAX)
			return;

		index currentNew,preceding,following;
		currentNew = newNode();
		if(pos == 0)
		{
			if(count == 0)
				following = -1;
			else
			{
				setPos(0);
				following = current;
			}
			preceding = -1;
		}
		else
		{
			setPos(pos);
			preceding = previous;
			following = current;
		}
		workspace[currentNew].Entry = x;
		workspace[currentNew].Diff = following - preceding;
		//the diff of preceding and following also changed,so we must reset them to maintain workspace well
		if(preceding!=-1)
			workspace[preceding].Diff += currentNew - following;
		if(following!=-1)
			workspace[following].Diff -= currentNew - preceding;
		current = currentNew;
		currentPos = pos;
		++count;
	}

	//wrong?
	void Remove(int pos)
	{
		if(pos<0||pos>=MAX||count == 0)
			return;
		index oldNode,preceding,following;
		setPos(pos);
		oldNode = current;
		preceding = previous;
		following = preceding+workspace[current].Diff;
		if(preceding!=-1)
			workspace[preceding].Diff += following - oldNode;
		
		if(following!=-1)
		{
			workspace[following].Diff -= preceding - oldNode;
			//set current
			current = following;
		}
		//dont't forget to take special care if following = -1
		else
		{
			current = preceding;
			--currentPos;
			//reset previous too
			if(currentPos>=0)
				previous = following - workspace[current].Diff;
		}
		deleteNode(oldNode);
		--count;
	}

private:
	int count;
	index available,lastUsed,current,previous;
	int currentPos;
	Node workspace[MAX];
	
	index newNode()
	{
		int newIndex;
		if(available!=-1)
		{
			newIndex = available;
			//available = workspace[available].Next;
		}
		else if(lastUsed<MAX)
		{
			newIndex = ++lastUsed;
		}
		else
			return -1;
		//workspace[newIndex].Next = -1;
		return newIndex;
	}
	
	void deleteNode(int deleteIndex)
	{
	}
	
	void setPos(int pos)
	{
		index tmp;
		if(currentPos<=pos)
		{
			for(;currentPos!=pos;++currentPos)
			{
				//current must be stored to assign old current to previous
				tmp = current;
				current = workspace[current].Diff+previous;
				previous = tmp;
			}
		}
		else
		{
			for(;currentPos!=pos;--currentPos)
			{
				tmp = previous;
				previous = tmp - workspace[previous].Diff;
				current = tmp;
			}
		}
	}
};