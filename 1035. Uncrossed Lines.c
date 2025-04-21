#include <stdio.h>
#include <stdlib.h>
#include <string.h>

inline int maxi(int a,int b)
{
    return a>b?a:b;
}

int maxUncrossedLines(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    int i,j;
    int memory[501][501]={0};
    for(i=1;i<=nums1Size;i++)
    {
        for(j=1;j<=nums2Size;j++)
        {
            if(nums1[i-1]==nums2[j-1])
            {
                memory[i][j]=1+memory[i-1][j-1];
            }
            else
            {
                memory[i][j]=maxi(memory[i-1][j],memory[i][j-1]);
            }
        }
    }
    return memory[nums1Size][nums2Size];
}
