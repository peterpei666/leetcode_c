#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    int i,x,y;
    int* list=(int*)malloc(sizeof(int)*(m+n));
    for(i=0,x=0,y=0;i<m+n;i++)
    {
        if(x>=m)
        {
            list[i]=nums2[y];
            y++;
        }
        else if(y>=n)
        {
            list[i]=nums1[x];
            x++;
        }
        else
        {
            if(nums1[x]<nums2[y])
            {
                list[i]=nums1[x];
                x++;
            }
            else
            {
                list[i]=nums2[y];
                y++;
            }
        }
    }
    memcpy(nums1,list,sizeof(int)*(m+n));
    free(list);
}
