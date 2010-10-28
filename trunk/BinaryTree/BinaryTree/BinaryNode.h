#pragma once
#include<iostream>

class BinaryNode
{
public:
	BinaryNode()
	{
		Left = Right = NULL;
	}
	BinaryNode(int x)
	{
		Left = Right = NULL;
		Data = x;
	}
	BinaryNode* Left;
	BinaryNode* Right;
	int Data;
};