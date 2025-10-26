#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    long long* temp;
    int n;
} Bank;


Bank* bankCreate(long long* balance, int balanceSize)
{
    Bank* obj = (Bank*)malloc(sizeof(Bank));
    obj->temp = balance;
    obj->n = balanceSize;
    return obj;
}

bool bankTransfer(Bank* obj, int account1, int account2, long long money)
{
    if (account1 > obj->n || account2 > obj->n || obj->temp[account1 - 1] < money)
    {
        return false;
    }
    obj->temp[account1 - 1] -= money;
    obj->temp[account2 - 1] += money;
    return true;
}

bool bankDeposit(Bank* obj, int account, long long money)
{
    if (account > obj->n)
    {
        return false;
    }
    obj->temp[account - 1] += money;
    return true;
}

bool bankWithdraw(Bank* obj, int account, long long money)
{
    if (account > obj->n || obj->temp[account - 1] < money)
    {
        return false;
    }
    obj->temp[account - 1] -= money;
    return true;
}

void bankFree(Bank* obj)
{
    free(obj->temp);
    free(obj);
}
