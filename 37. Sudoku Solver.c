#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool valid(char** board,int r,int c,char num)
{
    for(int i=0;i<9;i++)
    {
        if(board[r][i]==num||board[i][c]==num)
        {
            return false;
        }
    }
    int x=r-r%3;
    int y=c-c%3;
    for(int i=x;i<x+3;i++)
    {
        for(int j=y;j<y+3;j++)
        {
            if(board[i][j]==num)
            {
                return false;
            }
        }
    }
    return true;
}

bool dfs(char** board,int r,int c)
{
    if(r==9)
    {
        return true;
    }
    if(c==9)
    {
        return dfs(board,r+1,0);
    }
    if(board[r][c]=='.')
    {
        for(char i='1';i<='9';i++)
        {
            if(valid(board,r,c,i))
            {
                board[r][c]=i;
                if(dfs(board,r,c+1))
                {
                    return true;
                }
                board[r][c]='.';
            }
        }
    }
    else
    {
        return dfs(board,r,c+1);
    }
    return false;
}

void solveSudoku(char** board, int boardSize, int* boardColSize)
{
    dfs(board,0,0);
}
