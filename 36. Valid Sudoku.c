#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isValidSudoku(char** board, int boardSize, int* boardColSize)
{
    int i,j,m,n;
    int arr1[3]={-1,0,1};
    int arr2[3]={-1,0,1};
    for(i=0;i<9;i++)
    {
        bool* check=(bool*)calloc(9,sizeof(bool));
        for(j=0;j<9;j++)
        {
            if(board[i][j]=='.')
            {
                continue;
            }
            if(check[board[i][j]-'1']==true)
            {
                return false;
            }
            else
            {
                check[board[i][j]-'1']=true;
            }
        }
        free(check);
    }
    for(j=0;j<9;j++)
    {
        bool* check=(bool*)calloc(9,sizeof(bool));
        for(i=0;i<9;i++)
        {
            if(board[i][j]=='.')
            {
                continue;
            }
            if(check[board[i][j]-'1']==true)
            {
                return false;
            }
            else
            {
                check[board[i][j]-'1']=true;
            }
        }
        free(check);
    }
    for(i=1;i<8;i+=3)
    {
        for(j=1;j<8;j+=3)
        {
            bool* check=(bool*)calloc(9,sizeof(bool));
            for(m=0;m<3;m++)
            {
                for(n=0;n<3;n++)
                {
                    if(board[i+arr1[m]][j+arr2[n]]!='.'&&check[board[i+arr1[m]][j+arr2[n]]-'1']==true)
                    {
                        return false;
                    }
                    else if(board[i+arr1[m]][j+arr2[n]]!='.')
                    {
                        check[board[i+arr1[m]][j+arr2[n]]-'1']=true;
                    }
                }
            }
            free(check);
        }
    }
    return true;
}

