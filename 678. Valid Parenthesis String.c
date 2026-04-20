#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool checkValidString(char* s)
{
    int n = (int)strlen(s);
    bool dp[2][101] = {0};
    if (s[0] == '(')
    {
        dp[0][1] = true;
    }
    else if (s[0] == ')')
    {
        return false;
    }
    else
    {
        dp[0][0] = true;
        dp[0][1] = true;
    }
    for (int i = 1; i < n; i++)
    {
        int mask = i & 1;
        int prev = mask ^ 1;
        if (s[i] == '(')
        {
            memcpy(&dp[mask][1], &dp[prev][0], sizeof(dp[0]) - 1);
            dp[mask][0] = false;
        }
        else if (s[i] == ')')
        {
            memcpy(&dp[mask][0], &dp[prev][1], sizeof(dp[0]) - 1);
            dp[mask][100] = false;
        }
        else
        {
            memcpy(&dp[mask][0], &dp[prev][0], sizeof(dp[0]));
            dp[mask][1] |= dp[prev][0];
            for (int j = 1; j < 100; j++)
            {
                dp[mask][j - 1] |= dp[prev][j];
                dp[mask][j + 1] |= dp[prev][j];
            }
        }
    }
    return dp[(n - 1) & 1][0];
}
