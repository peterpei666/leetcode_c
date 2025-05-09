#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

unsigned char P[200][25]={0};
unsigned char A[200][25]={0};
int dir[4][2]={-1,0,0,-1,1,0,0,1};
int m,n;

inline bool test(int x,int y,char c)
{
    if(c=='P')
    {
        return P[x][y>>3]&(1<<(y&7))?1:0;
    }
    else
    {
        return A[x][y>>3]&(1<<(y&7))?1:0;
    }
}

inline void set(int x,int y,char c)
{
    if(c=='P')
    {
        P[x][y>>3]|=1<<(y&7);
    }
    else
    {
        A[x][y>>3]|=1<<(y&7);
    }
}

void dfs(int x,int y,char c,int** heights)
{
    int nx,ny,i;
    set(x,y,c);
    for(i=0;i<4;i++)
    {
        nx=x+dir[i][0];
        ny=y+dir[i][1];
        if(nx>=0&&nx<m&&ny>=0&&ny<n)
        {
            if(heights[nx][ny]>=heights[x][y]&&test(nx,ny,c)==false)
            {
                dfs(nx,ny,c,heights);
            }
        }
    }
}

int** pacificAtlantic(int** heights, int heightsSize, int* heightsColSize, int* returnSize, int** returnColumnSizes)
{
    int i,j,count=0,size=10;
    int** ret=(int**)malloc(sizeof(int*)*size);
    m=heightsSize;
    n=heightsColSize[0];
    memset(P,0,sizeof(P));
    memset(A,0,sizeof(A));
    for(i=0;i<n;i++)
    {
        dfs(0,i,'P',heights);
    }
    for(i=0;i<m;i++)
    {
        dfs(i,0,'P',heights);
    }
    for(i=0;i<n;i++)
    {
        dfs(m-1,i,'A',heights);
    }
    for(i=0;i<m;i++)
    {
        dfs(i,n-1,'A',heights);
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(test(i,j,'P')&&test(i,j,'A'))
            {
                if(count>=size)
                {
                    size*=2;
                    ret=(int**)realloc(ret,sizeof(int*)*size);
                }
                ret[count]=(int*)malloc(sizeof(int)*2);
                ret[count][0]=i;
                ret[count][1]=j;
                count++;
            }
        }
    }
    *returnSize=count;
    *returnColumnSizes=(int*)malloc(sizeof(int)*count);
    for(i=0;i<count;i++)
    {
        (*returnColumnSizes)[i]=2;
    }
    return ret;
}
