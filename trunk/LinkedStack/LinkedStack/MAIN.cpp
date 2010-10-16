#include"LinkedStack.h"
#include<iostream>
using namespace std;

int main()
{
	LinkedStack a;
	a.push(1);
	a.push(2);
	a.push(3);
	/*int x;;
	a.pop();*/
	int x;
	a.top(x);
	cout<<x<<endl;

	LinkedStack b(a);
	b.pop();
	b.top(x);
	cout<<x<<endl;

	LinkedStack c;
	c = a;
	c.top(x);
	cout<<x<<endl;

	return 0;
}