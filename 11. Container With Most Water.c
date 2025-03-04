#include <stdio.h>
#include <stdlib.h>

int min(int a,int b)
{
    return a>b?b:a;
}

int max(int a,int b)
{
    return a>b?a:b;
}

int maxArea(int* height,int heightSize)
{
    int area=0,temp=0;
    int* left=height;
    int* right=height+heightSize-1;
    while(right>=left)
    {
        temp=min(*left,*right)*(int)(right-left);
        area=max(area,temp);
        if(*left<*right)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    return area;
}
