#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maximumCostSubstring(const string& s, const string& chars, vector<int>& vals)
    {
        int list[26];
        for(int i=0;i<26;i++)
        {
            list[i]=i+1;
        }
        for(int i=0;i<chars.size();i++)
        {
            list[chars[i]-'a']=vals[i];
        }
        int ans=0;
        int prev=0;
        int cur=0;
        for(char c:s)
        {
            cur+=list[c-'a'];
            ans=max(ans,cur-prev);
            prev=min(prev,cur);
        }
        return ans;
    }
};
