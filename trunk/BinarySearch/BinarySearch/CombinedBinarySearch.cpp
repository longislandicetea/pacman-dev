#include<iostream>
#include<vector>
using namespace std;

int Median(vector<int>& l1,vector<int>& l2)
{
	int bottem1,top1,mid1,bottem2,top2,mid2;
	int a,b,c;
	int data1,data2;

	bottem1 = bottem2 = 0;
	top1 = l1.size()-1;
	top2 = l2.size()-1;

	while(top1>bottem1)
	{
		mid1 = (top1+bottem1)/2;
		data1 = l1[mid1];
		mid2 = (top2+bottem2)/2;
		data2 = l2[mid2];

		int reduce = (top1-bottem1+1)/2;

		if(data1<data2)
		{
			bottem1 += reduce;
			top2 -= reduce;
		}
		else
		{
			bottem2 += reduce;
			top1 -= reduce;
		}
	}

	a = l1[top1];

	//l2 only has one element
	if(bottem2 == top2)
	{
		b = l2[top2];
		if(a<=b)
			return a;
		return b;
	}
	//l2 has more than one elements
	else
	{
		mid2 = (top2+bottem2-1)/2;
		b = l2[mid2];
		c = l2[mid2+1];
		if(a<=b)
			return a;
		else if(a<=c)
			return a;
		else
			return c;
	}
}
int main()
{
	int a[] = {1,2,4};
	int b[] = {3,5,6,8};

	vector<int> l1(a,a+3);
	vector<int> l2(b,b+4);
	cout<<Median(l1,l2)<<endl;
	return 0;
}