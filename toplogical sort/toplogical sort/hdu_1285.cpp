#include<cstdio>
#include<list>
#include<string.h>
#include<vector>
using namespace std;

const int MAX = 500;
int n,cmpCnt;
bool valid[MAX];
int preSuccessorCnt[MAX];
list<int> neighbours[MAX];
vector<int> finalOrder;

void preProcess()
{
	for(int i = 0;i<=n;++i)
	{
		if(valid[i])
		{
			list<int>::iterator j;
			for(j = neighbours[i].begin();j!=neighbours[i].end();++j)
			{
				int currentV = *j;
			    ++preSuccessorCnt[currentV];
			}
		}
	}
}

void ToplogicalSort()
{
	for(int k = 0;k<n;++k)
	{
		for(int i = 1;i<=n;++i)
		{
			if(valid[i])
			{
				if(preSuccessorCnt[i] == 0)
				{
					valid[i] = false;
					finalOrder.push_back(i);
					list<int>::iterator it;
					for(it = neighbours[i].begin();it!=neighbours[i].end();++it)
					{
						int currentV = *it;
						--preSuccessorCnt[currentV];
					}
					break;
				}
			}

		}
	}
}

void Print()
{
	for(int i = 0;i<finalOrder.size();++i)
	{
		if(i == finalOrder.size()-1)
			printf("%d\n",finalOrder[i]);
		else
			printf("%d ",finalOrder[i]);
	}
}

int main()
{
	//freopen("fin.txt","r",stdin);
	while(scanf("%d%d",&n,&cmpCnt)!=EOF)
	{
		int c1,c2;
		memset(preSuccessorCnt,0,sizeof(preSuccessorCnt));
		memset(valid,0,sizeof(valid));
		for(int i = 0;i<MAX;++i)
		{
			valid[i] = true;
			neighbours[i].clear();
		}
		finalOrder.clear();
		for(int i = 0;i<cmpCnt;++i)
		{
			scanf("%d%d",&c1,&c2);
			neighbours[c1].push_back(c2);
		}
		preProcess();		
		ToplogicalSort();
		Print();
	}
	return 0;
}