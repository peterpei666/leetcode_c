#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int** spiralMatrixIII(int rows, int cols, int r, int c, int* returnSize, int** returnColumnSizes)
{
    int i,j,s,d,k;
    int dir[4][2]={0,1,1,0,0,-1,-1,0};
    int** ret=(int**)malloc(sizeof(int*)*rows*cols);
    *returnColumnSizes=(int*)malloc(sizeof(int)*rows*cols);
    *returnSize=rows*cols;
    for(k=0;k<rows*cols;k++)
    {
        ret[k]=(int*)malloc(sizeof(int)*2);
        (*returnColumnSizes)[k]=2;
    }
    for(d=0,k=0,s=1;k<rows*cols;s++)
    {
        for(i=0;i<2;i++)
        {
            for(j=0;j<s;j++)
            {
                if(r>=0&&r<rows&&c>=0&&c<cols)
                {
                    ret[k][0]=r;
                    ret[k][1]=c;
                    k++;
                }
                r+=dir[d][0];
                c+=dir[d][1];
            }
            d=(d+1)%4;
        }
    }
    return ret;
}
