#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convert(char* s,int numRows)
{
    if(numRows==1)
    {
        return s;
    }
    int len=(int)strlen(s),i,j=0,k1,k2;
    char* ans=(char*)malloc((len+1)*sizeof(char));
    ans[len]='\0';
    for(i=0;i<numRows;i++)
    {
        if(i==0)
        {
            k1=0;
            while(k1<len)
            {
                ans[j]=*(s+k1);
                k1+=2*numRows-2;
                j++;
            }
        }
        else if(i==numRows-1)
        {
            k1=numRows-1;
            while(k1<len)
            {
                ans[j]=*(s+k1);
                k1+=2*numRows-2;
                j++;
            }
        }
        else
        {
            k1=i;
            k2=2*numRows-2-i;
            while(k1<len||k2<len)
            {
                if(k1<k2)
                {
                    if(k1<len)
                    {
                        ans[j]=*(s+k1);
                        k1+=2*numRows-2;
                        j++;
                    }
                }
                else
                {
                    if(k2<len)
                    {
                        ans[j]=*(s+k2);
                        k2+=2*numRows-2;
                        j++;
                    }
                }
            }
        }
    }
    return ans;
}
