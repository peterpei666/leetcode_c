#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double knightProbability(int n, int k, int row, int column)
{
    int dir[8][2] = {1, 2, 2, 1, -1, 2, -2, 1, 1, -2, 2, -1, -1, -2, -2, -1};
    double cur[25][25] = {0.0};
    cur[row][column] = 1.0;
    for (int i = 0; i < k; i++)
    {
        double next[25][25] = {0.0};
        for (int x = 0; x < n; x++)
        {
            for (int y = 0; y < n; y++)
            {
                if (cur[x][y] > 0.0)
                {
                    for (int d = 0; d < 8; d++)
                    {
                        int nx = x + dir[d][0];
                        int ny = y + dir[d][1];
                        if (nx >= 0 && nx < n && ny >= 0 && ny < n)
                        {
                            next[nx][ny] += cur[x][y] / 8;
                        }
                    }
                }
            }
        }
        memcpy(cur, next, sizeof(cur));
    }
    double ans = 0.0;
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < n; y++)
        {
            ans += cur[x][y];
        }
    }
    return ans;
}
