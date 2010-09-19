#include"DoubleLinkedList.h"
#include<iostream>

int main()
{
	DoubleLinkedList a;
	a.Insert(0,1);
	a.Insert(1,2);
	a.Insert(2,3);
	a.Insert(3,5);
	a.Print();
	
	a.Insert(3,4);
	a.Print();

	a.Remove(3);
	a.Print();

	DoubleLinkedList b(a);
	b.Print();

	b.Clear();
	b.Print();


	/*int x;
	a.Retrieve(2,x);
	std::cout<<x<<std::endl;*/
	
	return 0;
}