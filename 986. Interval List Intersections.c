#include <stdio.h>
#include <stdlib.h>

static inline int min(int a,int b)
{
    return a<b?a:b;
}

static inline int max(int a,int b)
{
    return a>b?a:b;
}

int** intervalIntersection(int** list1, int m, int* firstListColSize, int** list2, int n, int* secondListColSize, int* returnSize, int** returnColumnSizes)
{
    int i=0,j=0,k=0;
    int sz=10;
    int** ret=(int**)malloc(sizeof(int*)*sz);
    while(i<m&&j<n)
    {
        int l=max(list1[i][0],list2[j][0]);
        int r=min(list1[i][1],list2[j][1]);
        if(l<=r)
        {
            if(k==sz)
            {
                sz*=2;
                ret=(int**)realloc(ret,sizeof(int*)*sz);
            }
            ret[k]=(int*)malloc(sizeof(int)*2);
            ret[k][0]=l;
            ret[k][1]=r;
            k++;
        }
        if(list1[i][1]<list2[j][1])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    *returnSize=k;
    *returnColumnSizes=(int*)malloc(sizeof(int)*k);
    for(i=0;i<k;i++)
    {
        (*returnColumnSizes)[i]=2;
    }
    return ret;
}
