#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countCollisions(char* directions)
{
    int n = (int)strlen(directions);
    int l = 0, r = n - 1;
    while (l < n && directions[l] == 'L')
    {
        l++;
    }
    while (r >= 0 && directions[r] == 'R')
    {
        r--;
    }
    int ans = r - l + 1;
    for (int i = l; i <= r; i++)
    {
        ans -= directions[i] == 'S';
    }
    return ans;
}
