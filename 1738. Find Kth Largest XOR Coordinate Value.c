#include <stdio.h>
#include <stdlib.h>

int cmp(const void* p1,const void* p2)
{
    return *(int*)p2-*(int*)p1;
}

int kthLargestValue(int** matrix, int matrixSize, int* matrixColSize, int k)
{
    int i,j;
    int m=matrixSize;
    int n=matrixColSize[0];
    int val[m][n];
    val[0][0]=matrix[0][0];
    for(i=1;i<m;i++)
    {
        val[i][0]=val[i-1][0]^matrix[i][0];
    }
    for(i=1;i<n;i++)
    {
        val[0][i]=val[0][i-1]^matrix[0][i];
    }
    for(i=1;i<m;i++)
    {
        for(j=1;j<n;j++)
        {
            val[i][j]=val[i-1][j]^val[i][j-1]^val[i-1][j-1]^matrix[i][j];
        }
    }
    qsort(&val[0][0],m*n,sizeof(int),cmp);
    return *(&val[0][0]+k-1);
}
