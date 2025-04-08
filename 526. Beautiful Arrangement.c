#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void count(bool* visited,int* sum,int current,int n)
{
    int i;
    if(current==n)
    {
        for(i=0;i<n;i++)
        {
            if(visited[i]==false&&n%(i+1)==0)
            {
                (*sum)++;
                break;
            }
        }
        return;
    }
    for(i=0;i<n;i++)
    {
        if(visited[i]==false&&(current%(i+1)==0||(i+1)%current==0))
        {
            visited[i]=true;
            count(visited,sum,current+1,n);
            visited[i]=false;
        }
    }
}

int countArrangement(int n)
{
    int sum=0;
    bool* visited=(bool*)malloc(sizeof(bool)*n);
    memset(visited,false,n);
    count(visited,&sum,1,n);
    free(visited);
    return sum;
}
