#include <stdio.h>
#include <stdlib.h>

int finalValueAfterOperations(char** operations, int n)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (operations[i][1] == '+')
        {
            ans++;
        }
        else
        {
            ans--;
        }
    }
    return ans;
}
