#include"Deque.h"
#include<iostream>

int main()
{
	Deque a;
	a.append_front(1);
	a.append_front(3);
	a.append_front(5);
	a.append_rear(2);
	a.append_rear(4);
	a.append_rear(6);
	a.print();

	a.serve_front();
	a.serve_rear();
	a.print();

	int x;
	a.retrieve_front(x);
	std::cout<<x<<std::endl;

	return 0;
}