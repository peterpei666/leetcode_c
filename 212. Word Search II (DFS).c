#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int direction[4][2]={-1,0,1,0,0,-1,0,1};

bool dfs(char** board,int boardSize,int* boardColSize,int i,int j,char* word,int index)
{
    if(index==(int)strlen(word))
    {
        return true;
    }
    if(i<0||i>=boardSize||j<0||j>=boardColSize[i]||board[i][j]!=word[index])
    {
        return false;
    }
    int d,row,col;
    bool find=false;
    char temp=board[i][j];
    board[i][j]='*';
    for(d=0;d<4;d++)
    {
        row=i+direction[d][0];
        col=j+direction[d][1];
        if(dfs(board,boardSize,boardColSize,row,col,word,index+1))
        {
            find=true;
            break;
        }
    }
    board[i][j]=temp;
    return find;
}

char** findWords(char** board, int boardSize, int* boardColSize, char** words, int wordsSize, int* returnSize)
{
    int i,j,k,count=0,f1=1;
    char** list=(char**)malloc(wordsSize*sizeof(char*));
    for(k=0;k<wordsSize;k++)
    {
        f1=1;
        for(i=0;i<boardSize&&f1;i++)
        {
            for(j=0;j<boardColSize[i];j++)
            {
                if(board[i][j]==words[k][0]&&dfs(board,boardSize,boardColSize,i,j,words[k],0))
                {
                    list[count]=words[k];
                    count++;
                    f1=0;
                    break;
                }
            }
        }
    }
    *returnSize=count;
    return list;
}
