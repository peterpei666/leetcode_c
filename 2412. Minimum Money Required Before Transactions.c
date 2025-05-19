#include <stdio.h>
#include <stdlib.h>

inline long long maxi(long long a,long long b)
{
    return a>b?a:b;
}

long long minimumMoney(int** transactions, int transactionsSize, int* transactionsColSize)
{
    int i;
    long long max_cost=0;
    long long total_loss=0;
    for(i=0;i<transactionsSize;i++)
    {
        if(transactions[i][1]<transactions[i][0])
        {
            total_loss+=transactions[i][0]-transactions[i][1];
            max_cost=maxi(max_cost,(long long)transactions[i][1]);
        }
        else
        {
            max_cost=maxi(max_cost,(long long)transactions[i][0]);
        }
    }
    return total_loss+max_cost;
}
