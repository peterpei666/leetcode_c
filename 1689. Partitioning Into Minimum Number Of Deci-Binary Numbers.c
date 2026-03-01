#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int minPartitions(char* num)
{
    int n = (int)strlen(num);
    char ans = '0';
    for (int i = 0; i < n; i++)
    {
        if (num[i] > ans)
        {
            ans = num[i];
        }
    }
    return ans - '0';
}
