#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* p1,const void* p2)
{
    return (int)(strlen(*((char**)p1))-strlen(*((char**)p2)));
}

char** twoEditWords(char** queries, int n, char** dictionary, int dictionarySize, int* returnSize)
{
    int i,j,sz,k,cnt,m;
    int len[dictionarySize];
    char** ret=(char**)malloc(sizeof(char*)*n);
    qsort(dictionary,dictionarySize,sizeof(char*),cmp);
    for(i=0;i<dictionarySize;i++)
    {
        len[i]=(int)strlen(dictionary[i]);
    }
    for(i=0,k=0;i<n;i++)
    {
        sz=(int)strlen(queries[i]);
        for(j=0;j<dictionarySize;j++)
        {
            if(len[j]<sz)
            {
                continue;
            }
            if(len[j]>sz)
            {
                break;
            }
            cnt=0;
            for(m=0;m<sz;m++)
            {
                if(queries[i][m]!=dictionary[j][m])
                {
                    cnt++;
                    if(cnt>2)
                    {
                        break;
                    }
                }
            }
            if(cnt<=2)
            {
                ret[k]=strdup(queries[i]);
                k++;
                break;
            }
        }
    }
    *returnSize=k;
    return ret;
}
