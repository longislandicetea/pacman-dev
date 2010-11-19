#include<cstdio>
#include<string.h>

const int MAXN = 110;
const int INF = 1<<30;

int n,m;
int adjTable[MAXN][MAXN];
int distance[MAXN];
int min;
bool found[MAXN];

int Dijkstra(int source) 
{
    /*for(int i = 1;i<=n;++i)
    {
        if(adjTable[source][i])
            distance[i] = adjTable[source][i];
        else
            distance[i] = INF;
    }

    found[source] = true;*/
    for (int i = 1;i<=n;++i)
        distance[i] = INF;

    distance[source] = 0;

    for(int i = 0;i<n;++i)
    {
        min = INF;
        int currentV = INF;
        for(int j = 1;j<=n;++j)
        {
            if(found[j])
                continue;
            if(distance[j]<min)
            {
                currentV = j;
                min = distance[j];
            }
        }
        found[currentV] = true;
        for(int j = 1;j<=n;++j)
        {
            if(found[j])
                continue;
            if(min+adjTable[currentV][j]<distance[j])
                distance[j] = min+adjTable[currentV][j];
        }
    }
    return distance[n];
}

int main()
{
    //freopen("fin.txt","r",stdin);
    while(1)
    {
		scanf("%d %d",&n,&m);
        if(n == 0 && m == 0)
            break;
        memset(adjTable,0,sizeof(adjTable));
        memset(distance,0,sizeof(distance));
        memset(found,0,sizeof(found));
        for(int i = 0;i<m;++i)
        {
            int p1,p2;
            scanf("%d%d",&p1,&p2);
            scanf("%d",&adjTable[p1][p2]);
            adjTable[p2][p1] = adjTable[p1][p2];
        }
        printf("%d\n",Dijkstra(1));
    }
    return 0;
}