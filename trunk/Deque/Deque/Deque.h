#include<iostream>

const int MAX = 10;

class Deque
{
public:
	Deque()
	{
		rear = -1;
	}
	bool empty( )
	{
		return rear<0;
	}
	void serve_front( )
	{
		if(rear<0)
			return;
		for(int i = 0;i<rear;++i)
		{
			entry[i] = entry[i+1];
		}
		--rear;
	}
	void serve_rear( )
	{
		if(rear<0)
			return;
		--rear;
	}
	void append_front(const int item)
	{
		if(rear == MAX-1)
			return;
		for(int i = rear+1;i>0;--i)
		{
			entry[i] = entry[i-1];
		}
		++rear;
		entry[0] = item;
	}
	void append_rear(const int item)
	{
		if(rear == MAX-1)
			return;
		entry[++rear] = item;
	}
	void retrieve_front(int &item)
	{
		if(rear<0)
			return;
		item = entry[0];
	}
	void retrieve_rear(int &item)
	{
		if(rear<0)
			return;
		item = entry[rear];
	}
	void print()
	{
		for(int i = 0;i<=rear;++i)
			std::cout<<entry[i]<<std::endl;
		std::cout<<std::endl;
	}
private:
	int rear;
	int entry[MAX];
};