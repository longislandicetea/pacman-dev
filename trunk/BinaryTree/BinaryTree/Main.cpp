#include"BinaryTree.h"
#include<iostream>
using namespace std;

int main()
{
	BinaryTree a;
	a.Insert(1);
	a.Insert(2);
	a.Insert(3);
	a.Insert(4);
	a.Insert(5);
	a.Print();

	cout<<"height:"<<a.Height()<<endl;
	cout<<"leaf:"<<a.LeafCnt()<<endl;
	cout<<"size:"<<a.Size()<<endl;
	cout<<endl;

	/*a.SymInterchange();
	a.Print();*/

	cout<<a.Width()<<endl;

	return 0;
}