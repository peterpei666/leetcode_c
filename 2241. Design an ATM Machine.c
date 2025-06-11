#include <stdio.h>
#include <stdlib.h>
#include <string.h>

inline int min(int a,int b)
{
    return a<b?a:b;
}

typedef struct
{
    int list[5];
} ATM;


ATM* aTMCreate(void)
{
    ATM* obj=(ATM*)malloc(sizeof(ATM));
    memset(obj->list,0,sizeof(obj->list));
    return obj;
}

void aTMDeposit(ATM* obj, int* banknotesCount, int banknotesCountSize)
{
    int i;
    for(i=0;i<5;i++)
    {
        obj->list[i]+=banknotesCount[i];
    }
}

int* aTMWithdraw(ATM* obj, int amount, int* retSize)
{
    int* ret=(int*)malloc(sizeof(int)*5);
    ret[4]=min(amount/500,obj->list[4]);
    amount-=500*ret[4];
    ret[3]=min(amount/200,obj->list[3]);
    amount-=200*ret[3];
    ret[2]=min(amount/100,obj->list[2]);
    amount-=100*ret[2];
    ret[1]=min(amount/50,obj->list[1]);
    amount-=50*ret[1];
    ret[0]=min(amount/20,obj->list[0]);
    amount-=20*ret[0];
    if(amount)
    {
        ret[0]=-1;
        *retSize=1;
        return ret;
    }
    else
    {
        for(int i=0;i<5;i++)
        {
            obj->list[i]-=ret[i];
        }
        *retSize=5;
        return ret;
    }
}

void aTMFree(ATM* obj)
{
    free(obj);
}
