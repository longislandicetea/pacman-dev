#pragma once
#include<iostream>

class ThreadNode
{
public:
	int Data;
	bool Ltag;
	bool Rtag;
	ThreadNode* Left;
	ThreadNode* Right;
};