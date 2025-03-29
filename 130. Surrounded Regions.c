#include <stdio.h>
#include <stdlib.h>

int directions[4][2]={-1,0,1,0,0,-1,0,1};

void dfs(char** board,int boardSize,int* boardColSize,int x,int y)
{
    if(x<0||x>=boardSize||y<0||y>=boardColSize[x]||board[x][y]!='O')
    {
        return;
    }
    int d,nx,ny;
    board[x][y]='A';
    for(d=0;d<4;d++)
    {
        nx=x+directions[d][0];
        ny=y+directions[d][1];
        dfs(board,boardSize,boardColSize,nx,ny);
    }
}

void solve(char** board, int boardSize, int* boardColSize)
{
    int i,j;
    for(i=0;i<boardSize;i++)
    {
        if(i==0)
        {
            for(j=0;j<boardColSize[0];j++)
            {
                if(board[i][j]=='O')
                {
                    dfs(board,boardSize,boardColSize,i,j);
                }
            }
        }
        else if(i==boardSize-1)
        {
            for(j=0;j<boardColSize[0];j++)
            {
                if(board[i][j]=='O')
                {
                    dfs(board,boardSize,boardColSize,i,j);
                }
            }
        }
        else
        {
            dfs(board,boardSize,boardColSize,i,0);
            dfs(board,boardSize,boardColSize,i,boardColSize[i]-1);
        }
    }
    for(i=0;i<boardSize;i++)
    {
        for(j=0;j<boardColSize[i];j++)
        {
            switch(board[i][j])
            {
                case 'A':
                    board[i][j]='O';
                    break;
                case 'O':
                    board[i][j]='X';
                    break;
            }
        }
    }
}
