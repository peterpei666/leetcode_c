#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool areSimilar(int** mat, int m, int* matColSize, int k)
{
    int n = matColSize[0];
    for (int i = 0; i < m; i++)
    {
        int temp[25];
        for (int j = 0; j < n; j++)
        {
            temp[((j - k) % n + n) % n] = mat[i][j];
        }
        if (memcmp(&mat[i][0], temp, sizeof(int) * n))
        {
            return false;
        }
    }
    return true;
}
