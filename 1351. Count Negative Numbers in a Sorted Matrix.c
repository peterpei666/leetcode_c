#include <stdio.h>
#include <stdlib.h>

int countNegatives(int** grid, int gridSize, int* gridColSize)
{
    int m = gridSize;
    int n = gridColSize[0];
    int ans = 0;
    for (int i = m - 1; i >= 0 && grid[i][n - 1] < 0; i--)
    {
        for (int j = n - 1; j >= 0 && grid[i][j] < 0; j--)
        {
            ans++;
        }
    }
    return ans;
}
