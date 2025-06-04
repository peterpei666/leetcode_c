#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

unsigned char visited[121072];
int cnt;

inline bool test(int a)
{
    return visited[a>>3]&(1<<(a&7))?true:false;
}

inline void set(int a)
{
    if(test(a)==false)
    {
        visited[a>>3]|=1<<(a&7);
        cnt++;
    }
}

bool hasAllCodes(char* s, int k)
{
    int i;
    int temp=0;
    int n=(int)strlen(s);
    memset(visited,0,sizeof(visited));
    cnt=0;
    if(n-k+1<(1<<k))
    {
        return false;
    }
    for(i=0;i<k;i++)
    {
        temp<<=1;
        temp+=s[i]-'0';
    }
    set(temp);
    for(i=k;i<n;i++)
    {
        temp<<=1;
        temp+=s[i]-'0';
        temp&=(1<<k)-1;
        set(temp);
    }
    return cnt==1<<k;
}
