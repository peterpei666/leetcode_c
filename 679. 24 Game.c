#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

const double dif=1e-6;

int compute(double a,double b,double arr[])
{
    arr[0]=a+b;
    arr[1]=a-b;
    arr[2]=b-a;
    arr[3]=a*b;
    int sz=4;
    if(a>dif)
    {
        arr[sz]=b/a;
        sz++;
    }
    if(b>dif)
    {
        arr[sz]=a/b;
        sz++;
    }
    return sz;
}

bool dfs(double nums[],int sz)
{
    if(sz==1)
    {
        return nums[0]-24.0<dif&&nums[0]-24.0>-dif;
    }
    for(int i=0;i<sz;i++)
    {
        for(int j=0;j<sz;j++)
        {
            if(i==j)
            {
                continue;
            }
            double next[6];
            int next_sz=0;
            for(int k=0;k<sz;k++)
            {
                if(k!=i&&k!=j)
                {
                    next[next_sz]=nums[k];
                    next_sz++;
                }
            }
            double temp[6];
            int temp_sz=compute(nums[i],nums[j],temp);
            for(int k=0;k<temp_sz;k++)
            {
                next[next_sz]=temp[k];
                if(dfs(next,next_sz+1))
                {
                    return true;
                }
            }
        }
    }
    return false;
}

bool judgePoint24(int* cards, int n)
{
    double nums[4];
    for(int i=0;i<4;i++)
    {
        nums[i]=(double)cards[i];
    }
    return dfs(nums,4);
}
