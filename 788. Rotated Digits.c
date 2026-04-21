#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int rotatedDigits(int n)
{
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int x = i;
        bool valid = false;
        while (x)
        {
            int t = x % 10;
            if (t == 3 || t == 4 || t == 7)
            {
                valid = false;
                break;
            }
            if (t == 2 || t == 5 || t == 6 || t == 9)
            {
                valid = true;
            }
            x /= 10;
        }
        if (valid)
        {
            ans++;
        }
    }
    return ans;
}
