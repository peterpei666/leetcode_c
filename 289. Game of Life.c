#include <stdio.h>
#include <stdlib.h>

int m,n;

int count(int x,int y,int** board)
{
    int k=0;
    for(int i=-1;i<=1;i++)
    {
        for(int j=-1;j<=1;j++)
        {
            if(x+i>=0&&x+i<m&&y+j>=0&&y+j<n&&board[x+i][y+j]%2)
            {
                k++;
            }
        }
    }
    return k-board[x][y];
}

void gameOfLife(int** board, int boardSize, int* boardColSize)
{
    m=boardSize;
    n=boardColSize[0];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            int c=count(i,j,board);
            if(board[i][j])
            {
                if(c==2||c==3)
                {
                    board[i][j]+=2;
                }
            }
            else
            {
                if(c==3)
                {
                    board[i][j]+=2;
                }
            }
        }
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            board[i][j]/=2;
        }
    }
}
