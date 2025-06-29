#include <stdio.h>
#include <stdlib.h>
#include <string.h>

inline int min(int a,int b)
{
    return a<b?a:b;
}

inline int max(int a,int b)
{
    return a>b?a:b;
}

inline int lcp(char* a,char* b,int al,int bl)
{
    int i=0,n=min(al,bl);
    while(i<n&&a[i]==b[i]) i++;
    return i;
}

int* longestCommonPrefix(char** words, int n, int* returnSize)
{
    
    int* ret=(int*)malloc(n*sizeof(int));
    if(n==1)
    {
        ret[0]=0;
        *returnSize=1;
        return ret;
    }
    int i;
    int len[n];
    int list[n-1];
    int prefix[n-1];
    int suffix[n-1];
    for(i=0;i<n;i++)
    {
        len[i]=(int)strlen(words[i]);
    }
    for(int i=0;i<n-1;i++)
    {
        list[i]=lcp(words[i],words[i+1],len[i],len[i+1]);
    }
    prefix[0]=list[0];
    for(int i=1;i<n-1;i++)
    {
        prefix[i]=max(prefix[i-1],list[i]);
    }
    suffix[n-2]=list[n-2];
    for(int i=n-3;i>=0;i--)
    {
        suffix[i]=max(suffix[i+1],list[i]);
    }
    for(int i=0;i<n;i++)
    {
        int temp=0;
        if(i!=0&&i!=n-1)
        {
            temp=max(temp,lcp(words[i-1],words[i+1],len[i-1],len[i+1]));
        }
        if(i-2>=0)
        {
            temp=max(temp,prefix[i-2]);
        }
        if(i+1<n-1)
        {
            temp=max(temp,suffix[i+1]);
        }
        ret[i]=temp;
    }
    *returnSize=n;
    return ret;
}
