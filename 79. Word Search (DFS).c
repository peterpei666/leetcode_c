#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int direction[4][2]={-1,0,1,0,0,-1,0,1};

bool dfs(char** board,int boardSize,int* boardColSize,int i,int j,char* word,int index)
{
    if(index==strlen(word))
    {
        return true;
    }
    if(i<0||i>=boardSize||j<0||j>=boardColSize[i]||board[i][j]!=word[index])
    {
        return false;
    }
    char temp=board[i][j];
    int m,row,col;
    board[i][j]='*';
    for(m=0;m<4;m++)
    {
        row=i+direction[m][0];
        col=j+direction[m][1];
        if(dfs(board,boardSize,boardColSize,row,col,word,index+1))
        {
            return true;
        }
    }
    board[i][j]=temp;
    return false;
}

bool exist(char** board, int boardSize, int* boardColSize, char* word)
{
    int i,j;
    for(i=0;i<boardSize;i++)
    {
        for(j=0;j<boardColSize[i];j++)
        {
            if(board[i][j]==word[0]&&dfs(board,boardSize,boardColSize,i,j,word,0))
            {
                return true;
            }
        }
    }
    return false;
}

