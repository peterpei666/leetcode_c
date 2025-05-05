#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int parent[26];

int find(int x)
{
    if(x==parent[x])
    {
        return x;
    }
    else
    {
        parent[x]=find(parent[x]);
        return parent[x];
    }
}

void unite(int a,int b)
{
    int root1=find(a);
    int root2=find(b);
    if(root1!=root2)
    {
        if(root1<root2)
        {
            parent[root2]=root1;
        }
        else
        {
            parent[root1]=root2;
        }
    }
}

char* smallestEquivalentString(char* s1, char* s2, char* baseStr)
{
    int i,n;
    for(i=0;i<26;i++)
    {
        parent[i]=i;
    }
    n=(int)strlen(s1);
    for(i=0;i<n;i++)
    {
        unite(s1[i]-'a',s2[i]-'a');
    }
    n=(int)strlen(baseStr);
    for(i=0;i<n;i++)
    {
        baseStr[i]=find(baseStr[i]-'a')+'a';
    }
    return baseStr;
}
