#include <stdio.h>
#include <stdlib.h>

int** generate(int n, int* returnSize, int** returnColumnSizes)
{
    int** ans=(int**)malloc(sizeof(int*)*n);
    *returnSize=n;
    *returnColumnSizes=(int*)malloc(sizeof(int)*n);
    for(int i=1;i<=n;i++)
    {
        ans[i-1]=(int*)malloc(sizeof(int)*i);
        ans[i-1][0]=1;
        ans[i-1][i-1]=1;
        for(int j=1;j<i-1;j++)
        {
            ans[i-1][j]=ans[i-2][j-1]+ans[i-2][j];
        }
        (*returnColumnSizes)[i-1]=i;
    }
    return ans;
}
