#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* p1,const void* p2)
{
    int** a=(int**)p1;
    int** b=(int**)p2;
    return (*a)[0]==(*b)[0]?(*a)[1]-(*b)[1]:(*a)[0]-(*b)[0];
}

int* findingUsersActiveMinutes(int** logs, int n, int* logsColSize, int k, int* returnSize)
{
    int i;
    int cur=-1,m=-1;
    int list[n];
    int* ans=(int*)calloc(sizeof(int),k);
    memset(list,0,sizeof(list));
    qsort(logs,n,sizeof(int*),cmp);
    for(i=0;i<n;i++)
    {
        if(i&&logs[i][0]==logs[i-1][0]&&logs[i][1]==logs[i-1][1])
        {
            continue;
        }
        else
        {
            if(cur==-1||cur!=logs[i][0])
            {
                cur=logs[i][0];
                m++;
            }
            list[m]++;
        }
    }
    for(i=0;i<=m;i++)
    {
        if(list[i]&&list[i]-1<k)
        {
            ans[list[i]-1]++;
        }
    }
    *returnSize=k;
    return ans;
}
