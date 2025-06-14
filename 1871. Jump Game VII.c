#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

unsigned char visited[12500];

inline bool test(int a)
{
    return visited[a>>3]&(1<<(a&7))?true:false;
}

inline void set(int a)
{
    visited[a>>3]|=1<<(a&7);
}

inline void reset(int a)
{
    visited[a>>3]&=~(1<<(a&7));
}

bool canReach(char* s, int minJump, int maxJump)
{
    int i,n,cnt;
    n=(int)strlen(s);
    cnt=0;
    memset(visited,0,sizeof(visited));
    set(0);
    for(i=1;i<n;i++)
    {
        if(i>maxJump)
        {
            cnt-=test(i-maxJump-1);
        }
        if(i>=minJump)
        {
            cnt+=test(i-minJump);
        }
        if(cnt&&s[i]=='0')
        {
            set(i);
        }
    }
    return test(n-1);
}
