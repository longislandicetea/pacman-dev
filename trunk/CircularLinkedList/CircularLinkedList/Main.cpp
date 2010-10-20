#include<iostream>
#include"CircularLinkedList.h"

int main()
{
	CircularLinkedQueue a;
	a.Append(1);
	a.Append(2);
	a.Append(3);
	a.Serve();
	int x;
	a.Retrieve(x);
	std::cout<<x<<std::endl;

	CircularLinkedQueue b;
	b = a;
	b.Serve();
	std::cout<<x<<std::endl;

	return 0;
}