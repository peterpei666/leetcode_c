#include <stdio.h>
#include <stdlib.h>

int valid(int* list,int m,int x)
{
    int i;
    for(i=0;i<m;i++)
    {
        if(x==list[i]||abs(m-i)==abs(x-list[i]))
        {
            return 0;
        }
    }
    return 1;
}

void place(int* list,int m,int n,int* count)
{
    int i;
    if(m==n-1)
    {
        for(i=0;i<n;i++)
        {
            if(valid(list,m,i))
            {
                (*count)++;
                return;
            }
        }
    }
    else
    {
        for(i=0;i<n;i++)
        {
            if(valid(list,m,i))
            {
                list[m]=i;
                place(list,m+1,n,count);
            }
        }
    }
}

int totalNQueens(int n)
{
    int* list=(int*)malloc(sizeof(int)*n);
    int count=0;
    place(list,0,n,&count);
    free(list);
    return count;
}
