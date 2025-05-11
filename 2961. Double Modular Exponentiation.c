#include <stdio.h>
#include <stdlib.h>

int mod2[4]={6,2,4,8};
int mod3[4]={1,3,9,7};
int mod7[4]={1,7,9,3};
int mod8[4]={6,8,4,2};
int mod4[2]={6,4};
int mod9[2]={1,9};

int mod(int base,int exp)
{
    switch(base)
    {
        case 2:
            return mod2[exp%4];
        case 3:
            return mod3[exp%4];
        case 4:
            return mod4[exp%2];
        case 7:
            return mod7[exp%4];
        case 8:
            return mod8[exp%4];
        case 9:
            return mod9[exp%2];
        default:
            return base;
    }
}

int* getGoodIndices(int** variables, int variablesSize, int* variablesColSize, int target, int* returnSize)
{
    int i,j,temp,t,x,sz=10,cnt=0;
    int* ret=(int*)malloc(sizeof(int)*sz);
    for(i=0;i<variablesSize;i++)
    {
        if(variables[i][3]<=target)
        {
            continue;
        }
        temp=mod(variables[i][0]%10,variables[i][1]);
        x=1;
        t=variables[i][2];
        for(j=0;j<t;j++)
        {
            x=temp*x%variables[i][3];
        }
        if(x==target)
        {
            if(cnt>=sz)
            {
                sz*=2;
                ret=(int*)realloc(ret,sizeof(int)*sz);
            }
            ret[cnt]=i;
            cnt++;
        }
    }
    *returnSize=cnt;
    return ret;
}
