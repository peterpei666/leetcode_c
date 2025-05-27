#include <stdio.h>
#include <stdlib.h>

int* lexicalOrder(int n, int* returnSize)
{
    int i,k=0,cur=1;
    int* ret=(int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
    {
        ret[k]=cur;
        k++;
        if(cur*10<=n)
        {
            cur*=10;
        }
        else
        {
            while(cur%10==9||cur>=n)
            {
                cur/=10;
            }
            cur++;
        }
    }
    *returnSize=n;
    return ret;
}
