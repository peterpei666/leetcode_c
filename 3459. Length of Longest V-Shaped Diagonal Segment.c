#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

static inline int max(int a,int b)
{
    return a>b?a:b;
}

static inline bool valid(int x, int y, int m, int n)
{
    return x >= 0 && y >= 0 && x < m && y < n;
}

int dx[4] = {-1, -1, 1, 1};
int dy[4] = {-1, 1, 1, -1};

int dfs(int m, int n, int memo[m][n][4][2], int** grid, int i, int j, int dir, int change)
{
    if (memo[i][j][dir][change]!=-1)
    {
        return memo[i][j][dir][change];
    }
    int cnt = 1;
    int ni = i + dx[dir];
    int nj = j + dy[dir];
    if (valid(ni, nj, m, n) && ((grid[i][j] == 0 && grid[ni][nj] == 2) || (grid[i][j] == 2 && grid[ni][nj] == 0)))
    {
        cnt = max(cnt, 1 + dfs(m, n, memo, grid, ni, nj, dir, change));
    }
    if (change)
    {
        int ndir = (dir + 1 + 4) % 4;
        ni = i + dx[ndir];
        nj = j + dy[ndir];
        if (valid(ni, nj, m, n) && ((grid[i][j] == 0 && grid[ni][nj] == 2) || (grid[i][j] == 2 && grid[ni][nj] == 0)))
        {
            cnt = max(cnt, 1 + dfs(m, n, memo, grid, ni, nj, ndir, change - 1));
        }
    }
    return memo[i][j][dir][change] = cnt;
}

int lenOfVDiagonal(int** grid, int gridSize, int* gridColSize)
{
    int m = gridSize;
    int n = gridColSize[0];
    int memo[m][n][4][2];
    memset(memo, -1, sizeof(memo));
    int dx[4] = {-1, -1, 1, 1};
    int dy[4] = {-1, 1, 1, -1};
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
            {
                ans = max(ans, 1);
                for (int d = 0; d < 4; d++)
                {
                    int ni = i + dx[d];
                    int nj = j + dy[d];
                    if (valid(ni, nj, m, n) && grid[ni][nj] == 2)
                    {
                        ans = max(ans, 1 + dfs(m, n, memo, grid, ni, nj, d, 1));
                    }
                }
            }
        }
    }
    return ans;
}
