#include <stdio.h>
#include <stdlib.h>

int* countPoints(int** points, int m, int* pointsColSize, int** queries, int n, int* queriesColSize, int* returnSize)
{
    int i,j;
    int* ret=(int*)calloc(n,sizeof(int));
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if((queries[i][0]-points[j][0])*(queries[i][0]-points[j][0])+(queries[i][1]-points[j][1])*(queries[i][1]-points[j][1])<=queries[i][2]*queries[i][2])
            {
                ret[i]++;
            }
        }
    }
    *returnSize=n;
    return ret;
}
