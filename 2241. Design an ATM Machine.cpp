#include <iostream>
#include <algorithm>
using namespace std;

class ATM
{
public:
    vector<int> list;
    
    ATM()
    {
        list=vector<int>(5,0);
    }
    
    void deposit(const vector<int>& banknotesCount)
    {
        for(int i=0;i<5;i++)
        {
            list[i]+=banknotesCount[i];
        }
    }
    
    vector<int> withdraw(int amount)
    {
        vector<int> ret(5);
        ret[4]=min(amount/500,list[4]);
        amount-=500*ret[4];
        ret[3]=min(amount/200,list[3]);
        amount-=200*ret[3];
        ret[2]=min(amount/100,list[2]);
        amount-=100*ret[2];
        ret[1]=min(amount/50,list[1]);
        amount-=50*ret[1];
        ret[0]=min(amount/20,list[0]);
        amount-=20*ret[0];
        if(amount)
        {
            return {-1};
        }
        else
        {
            for(int i=0;i<5;i++)
            {
                list[i]-=ret[i];
            }
            return ret;
        }
    }
};
