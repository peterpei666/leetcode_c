#include <stdio.h>
#include <stdlib.h>

static inline void swap(char* a,char* b)
{
    char temp=*a;
    *a=*b;
    *b=temp;
}

static inline void reverse(char* t,int n)
{
    int l=0,r=n-1;
    while(l<r)
    {
        swap(&t[l],&t[r]);
        l++;
        r--;
    }
}

char** rotateTheBox(char** boxGrid, int boxGridSize, int* boxGridColSize, int* returnSize, int** returnColumnSizes)
{
    int i,j,k,next;
    int m=boxGridSize;
    int n=boxGridColSize[0];
    char** result=(char**)malloc(sizeof(char*)*n);
    *returnSize=n;
    *returnColumnSizes=(int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
    {
        result[i]=(char*)malloc(sizeof(char)*m);
        (*returnColumnSizes)[i]=m;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            result[i][j]=boxGrid[j][i];
        }
    }
    for(i=0;i<n;i++)
    {
        reverse(result[i],m);
    }
    for(j=0;j<m;j++)
    {
        for(i=n-1;i>=0;i--)
        {
            if(result[i][j]=='.')
            {
                next=-1;
                for(k=i-1;k>=0;k--)
                {
                    if(result[k][j]=='*')
                    {
                        break;
                    }
                    if(result[k][j]=='#')
                    {
                        next=k;
                        break;
                    }
                }
                if(next!=-1)
                {
                    result[next][j]='.';
                    result[i][j]='#';
                }
            }
        }
    }
    return result;
}
