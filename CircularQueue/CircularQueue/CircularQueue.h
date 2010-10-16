#pragma once

const int MAX = 10;

class CircularQueue
{
public :
	CircularQueue();
	void Print();
	bool Empty();
	bool Full();
	void Clear();
	void ServeAndRetrieve(int &item);
	int Size();
	void Serve();
	void Append(int item);
	void Retrieve(int& item);
private:
	int count;
	int front,rear;
	int queueEntry[MAX];
};