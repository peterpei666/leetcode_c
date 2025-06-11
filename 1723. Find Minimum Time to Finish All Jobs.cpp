#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

class Solution
{
private:
    bool valid(int time,int k,int n,vector<int>& jobs)
    {
        vector<int> workers(k,0);
        return backtrack(0,n,k,workers,jobs,time);
    }
    
    bool backtrack(int i,int n,int k,vector<int>& workers,vector<int>& jobs,int time)
    {
        if(i==n)
        {
            return true;
        }
        set<int> seen;
        for(int j=0;j<k;j++)
        {
            if(workers[j]+jobs[i]<=time&&seen.count(workers[j])==false)
            {
                workers[j]+=jobs[i];
                if(backtrack(i+1,n,k,workers,jobs,time))
                {
                    return true;
                }
                workers[j]-=jobs[i];
                seen.insert(workers[j]);
            }
            if(workers[j]==0)
            {
                break;
            }
        }
        return false;
    }
    
public:
    int minimumTimeRequired(vector<int>& jobs, int k)
    {
        sort(jobs.begin(),jobs.end(),greater<int>());
        int l=0,r=0;
        int n=(int)jobs.size();
        for(int i:jobs)
        {
            l=max(l,i);
            r+=i;
        }
        while(l<r)
        {
            int mid=(l+r)/2;
            if(valid(mid,k,n,jobs))
            {
                r=mid;
            }
            else
            {
                l=mid+1;
            }
        }
        return l;
    }
};
