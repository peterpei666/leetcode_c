#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int bestClosingTime(char* customers)
{
    int n = (int)strlen(customers);
    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        if (customers[i] == 'Y')
        {
            temp++;
        }
    }
    int ans = temp;
    int t = 0;
    for (int i = 0; i < n; i++)
    {
        if (customers[i] == 'Y')
        {
            temp--;
        }
        else
        {
            temp++;
        }
        if (ans > temp)
        {
            ans = temp;
            t = i + 1;
        }
    }
    return t;
}
