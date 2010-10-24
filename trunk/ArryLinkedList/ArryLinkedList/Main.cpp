#include"ArrayLinkedList.h"
#include<iostream>
using namespace std;

int main()
{
	ArrayLinkedList a;
	a.Insert(0,1);
	a.Insert(1,2);
	a.Insert(2,4);
	a.Insert(2,3);
	a.Print();

	a.Remove(2);
	a.Print();

	int x;
	a.Retrieve(0,x);
	cout<<x<<endl;
	cout<<endl;

	a.Replace(2,5);
	a.Print();

	cout<<a.Size()<<endl;
	
	return 0;
}