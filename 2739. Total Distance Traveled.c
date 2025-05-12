#include <stdio.h>
#include <stdlib.h>

inline int mini(int a,int b)
{
    return a<b?a:b;
}

int distanceTraveled(int mainTank, int additionalTank)
{
    if(mainTank<5)
    {
        return mainTank*10;
    }
    int add=mini(additionalTank,(mainTank-1)/4);
    return (add+mainTank)*10;
}
