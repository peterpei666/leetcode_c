#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static inline int mini(int a, int b)
{
    return a < b ? a : b;
}

static inline long long minll(long long a, long long b)
{
    return a < b ? a : b;
}

long long minimumCost(char* source, char* target, char* original, int originalSize, char* changed, int changedSize, int* cost, int costSize)
{
    int n = changedSize;
    int m = (int)strlen(source);
    int dis[26][26];
    memset(dis, 0x7f, sizeof(dis));
    for (int i = 0; i < 26; i++)
    {
        dis[i][i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        dis[original[i] - 'a'][changed[i] - 'a'] = mini(dis[original[i] - 'a'][changed[i] - 'a'], cost[i]);
    }
    for (int k = 0; k < 26; k++)
    {
        for (int i = 0; i < 26; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                dis[i][j] = (int)minll(1LL * dis[i][j], 1LL * dis[i][k] + dis[k][j]);
            }
        }
    }
    long long ans = 0;
    for (int i = 0; i < m; i++)
    {
        int x = source[i] - 'a';
        int y = target[i] - 'a';
        if (dis[x][y] == 0x7f7f7f7f)
        {
            return -1;
        }
        ans += dis[x][y];
    }
    return ans;
}
