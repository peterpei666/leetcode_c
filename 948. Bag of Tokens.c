#include <stdio.h>
#include <stdlib.h>

inline int maxi(int a,int b)
{
    return a>b?a:b;
}

int cmp(const void* p1,const void* p2)
{
    return *(int*)p1-*(int*)p2;
}

int bagOfTokensScore(int* tokens, int n, int power)
{
    int i=0,j=n-1;
    int m=0,score=0;
    qsort(tokens,n,sizeof(int),cmp);
    while(i<=j)
    {
        while(i<=j&&tokens[i]<=power)
        {
            power-=tokens[i];
            i++;
            score++;
        }
        m=maxi(m,score);
        if(score==0||i>=j)
        {
            break;;
        }
        power+=tokens[j];
        j--;
        score--;
    }
    return m;
}
