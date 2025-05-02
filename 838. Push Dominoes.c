#include <stdio.h>
#include <stdlib.h>
#include <string.h>

inline int maxi(int a,int b)
{
    return a>b?a:b;
}

char* pushDominoes(char* dominoes)
{
    int i,n,f=0;
    n=(int)strlen(dominoes);
    int* force=(int*)calloc(sizeof(int),n);
    for(int i=0;i<n;i++)
    {
        if(dominoes[i]=='R')
        {
            f=n;
        }
        else if(dominoes[i]=='L')
        {
            f=0;
        }
        else
        {
            f=maxi(f-1,0);
        }
        force[i]+=f;
    }
    f=0;
    for(int i=n-1;i>=0;i--)
    {
        if(dominoes[i]=='L')
        {
            f=n;
        }
        else if(dominoes[i]=='R')
        {
            f=0;
        }
        else
        {
            f=maxi(f-1,0);
        }
        force[i]-=f;
    }
    for(int i=0;i<n;i++)
    {
        if(force[i]==0)
        {
            dominoes[i]='.';
        }
        else if(force[i]>0)
        {
            dominoes[i]='R';
        }
        else
        {
            dominoes[i]='L';
        }
    }
    return dominoes;
}

