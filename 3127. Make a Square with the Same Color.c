#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool canMakeSquare(char** grid,int m,int* gridColSize)
{
	int i,j,B;
	int n=gridColSize[0];
	for(i=0;i<m-1;i++)
		{
			for(j=0;j<n-1;j++)
			{
				B=0;
				if(grid[i][j]=='B')
				{
					B++;
				}
				if(grid[i+1][j]=='B')
				{
					B++;
				}
				if(grid[i][j+1]=='B')
				{
					B++;
				}
				if(grid[i+1][j+1]=='B')
				{
					B++;
				}
				if(B!=2)
				{
					return true;
				}
			}
		}
		return false;
}
