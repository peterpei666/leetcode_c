#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static inline int max(int a,int b)
{
    return a>b?a:b;
}

int cmp1(const void* p1,const void* p2)
{
    int* a=*(int**)p1;
    int* b=*(int**)p2;
    return a[0]-b[0];
}

int cmp2(const void* p1,const void* p2)
{
    int* a=*(int**)p1;
    int* b=*(int**)p2;
    return a[1]-b[1];
}

bool checkValidCuts(int n, int** rectangles, int r, int* rectanglesColSize)
{
    qsort(rectangles,r,sizeof(int*),cmp1);
    int cnt=0;
    int cur=rectangles[0][2];
    for(int i=1;i<r;i++)
    {
        if(cur<=rectangles[i][0])
        {
            cnt++;
            if(cnt>=2)
            {
                return true;
            }
        }
        cur=max(cur,rectangles[i][2]);
    }
    qsort(rectangles,r,sizeof(int*),cmp2);
    cnt=0;
    cur=rectangles[0][3];
    for(int i=1;i<r;i++)
    {
        if(cur<=rectangles[i][1])
        {
            cnt++;
            if(cnt>=2)
            {
                return true;
            }
        }
        cur=max(cur,rectangles[i][3]);
    }
    return false;
}
