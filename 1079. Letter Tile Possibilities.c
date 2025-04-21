#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void place(int* list,int m,int n,int* count)
{
    int i;
    if(m==n)
    {
        for(i=0;i<26;i++)
        {
            if(list[i])
            {
                (*count)++;
            }
        }
    }
    else
    {
        for(i=0;i<26;i++)
        {
            if(list[i])
            {
                list[i]--;
                place(list,m+1,n,count);
                list[i]++;
            }
        }
    }
}

int numTilePossibilities(char* tiles)
{
    int i,count=0;
    int len=(int)strlen(tiles);
    int list[26]={0};
    for(i=0;i<len;i++)
    {
        list[tiles[i]-'A']++;
    }
    for(i=1;i<=len;i++)
    {
        place(list,1,i,&count);
    }
    return count;
}
