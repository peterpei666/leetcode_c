#include <stdio.h>
#include <stdlib.h>

static inline int max(int a,int b)
{
    return a>b?a:b;
}

int areaOfMaxDiagonal(int** dimensions, int n, int* dimensionsColSize)
{
    int ans=dimensions[0][0]*dimensions[0][1];
    int dia=dimensions[0][0]*dimensions[0][0]+dimensions[0][1]*dimensions[0][1];
    for(int i=1;i<n;i++)
    {
        int temp=dimensions[i][0]*dimensions[i][0]+dimensions[i][1]*dimensions[i][1];
        if(dia==temp)
        {
            ans=max(ans,dimensions[i][0]*dimensions[i][1]);
        }
        else if(dia<temp)
        {
            dia=temp;
            ans=dimensions[i][0]*dimensions[i][1];
        }
    }
    return ans;
}
