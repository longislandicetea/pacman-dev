#include"List.h"
#include<iostream>
using namespace std;

int main()
{
	List a;
	
	a.Insert(0,1);
	a.Insert(1,2);
	a.Insert(2,3);
	a.Insert(3,5);
	a.Print();

	a.InsertOrder(4);
	a.Print();

	/*a.Insert(3,4);
	a.Print();*/

	/*a.Remove(4);
	a.Print();
	cout << "Clear begin" << endl;
	a.Clear();
	a.Print();
	
	cout << "Clear End" << endl;
	a.Insert(0,1);
	a.Insert(1,2);
	a.Insert(2,3);
	a.Insert(3,5);
	a.Print();*/

	/*int tmp;
	a.Retrieve(1,tmp);
	cout<<tmp<<endl;*/

	/*a.Reverse();
	a.Print();*/

	/*List b(a);
	b.Print();*/

	List b(a);
	b.Remove(1);
	b.Remove(3);
	b.Insert(3,7);
	b.Print();
	/*if(IsSubset(b.GetHead(),a.GetHead()))
		cout<<"yes"<<endl;*/
	

	Node *c = InterSet(a.GetHead(),b.GetHead());
	for(;c!=NULL;c = c->Next())
	{
		cout<<c->Entry()<<endl;
	}

	return 0;
}