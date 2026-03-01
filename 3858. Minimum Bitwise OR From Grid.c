#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int minimumOR(int** grid, int gridSize, int* gridColSize)
{
    int m = gridSize;
    int n = gridColSize[0];
    int ans = 0;
    for (int b = 29; b >= 0; b--)
    {
        int temp = ans | ((1 << b) - 1);
        bool p = true;
        for (int i = 0; i < m; i++)
        {
            bool valid = false;
            for (int j = 0; j < n; j++)
            {
                if ((grid[i][j] | temp) == temp)
                {
                    valid = true;
                    break;
                }
            }
            if (!valid)
            {
                p = false;
                break;
            }
        }
        if (!p)
        {
            ans |= 1 << b;
        }
    }
    return ans;
}
