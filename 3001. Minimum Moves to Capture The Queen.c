#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

inline bool between(int a,int b,int m)
{
    return (a<m&&b>m)||(b<m&&a>m);
}

int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f)
{
    if(abs(e-c)==abs(f-d))
    {
        if(abs(c-a)!=abs(d-b)||between(e,c,a)==false||between(f,d,b)==false)
        {
            return 1;
        }
    }
    if(a==e&&(a!=c||between(b,f,d)==false))
    {
        return 1;
    }
    if(b==f&&(b!=d||between(a,e,c)==false))
    {
        return 1;
    }
    return 2;
}
