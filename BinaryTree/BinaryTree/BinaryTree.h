#pragma once
#include"BinaryNode.h"
#include<string.h>
#include<queue>
using namespace std;

struct NodeInfo
{
	int depth;
	BinaryNode* node;
};

class BinaryTree
{
public:
	BinaryTree()
	{
		root = NULL;
	}
	
	bool Empty() const
	{
		return root == NULL;
	}

	void Preorder(void(*visit)(int& x))
	{
	}

	void Inorder(void(*visit)(int& x))
	{
	}

	void Postorder(void(*visit)(int& x))
	{
	}

	int Size() const
	{
		return recursiveNodeCnt(root);
	}

	int LeafCnt() const
	{
		return recursiveLeafCnt(root);
	}

	void Clear()
	{
		recursiveClear(root);
	}

	int Height() const
	{
		return recursiveHeightCnt(root);
	}

	int Width() const
	{
		int width = 0;
		int widthInLevel[15];
		if(root == NULL)
			return 0;
		queue<NodeInfo> nodes;
		NodeInfo rootInfo;
		rootInfo.depth = 0;
		rootInfo.node = root;
		nodes.push(rootInfo);
		memset(widthInLevel,0,sizeof(widthInLevel));
		widthInLevel[0] = 1;
		while(!nodes.empty())
		{
			NodeInfo tmp = nodes.front();
			nodes.pop();
			if((widthInLevel[tmp.depth])>=width)
				width = widthInLevel[tmp.depth];
			if(tmp.node->Left!=NULL)
			{
				NodeInfo l;
				l.depth = tmp.depth+1;
				l.node = tmp.node->Left;
				nodes.push(l);
				++widthInLevel[l.depth];
			}
			if(tmp.node->Right!=NULL)
			{
				NodeInfo r;
				r.depth = tmp.depth+1;
				r.node = tmp.node->Left;
				nodes.push(r);
				++widthInLevel[r.depth];
			}
		}
		return width;
	}

	void Insert(int x)
	{
		recursiveInsert(root,x);
	}

	BinaryTree(const BinaryTree& original)
	{
		//construct the root equals to the whole tree^^
		root = recursiveCopy(original.root);
	}

	BinaryTree& operator=(const BinaryTree& original)
	{
		//clear first!
		Clear();
		BinaryTree newTree(original);
		root = newTree.root;
		//set newTree's root null
		newTree.root = NULL;
		//pay attention to the return value
		return *this;
	}

	void SymInterchange()
	{
		recursiveSym(root);
	}

	void TraverseByLevel(void(*visit)(int x))
	{
		//bfs instead of recurve
		if(root == NULL)
			return;
		queue<BinaryNode*> nodes;
		nodes.push(root);
		while(!nodes.empty())
		{
			BinaryNode* tmp  = nodes.front();
			nodes.pop();
			visit(tmp->Data);
			if(tmp->Left!=NULL)
				nodes.push(tmp->Left);
			if(tmp->Right!=NULL)
				nodes.push(tmp->Right);
		}
	}

	//in insert order
	void Print()
	{
		if(root == NULL)
			return;
		queue<BinaryNode*> nodes;
		nodes.push(root);
		while(!nodes.empty())
		{
			BinaryNode* tmp  = nodes.front();
			nodes.pop();
			cout<<tmp->Data<<endl;
			if(tmp->Left!=NULL)
				nodes.push(tmp->Left);
			if(tmp->Right!=NULL)
				nodes.push(tmp->Right);
		}
		cout<<endl;
	}

	~BinaryTree()
	{
		Clear();
	}
private:
	BinaryNode* root;

	int recursiveNodeCnt(BinaryNode* subRoot) const
	{
		if(subRoot == NULL)
			return 0;
		return 1+recursiveNodeCnt(subRoot->Left)+recursiveNodeCnt(subRoot->Right);
	}

	int recursiveLeafCnt(BinaryNode* subRoot) const
	{
		//important!
		if(subRoot == NULL)
			return 0;
		if(subRoot->Left == NULL && subRoot->Right == NULL)
			return 1;
		return recursiveLeafCnt(subRoot->Left)+recursiveLeafCnt(subRoot->Right);
	}

	int recursiveHeightCnt(BinaryNode* subRoot) const
	{
		if(subRoot == NULL)
			return 0;
		//important!
		int l = recursiveHeightCnt(subRoot->Left);
		int r = recursiveHeightCnt(subRoot->Right);
		return 1+(l>r?l:r);
	}

	void recursiveInsert(BinaryNode*& subRoot,int& x)
	{
		if(subRoot == NULL)
			subRoot = new BinaryNode(x);
		else
		{
			if(recursiveHeightCnt(subRoot->Left) <= recursiveHeightCnt(subRoot->Right))
				recursiveInsert(subRoot->Left,x);
			else
				recursiveInsert(subRoot->Right,x);
		}
	}

	void recursiveClear(BinaryNode* subRoot)
	{
		if(subRoot == NULL)
			return;
		
		//store curent node first ,then delete it later
		BinaryNode* tmp = subRoot;
		
		recursiveClear(subRoot->Left);
		recursiveClear(subRoot->Right);

		//set current subRoot NULL!
		subRoot = NULL;
		delete tmp;
	}

	//note that the return value is a BinaryNode*
	BinaryNode* recursiveCopy(BinaryNode* subRoot)
	{
		//return NULL instead of 0
		if(subRoot == NULL)
			return NULL;
		BinaryNode* newNode = new BinaryNode(subRoot->Data);
		recursiveCopy(subRoot->Left);
		recursiveCopy(subRoot->Right);
		return newNode;
	}
	
	void recursiveSym(BinaryNode* subRoot)
	{
		if(subRoot == NULL)
			return ;
		BinaryNode* tmp = subRoot->Left;
		subRoot->Left = subRoot->Right;
		subRoot->Right = tmp;
		recursiveSym(subRoot->Left);
		recursiveSym(subRoot->Right);
	}
};