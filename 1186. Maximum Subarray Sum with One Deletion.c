#include <stdio.h>
#include <stdlib.h>

inline int max(int a,int b)
{
    return a>b?a:b;
}

int maximumSum(int* arr, int n)
{
    int i,cur,temp,ans;
    int prefix[n];
    int suffix[n];
    cur=arr[0];
    prefix[0]=cur;
    temp=cur;
    for(i=1;i<n;i++)
    {
        cur=max(arr[i],cur+arr[i]);
        temp=max(temp,cur);
        prefix[i]=cur;
    }
    cur=arr[n-1];
    suffix[n-1]=cur;
    temp=max(temp,cur);
    for(i=n-2;i>=0;i--)
    {
        cur=max(arr[i],cur+arr[i]);
        temp=max(temp,cur);
        suffix[i]=cur;
    }
    ans=temp;
    for(i=1;i<n-1;i++)
    {
        ans=max(ans,prefix[i-1]+suffix[i+1]);
    }
    return ans;
}
