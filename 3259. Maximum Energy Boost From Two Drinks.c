#include <stdio.h>
#include <stdlib.h>
#include <string.h>

inline long long maxi(long long a,long long b)
{
    return a>b?a:b;
}

long long maxEnergyBoost(int* energyDrinkA, int n, int* energyDrinkB, int energyDrinkBSize)
{
    int i;
    long long A[3];
    long long B[3];
    A[0]=energyDrinkA[0];
    B[0]=energyDrinkB[0];
    A[1]=A[0]+energyDrinkA[1];
    B[1]=B[0]+energyDrinkB[1];
    for(i=2;i<n;i++)
    {
        A[i%3]=maxi(A[(i-1)%3],B[(i-2)%3])+energyDrinkA[i];
        B[i%3]=maxi(A[(i-2)%3],B[(i-1)%3])+energyDrinkB[i];
    }
    return maxi(A[(n-1)%3],B[(n-1)%3]);
}
