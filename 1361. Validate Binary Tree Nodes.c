#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int find(int root[],int x)
{
    if(root[x]==x)
    {
        return x;
    }
    root[x]=find(root,root[x]);
    return root[x];
}

void join(int root[],int a,int b)
{
    int r1=find(root,a);
    int r2=find(root,b);
    if(r1<r2)
    {
        root[r2]=r1;
    }
    else
    {
        root[r1]=r2;
    }
}

bool validateBinaryTreeNodes(int n, int* leftChild, int leftChildSize, int* rightChild, int rightChildSize)
{
    int i,t;
    int parent[n];
    int root[n];
    bool r=false;
    memset(parent,-1,sizeof(parent));
    for(i=0;i<n;i++)
    {
        root[i]=i;
    }
    for(i=0;i<n;i++)
    {
        if(leftChild[i]!=-1)
        {
            if(parent[leftChild[i]]!=-1)
            {
                return false;
            }
            parent[leftChild[i]]=i;
            join(root,i,leftChild[i]);
        }
        if(rightChild[i]!=-1)
        {
            if(parent[rightChild[i]]!=-1)
            {
                return false;
            }
            parent[rightChild[i]]=i;
            join(root,i,rightChild[i]);
        }
    }
    t=find(root,0);
    for(i=0;i<n;i++)
    {
        if(parent[i]==-1)
        {
            if(r)
            {
                return false;
            }
            r=true;
        }
        if(find(root,i)!=t)
        {
            return false;
        }
    }
    return r;
}
