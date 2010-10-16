#include"CircularQueue.h"
#include<iostream>

CircularQueue::CircularQueue()
{
	count = 0;
	front = 0;
	rear = MAX-1;
}

bool CircularQueue::Empty()
{
	return count == 0;
}

int CircularQueue::Size()
{
	return count;
}

void CircularQueue::Serve()
{
	if(count<=0)
		return ;
	--count;
	front = ((front+1)==MAX)?0:front+1;
}

void CircularQueue::Append(int item)
{
	if(count>=MAX)
		return;
	++count;
	rear = ((rear+1)==MAX)?0:rear+1;
	queueEntry[rear] = item;
}

void CircularQueue::Retrieve(int& item)
{
	if(count<=0)
		return;
	item = queueEntry[front];
}

bool CircularQueue::Full()
{
	return count == MAX-1;
}

void CircularQueue::Clear()
{
	std::cout<<"clear begin"<<std::endl;
	front = 0;
	rear = MAX-1;
	count = 0;
	std::cout<<"clear end"<<std::endl;
}

void CircularQueue::ServeAndRetrieve(int& item)
{
	if(count<=0)
		return;
	--count;
	item = queueEntry[front];
	front = ((front+1)==MAX)?0:front+1;
}

void CircularQueue::Print()
{
	if(this->Empty())
	{
		std::cout<<"emtpy!"<<std::endl;
		return;
	}
	int tmp;
	CircularQueue tmpQueue;

	while(!this->Empty())
	{
		this->Retrieve(tmp);
		tmpQueue.Append(tmp);
		this->Serve();
		std::cout<<tmp<<std::endl;
	}
	std::cout<<std::endl;

	while(!tmpQueue.Empty())
	{
		tmpQueue.Retrieve(tmp);
		this->Append(tmp);
		tmpQueue.Serve();
	}
}

