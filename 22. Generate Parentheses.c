#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dfs(char temp[],int idx,int l,int r,char*** ans,int* sz,int* capacity)
{
    if(l==0&&r==0)
    {
        if(*sz==*capacity)
        {
            (*capacity)*=2;
            *ans=(char**)realloc(*ans,sizeof(char*)*(*capacity));
        }
        (*ans)[*sz]=strdup(temp);
        (*sz)++;
        return;
    }
    if(l)
    {
        temp[idx]='(';
        dfs(temp,idx+1,l-1,r+1,ans,sz,capacity);
    }
    if(r)
    {
        temp[idx]=')';
        dfs(temp,idx+1,l,r-1,ans,sz,capacity);
    }
    temp[idx]='\0';
}

char** generateParenthesis(int n, int* returnSize)
{
    char temp[17];
    memset(temp,'\0',17);
    char** ans=(char**)malloc(sizeof(char*)*16);
    int sz=0,capacity=16;
    dfs(temp,0,n,0,&ans,&sz,&capacity);
    *returnSize=sz;
    return ans;
}
