#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* p1,const void* p2)
{
    return *(int*)p2-*(int*)p1;
}

inline int min(int a,int b)
{
    return a<b?a:b;
}

inline int max(int a,int b)
{
    return a>b?a:b;
}

int minimumDeletions(char* word, int k)
{
    int i,j,temp;
    int list[26]={0};
    int n=(int)strlen(word);
    for(i=0;i<n;i++)
    {
        list[word[i]-'a']++;
    }
    qsort(list,26,sizeof(int),cmp);
    for(i=0;i<26&&list[i]>0;i++)
    {
        temp=0;
        for(j=0;j<i;j++)
        {
            temp+=max(0,list[j]-k-list[i]);
        }
        for(j=i+1;j<26&&list[j]>0;j++)
        {
            temp+=list[j];
        }
        n=min(temp,n);
    }
    return n;
}
