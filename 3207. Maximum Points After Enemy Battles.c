#include <stdio.h>
#include <stdlib.h>

int cmp(const void* p1,const void* p2)
{
    return *(int*)p1-*(int*)p2;
}

long long maximumPoints(int* enemyEnergies, int n, int currentEnergy)
{
    qsort(enemyEnergies,n,sizeof(int),cmp);
    if(enemyEnergies[0]>currentEnergy)
    {
        return 0;
    }
    n--;
    long long ans=0;
    while(n>=0)
    {
        if(enemyEnergies[0]<=currentEnergy)
        {
            ans+=currentEnergy/enemyEnergies[0];
            currentEnergy%=enemyEnergies[0];
        }
        else
        {
            currentEnergy+=enemyEnergies[n];
            n--;
        }
    }
    return ans;
}
