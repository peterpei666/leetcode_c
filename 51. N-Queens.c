#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool valid(char board[9][9],int r,int c,int n)
{
    for(int i=0;i<r;i++)
    {
        if(board[i][c]=='Q')
        {
            return false;
        }
    }
    for(int i=r,j=c;i>=0&&j>=0;i--,j--)
    {
        if(board[i][j]=='Q')
        {
            return false;
        }
    }
    for(int i=r,j=c;i>=0&&j<n;i--,j++)
    {
        if(board[i][j]=='Q')
        {
            return false;
        }
    }
    return true;
}

void construct(char**** ans,char board[9][9],int r,int n,int* sz,int* capacity)
{
    if(r==n)
    {
        if(*sz==*capacity)
        {
            (*capacity)*=2;
            *ans=(char***)realloc(*ans,sizeof(char**)*(*capacity));
        }
        (*ans)[*sz]=(char**)malloc(sizeof(char*)*n);
        for(int i=0;i<n;i++)
        {
            (*ans)[*sz][i]=(char*)malloc(n+1);
            memcpy((*ans)[*sz][i],board[i],n);
            (*ans)[*sz][i][n]='\0';
        }
        (*sz)++;
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(valid(board,r,i,n))
        {
            board[r][i]='Q';
            construct(ans,board,r+1,n,sz,capacity);
            board[r][i]='.';
        }
    }
}

char*** solveNQueens(int n, int* returnSize, int** returnColumnSizes)
{
    int sz=0,capacity=20;
    char board[9][9];
    memset(board,'.',sizeof(board));
    char*** ans=(char***)malloc(sizeof(char**)*capacity);
    construct(&ans,board,0,n,&sz,&capacity);
    *returnSize=sz;
    *returnColumnSizes=(int*)malloc(sizeof(int)*sz);
    for(int i=0;i<sz;i++)
    {
        (*returnColumnSizes)[i]=n;
    }
    return ans;
}
