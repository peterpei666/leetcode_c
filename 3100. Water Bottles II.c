#include <stdio.h>
#include <stdlib.h>

int maxBottlesDrunk(int numBottles, int numExchange)
{
    int cnt=numBottles,empty=numBottles;
    while(empty>=numExchange)
    {
        empty-=numExchange;
        cnt++;
        empty++;
        numExchange++;
    }
    return cnt;
}
