#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

static inline int max(int a, int b)
{
    return a > b ? a : b;
}

static inline int min(int a, int b)
{
    return a < b ? a : b;
}

int strongPasswordChecker(char* password)
{
    int n = (int)strlen(password);
    int miss = 3;
    bool f1 = true, f2 = true, f3 = true;
    for (int i = 0; i < n; i++)
    {
        if (f1 && password[i] >= 'a' && password[i] <= 'z')
        {
            f1 = false;
            miss--;
        }
        if (f2 && password[i] >= 'A' && password[i] <= 'Z')
        {
            f2 = false;
            miss--;
        }
        if (f3 && password[i] >= '0' && password[i] <= '9')
        {
            f3 = false;
            miss--;
        }
    }
    int change = 0;
    int one = 0,two = 0;
    int p = 2;
    while (p < n)
    {
        if (password[p] == password[p - 1] && password[p] == password[p - 2])
        {
            int len = 2;
            while (p < n && password[p] == password[p - 1])
            {
                len++;
                p++;
            }
            change += len / 3;
            if (len % 3 == 0)
            {
                one++;
            }
            else if (len % 3 == 1)
            {
                two++;
            }
        }
        else
        {
            p++;
        }
    }
    if (n < 6)
    {
        return max(miss, 6 - n);
    }
    else if (n <= 20)
    {
        return max(miss, change);
    }
    else
    {
        int del = n - 20;
        change -= min(del, one);
        change -= min(max(del - one, 0), two * 2) / 2;
        change -= max(del - one - 2 * two, 0) / 3;
        return del + max(miss, change);
    }
}
