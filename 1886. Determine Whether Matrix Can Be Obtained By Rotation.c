#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool findRotation(int** mat, int n, int* matColSize, int** target, int targetSize, int* targetColSize)
{
    bool flag[4] = {true, true, true, true};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] != target[i][j])
            {
                flag[0]=false;
            }
            if (mat[i][j] != target[j][n - i - 1])
            {
                flag[1]=false;
            }
            if (mat[i][j] != target[n - i - 1][n - j - 1])
            {
                flag[2]=false;
            }
            if (mat[i][j] != target[n - j - 1][i])
            {
                flag[3]=false;
            }
        }
    }
    return flag[0] | flag[1] | flag[2] | flag[3];
}
