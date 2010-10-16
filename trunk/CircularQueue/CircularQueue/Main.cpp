#include"CircularQueue.h"
#include<iostream>

int main()
{
	CircularQueue a;
	a.Append(1);
	a.Append(2);
	a.Append(3);
	a.Print();

	/*int x;
	a.ServeAndRetrieve(x);
	a.Print();
	std::cout<<x<<std::endl;*/

	a.Clear();
	a.Print();

	return 0;
}