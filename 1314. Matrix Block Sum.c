#include <stdio.h>
#include <stdlib.h>

void insert(int** mat,int matSize,int* matColSize,int** board)
{
    int i,j;
    board[0][0]=mat[0][0];
    for(i=1;i<matColSize[0];i++)
    {
        board[0][i]=mat[0][i]+board[0][i-1];
    }
    for(i=1;i<matSize;i++)
    {
        board[i][0]=mat[i][0]+board[i-1][0];
    }
    for(i=1;i<matSize;i++)
    {
        for(j=1;j<matColSize[i];j++)
        {
            board[i][j]=board[i-1][j]+board[i][j-1]-board[i-1][j-1]+mat[i][j];
        }
    }
}

int part(int matSize,int* matColSize,int** board,int x,int y)
{
    if(x<0||y<0)
    {
        return 0;
    }
    if(x>=matSize)
    {
        x=matSize-1;
    }
    if(y>=matColSize[x])
    {
        y=matColSize[x]-1;
    }
    return board[x][y];
}

int** matrixBlockSum(int** mat, int matSize, int* matColSize, int k, int* returnSize, int** returnColumnSizes)
{
    int i,j;
    int** board=(int**)malloc(sizeof(int*)*matSize);
    int** ans=(int**)malloc(sizeof(int*)*matSize);
    *returnSize=matSize;
    *returnColumnSizes=(int*)malloc(sizeof(int)*matSize);
    for(i=0;i<matSize;i++)
    {
        board[i]=(int*)malloc(sizeof(int)*matColSize[i]);
        ans[i]=(int*)malloc(sizeof(int)*matColSize[i]);
        (*returnColumnSizes)[i]=matColSize[i];
    }
    insert(mat,matSize,matColSize,board);
    for(i=0;i<matSize;i++)
    {
        for(j=0;j<matColSize[i];j++)
        {
            ans[i][j]=part(matSize,matColSize,board,i+k,j+k)-part(matSize,matColSize,board,i+k,j-k-1)-part(matSize,matColSize,board,i-k-1,j+k)+part(matSize,matColSize,board,i-k-1,j-k-1);
        }
    }
    for(i=0;i<matSize;i++)
    {
        free(board[i]);
    }
    free(board);
    return ans;
}

