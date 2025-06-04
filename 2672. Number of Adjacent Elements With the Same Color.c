#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* colorTheArray(int n, int** queries, int m, int* queriesColSize, int* returnSize)
{
    int i,p,cnt=0;
    int list[n+2];
    int* ret=(int*)malloc(sizeof(int)*m);
    memset(list,0,sizeof(list));
    for(i=0;i<m;i++)
    {
        p=queries[i][0]+1;
        if(list[p])
        {
            if(list[p-1]==list[p])
            {
                cnt--;
            }
            if(list[p+1]==list[p])
            {
                cnt--;
            }
        }
        list[p]=queries[i][1];
        if(list[p-1]==list[p])
        {
            cnt++;
        }
        if(list[p+1]==list[p])
        {
            cnt++;
        }
        ret[i]=cnt;
    }
    *returnSize=m;
    return ret;
}
