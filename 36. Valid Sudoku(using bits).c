#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isValidSudoku(char** board, int boardSize, int* boardColSize)
{
    int i,j,m,n,check;
    int arr1[3]={-1,0,1};
    int arr2[3]={-1,0,1};
    for(i=0;i<9;i++)
    {
        check=0;
        for(j=0;j<9;j++)
        {
            if(board[i][j]=='.')
            {
                continue;
            }
            if(check&1<<(board[i][j]-'1'))
            {
                return false;
            }
            else
            {
                check+=1<<(board[i][j]-'1');
            }
        }
    }
    for(j=0;j<9;j++)
    {
        check=0;
        for(i=0;i<9;i++)
        {
            if(board[i][j]=='.')
            {
                continue;
            }
            if(check&1<<(board[i][j]-'1'))
            {
                return false;
            }
            else
            {
                check+=1<<(board[i][j]-'1');
            }
        }
    }
    for(i=1;i<8;i+=3)
    {
        for(j=1;j<8;j+=3)
        {
            check=0;
            for(m=0;m<3;m++)
            {
                for(n=0;n<3;n++)
                {
                    if(board[i+arr1[m]][j+arr2[n]]!='.'&&check&1<<(board[i+arr1[m]][j+arr2[n]]-'1'))
                    {
                        return false;
                    }
                    else if(board[i+arr1[m]][j+arr2[n]]!='.')
                    {
                        check+=1<<(board[i+arr1[m]][j+arr2[n]]-'1');
                    }
                }
            }
        }
    }
    return true;
}

