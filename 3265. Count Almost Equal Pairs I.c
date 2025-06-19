#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool valid(int a,int b)
{
    if(a==b)
    {
        return true;
    }
    int list1[10]={0};
    int list2[10]={0};
    int cnt=0,temp1,temp2;
    while(a||b)
    {
        temp1=a%10;
        temp2=b%10;
        if(temp1!=temp2)
        {
            cnt++;
            if(cnt>2)
            {
                return false;
            }
        }
        list1[temp1]++;
        list2[temp2]++;
        a/=10;
        b/=10;
    }
    if(cnt==2&&memcmp(list1+1,list2+1,sizeof(int)*9)==0)
    {
        return true;
    }
    return false;
}

int countPairs(int* nums, int n)
{
    int i,j,cnt=0;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(valid(nums[i],nums[j]))
            {
                cnt++;
            }
        }
    }
    return cnt;
}
