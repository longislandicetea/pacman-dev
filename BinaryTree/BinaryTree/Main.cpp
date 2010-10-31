#include"BinaryTree.h"
#include<iostream>
using namespace std;

void NewPrint(int &x)
{
	cout<<x<<endl;
}


int main()
{
	BinaryTree a;
	a.Insert(1);
	a.Insert(2);
	a.Insert(3);
	a.Insert(4);
	a.Insert(5);
	//a.Print();

	a.Preorder(NewPrint);
	cout<<endl;
	a.Inorder(NewPrint);
	cout<<endl;
	a.Postorder(NewPrint);
	cout<<endl;

	cout<<"height:"<<a.Height()<<endl;
	cout<<"leaf:"<<a.LeafCnt()<<endl;
	cout<<"size:"<<a.Size()<<endl;
	cout<<endl;

	a.SymInterchange();

	cout<<a.Width()<<endl;

	return 0;
}