#pragma once
#include"ThreadNode.h"

class ThreadBinaryTree
{
public:
	ThreadBinaryTree()
	{
		root = NULL;
	}

	void InOrderThreadize(ThreadNode* current,ThreadNode* pre)
	{
		if(current!=NULL)
		{
			InOrderThreadize(current->Left,pre);
			if(current->Left == NULL)
			{
				current->Left = pre;
				current->Ltag = true;
			}
			if(pre!=NULL)
			{
				if(pre->Right == NULL)
				{
					pre->Right = current;
					pre->Rtag = true;
				}
			}
			//dont't forget that when it comes to the right child,current should be right child's pre
			pre = current;
			InOrderThreadize(current->Right,pre);
		}
	}
	
	ThreadNode* First()
	{
		return root;
	}

	ThreadNode* Prior(ThreadNode* current)
	{
		ThreadNode* pre;
		if(current->Ltag)
			pre = current->Left;
		else
		{
			pre = current->Left;
			while(!pre->Rtag)
				pre = pre->Right;
		}
		return pre;
	}

	ThreadNode* Next(ThreadNode* current)
	{
		ThreadNode* next;
		if(current->Rtag)
			next = current->Right;
		else
		{
			next = current->Right;
			while(!next->Ltag)
				next = next->Left;
		}
		return next; 
	}

	void InsertRight(ThreadNode* parent,ThreadNode* child)
	{
		if(parent->Rtag)
		{
			//firstly,set child's right items
			child->Right = parent->Right;
			child->Rtag = parent->Rtag;
			
			// very very very important! set the parent's old right child!
			if(child->Right->Ltag)
				child->Left = parent;

			//set new right child and parent
			child->Left = parent;
			child->Ltag = true;
			parent->Right = child;
			parent->Rtag = false;
		}
		else
		{
			//find the "first node" of the origin right child
			ThreadNode* current = parent->Right;
			while(current->Ltag)
				current = current->Left;

			//first set current
			current->Left = child;

			//secondly set child
			child->Left = parent;
			child->Ltag = true;
			child->Right = parent->Right;
			child->Rtag = false;

			//lastly set parent
			parent->Right = child;
			parent->Rtag = false;
		}
	}

	void DeleteRight(ThreadNode* node,ThreadNode* parent)
	{
		ThreadNode* current;
		if(node == NULL)
			return;
		
		//node is leaf
		if(node->Ltag==true && node->Rtag==true)
		{
			parent->Right = NULL;
			parent->Rtag = true;
		}

		//node just has left child
		else if(node->Ltag==false && node->Rtag==true)
		{
			current = node->Left; 
			while(!current->Ltag)
				current = current->Left;

			parent->Right = node->Left;
			parent->Rtag = false;

			current->Left = parent;

		}

		//node just has right child
		else if(node->Ltag==true && node->Rtag==false)
		{
			current= node->Right;
			while(!current->Ltag)
				current = current->Left;

			parent->Right = node->Right;
			parent->Rtag = false;

			current->Left = parent;
		}

		//node has two children
		else if(node->Ltag==false && node->Rtag==false)
		{
			ThreadNode *current2,*current3;
			
			parent->Right = node->Left;

			current = current2 =  node->Left;
			while(!current->Ltag)
				current = current->Left;
			while(!current2->Rtag)
				current2 = current2->Right;
			current->Left = parent;
			current2->Right = node->Right;
			current2->Rtag = false;

			current3 = node->Right;
			while(!current3->Ltag)
				current3 = current3->Left;
			current3->Left = current2;
		}
	}
private:
	ThreadNode* root;
};