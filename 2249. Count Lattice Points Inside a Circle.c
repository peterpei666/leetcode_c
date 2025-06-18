#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

unsigned char visited[201][26];

inline bool test(int x,int a)
{
    return visited[x][a>>3]&(1<<(a&7))?true:false;
}

inline void set(int x,int a)
{
    visited[x][a>>3]|=1<<(a&7);
}

int countLatticePoints(int** circles, int n, int* circlesColSize)
{
    int i,j,k,d;
    int ans=0;
    memset(visited,0,sizeof(visited));
    for(k=0;k<n;k++)
    {
        for(i=0;i<=circles[k][2];i++)
        {
            d=sqrt(circles[k][2]*circles[k][2]-i*i);
            for(j=circles[k][1]-d;j<=circles[k][1];j++)
            {
                set(circles[k][0]+i,j);
                set(circles[k][0]+i,2*circles[k][1]-j);
                set(circles[k][0]-i,j);
                set(circles[k][0]-i,2*circles[k][1]-j);
            }
        }
    }
    for(i=0;i<201;i++)
    {
        for(j=0;j<201;j++)
        {
            if(test(i,j))
            {
                ans++;
            }
        }
    }
    return ans;
}
