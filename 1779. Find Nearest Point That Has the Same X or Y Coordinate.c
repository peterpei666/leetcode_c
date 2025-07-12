#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int nearestValidPoint(int x, int y, int** points, int n, int* pointsColSize)
{
    int ans=-1;
    int dist=INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(points[i][0]==x||points[i][1]==y)
        {
            if(abs(x-points[i][0])+abs(y-points[i][1])<dist)
            {
                dist=abs(x-points[i][0])+abs(y-points[i][1]);
                ans=i;
            }
        }
    }
    return ans;
}
