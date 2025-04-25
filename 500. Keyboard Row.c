#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char row1[11]="qwertyuiop";
char row2[10]="asdfghjkl";
char row3[8]="zxcvbnm";

int row(char c)
{
    int i;
    for(i=0;i<10;i++)
    {
        if(c==row1[i])
        {
            return 1;
        }
    }
    for(i=0;i<9;i++)
    {
        if(c==row2[i])
        {
            return 2;
        }
    }
    return 3;
}

char** findWords(char** words, int wordsSize, int* returnSize)
{
    int i,j,count=0,f,t,len;
    char c;
    char** ret=(char**)malloc(sizeof(char*)*wordsSize);
    for(i=0;i<wordsSize;i++)
    {
        len=(int)strlen(words[i]);
        f=1;
        t=-1;
        for(j=0;j<len&&f;j++)
        {
            c=words[i][j];
            if(c>='A'&&c<='Z')
            {
                c+='a'-'A';
            }
            if(t==-1)
            {
                t=row(c);
            }
            else
            {
                if(t!=row(c))
                {
                    f=0;
                }
            }
        }
        if(f)
        {
            ret[count]=words[i];
            count++;
        }
    }
    *returnSize=count;
    return ret;
}
