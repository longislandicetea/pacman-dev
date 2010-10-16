#include"LinkedQueue.h"
#include<iostream>
using namespace std;

int main()
{
	LinkedQueue a;
	a.Append(1);
	a.Append(2);
	a.Append(3);
	a.Serve();
	int x;
	a.ServeAndRetrieve(x);
	cout<<x<<endl;

	/*LinkedQueue b;
	b = a;
	b.ServeAndRetrieve(x);
	cout<<x<<endl;
	b.Serve();
	//b.Retrieve(x);
	//cout<<x<<endl;
	return 0;*/
}