#include <stdio.h>
#include <stdlib.h>

int countUnguarded(int m, int n, int** guards, int n1, int* guardsColSize, int** walls, int n2, int* wallsColSize)
{
    char mp[100000] = {0};
    for (int i = 0; i < n1; i++)
    {
        mp[guards[i][0] * n + guards[i][1]] = 2;
    }
    for (int i = 0; i < n2; i++)
    {
        mp[walls[i][0] * n + walls[i][1]] = 2;
    }
    for (int i = 0; i < n1; i++)
    {
        int x = guards[i][0], y = guards[i][1];
        for (int i = x - 1; i >= 0 && mp[i * n + y] != 2; i--)
        {
            mp[i * n + y] = 1;
        }
        for (int i = x + 1; i < m && mp[i * n + y] != 2; i++)
        {
            mp[i * n + y] = 1;
        }
        for (int j = y - 1; j >= 0 && mp[x * n + j] != 2; j--)
        {
            mp[x * n + j] = 1;
        }
        for (int j = y + 1; j < n && mp[x * n + j] != 2; j++)
        {
            mp[x * n + j] = 1;
        }
    }
    int ans = 0;
    for (int i = 0; i < m * n; i++)
    {
        if (mp[i] == 0)
        {
            ans++;
        }
    }
    return ans;
}
