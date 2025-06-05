#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

unsigned char visited[8];

bool test(unsigned char a)
{
    return visited[a>>3]&(1<<(a&7))?true:false;
}

void set(unsigned char a)
{
    visited[a>>3]|=1<<(a&7);
}

int* prisonAfterNDays(int* cells, int cellsSize, int n, int* returnSize)
{
    unsigned char temp=0,next;
    unsigned char day[100];
    int i,p=0,idx;
    for(i=1;i<7;i++)
    {
        if(cells[i-1]==cells[i+1])
        {
            temp|=1<<i;
        }
    }
    memset(visited,0,sizeof(visited));
    while(test(temp>>1)==false)
    {
        set(temp>>1);
        day[p]=temp;
        p++;
        next=0;
        for(i=1;i<7;i++)
        {
            if(((temp&(1<<(i-1)))>0)==((temp&(1<<(i+1)))>0))
            {
                next|=1<<i;
            }
        }
        temp=next;
    }
    for(i=0;i<p;i++)
    {
        if(day[i]==temp)
        {
            break;
        }
    }
    if(n<=i)
    {
        idx=n-1;
    }
    else
    {
        n=(n-i)%(p-i);
        if(n==0)
        {
            idx=p-1;
        }
        else
        {
            idx=i+n-1;
        }
    }
    int* ret=(int*)calloc(sizeof(int),8);
    *returnSize=8;
    for(i=1;i<7;i++)
    {
        if(day[idx]&(1<<i))
        {
            ret[i]=1;
        }
    }
    return ret;
}
