#include"Node.h"

class DoubleLinkedList
{
public:
	DoubleLinkedList();
	DoubleLinkedList(DoubleLinkedList& copy);
	~DoubleLinkedList();
	void Print();
	void Clear();
	int Size();
	bool Empty();
	void Insert(int pos,int entry);
	void Retrieve(int pos,int& x);
	void Remove(int pos);
	void Traverse(void(*visit)(int));
protected:
	int cnt;
	mutable int currentPos;
	mutable Node* current;
	void setPosition(int pos);
};