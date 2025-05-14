#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

inline bool test(int a,int b,unsigned char visited[][13])
{
    return visited[a][b>>3]&(1<<(b&7))?true:false;
}

inline void set(int a,int b,unsigned char visited[][13])
{
    visited[a][b>>3]|=1<<(b&7);
}

int count(int a,unsigned char visited[][13])
{
    int c=0,i,x;
    for(i=0;i<13;i++)
    {
        x=1;
        while(visited[a][i]>=x)
        {
            c+=(visited[a][i]&x)?1:0;
            x<<=1;
        }
    }
    return c;
}

inline int maxi(int a,int b)
{
    return a>b?a:b;
}

int maximalNetworkRank(int n, int** roads, int roadsSize, int* roadsColSize)
{
    int i,j,m=0;
    int rank[n];
    unsigned char visited[n][13];
    memset(visited,0,sizeof(visited));
    for(i=0;i<roadsSize;i++)
    {
        set(roads[i][0],roads[i][1],visited);
        set(roads[i][1],roads[i][0],visited);
    }
    for(i=0;i<n;i++)
    {
        rank[i]=count(i,visited);
    }
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            m=maxi(m,(rank[i]+rank[j]-(test(i,j,visited)?1:0)));
        }
    }
    return m;
}
