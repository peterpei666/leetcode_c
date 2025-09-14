#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

unsigned char visited[2501];

inline bool test(int a)
{
    return visited[a>>3]&(1<<(a&7))?true:false;
}

inline void set(int a)
{
    visited[a>>3]|=1<<(a&7);
}

inline void reset(int a)
{
    visited[a>>3]&=~(1<<(a&7));
}

int closestCost(int* baseCosts, int baseCostsSize, int* toppingCosts, int toppingCostsSize, int target)
{
    int i,j,k;
    int ans=-1;
    memset(visited,0,sizeof(visited));
    set(0);
    for(i=0;i<toppingCostsSize;i++)
    {
        for(j=0;j<2;j++)
        {
            for(k=20000;k>=0;k--)
            {
                if(test(k)&&toppingCosts[i]+k<=20000)
                {
                    set(toppingCosts[i]+k);
                }
            }
        }
    }
    for(i=0;i<baseCostsSize;i++)
    {
        for(j=0;j<=20000;j++)
        {
            if(test(j))
            {
                if(ans==-1||abs(baseCosts[i]+j-target)<abs(ans-target))
                {
                    ans=baseCosts[i]+j;
                }
                else if(abs(baseCosts[i]+j-target)==abs(ans-target)&&baseCosts[i]+j<ans)
                {
                    ans=baseCosts[i]+j;
                }
            }
        }
    }
    return ans;
}
