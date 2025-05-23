#include <stdio.h>
#include <stdlib.h>

void rotate(int** matrix,int n,int* col)
{
	int temp,i,j;
    for(i=0;i<n/2;i++)
    {
        for(j=i;j<n-i-1;j++)
        {
            temp=matrix[i][j];
            matrix[i][j]=matrix[n-j-1][i];
            matrix[n-j-1][i]=matrix[n-i-1][n-j-1];
            matrix[n-i-1][n-j-1]=matrix[j][n-i-1];
            matrix[j][n-i-1]=temp;
        }
    }
}
