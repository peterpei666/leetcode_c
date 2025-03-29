#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int parent[26];

int find(int x)
{
    if(parent[x]!=x)
    {
        parent[x]=find(parent[x]);
    }
    return parent[x];
}

void initialize(void)
{
    int i;
    for(i=0;i<26;i++)
    {
        parent[i]=i;
    }
}

void merge(int a,int b)
{
    int root1=find(a);
    int root2=find(b);
    if(root1<root2)
    {
        parent[root2]=root1;
    }
    else
    {
        parent[root1]=root2;
    }
}

bool equationsPossible(char** equations, int equationsSize)
{
    int i,root1,root2;
    initialize();
    for(i=0;i<equationsSize;i++)
    {
        if(equations[i][1]=='=')
        {
            merge(equations[i][0]-'a',equations[i][3]-'a');
        }
        else
        {
            root1=find(equations[i][0]-'a');
            root2=find(equations[i][3]-'a');
            if(root1==root2)
            {
                return false;
            }
        }
    }
    for(i=0;i<equationsSize;i++)
    {
        if(equations[i][1]=='!')
        {
            root1=find(equations[i][0]-'a');
            root2=find(equations[i][3]-'a');
            if(root1==root2)
            {
                return false;
            }
        }
    }
    return true;
}
