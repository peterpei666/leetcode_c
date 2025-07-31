#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** fullJustify(char** words, int n, int maxWidth, int* returnSize)
{
    int wlen[n];
    for(int i=0;i<n;i++)
    {
        wlen[i]=(int)strlen(words[i]);
    }
    int sz=0,capacity=20;
    char** ans=(char**)malloc(sizeof(char*)*capacity);
    int i=0;
    while(i<n)
    {
        int j=i;
        int len=0,chrs=0;
        while(j<n&&len+wlen[j]+j-i<=maxWidth)
        {
            len+=wlen[j];
            chrs+=wlen[j];
            j++;
        }
        int space=maxWidth-chrs;
        int gap=j-i-1;
        char* line=(char*)malloc(maxWidth+1);
        memset(line,' ',maxWidth);
        line[maxWidth]='\0';
        int m=0;
        if(j==n||gap==0)
        {
            for(int k=i;k<j;k++)
            {
                memcpy(line+m,words[k],wlen[k]);
                m+=wlen[k]+1;
            }
        }
        else
        {
            int each=space/gap;
            int extra=space%gap;
            for(int k=i;k<j;k++)
            {
                memcpy(line+m,words[k],wlen[k]);
                m+=wlen[k];
                if(k!=j-1)
                {
                    m+=each+(extra>0?1:0);
                    extra--;
                }
            }
        }
        if(sz==capacity)
        {
            capacity*=2;
            ans=(char**)realloc(ans,sizeof(char*)*capacity);
        }
        ans[sz]=line;
        sz++;
        i=j;
    }
    *returnSize=sz;
    return ans;
}
