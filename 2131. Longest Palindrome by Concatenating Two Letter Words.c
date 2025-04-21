#include <stdio.h>
#include <stdlib.h>
#include <string.h>

inline int mini(int a,int b)
{
    return a>b?b:a;
}

int longestPalindrome(char** words, int wordsSize)
{
    int i,j,len=0,f=1;
    int list[26][26]={0};
    memset(list,0,26*26*sizeof(int));
    for(i=0;i<wordsSize;i++)
    {
        list[words[i][0]-'a'][words[i][1]-'a']++;
    }
    for(i=0;i<26;i++)
    {
        if(f&&list[i][i]%2)
        {
            len+=list[i][i]*2;
            f=0;
        }
        else
        {
            len+=list[i][i]/2*4;
        }
    }
    for(i=0;i<26;i++)
    {
        for(j=i+1;j<26;j++)
        {
            len+=mini(list[i][j],list[j][i])*4;
        }
    }
    return len;
}
