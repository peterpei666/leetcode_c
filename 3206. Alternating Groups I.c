#include <stdio.h>
#include <stdlib.h>

int numberOfAlternatingGroups(int* colors, int n)
{
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(colors[(i-2+n)%n]!=colors[(i-1+n)%n]&&colors[i]!=colors[(i-1+n)%n])
        {
            cnt++;
        }
    }
    return cnt;
}
