#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

inline int maxi(int a,int b)
{
    return a>b?a:b;
}

int maxScoreSightseeingPair(int* values, int valuesSize)
{
    int i,max=INT_MIN;
    int* list1=(int*)malloc(sizeof(int)*valuesSize);
    int* list2=(int*)malloc(sizeof(int)*valuesSize);
    list1[0]=values[0];
    list2[valuesSize-1]=values[valuesSize-1]-(valuesSize-1);
    for(i=1;i<valuesSize;i++)
    {
        list1[i]=maxi(list1[i-1],values[i]+i);
    }
    for(i=valuesSize-2;i>=0;i--)
    {
        list2[i]=maxi(list2[i+1],values[i]-i);
    }
    for(i=0;i<valuesSize-1;i++)
    {
        max=maxi(list1[i]+list2[i+1],max);
    }
    free(list1);
    free(list2);
    return max;
}
