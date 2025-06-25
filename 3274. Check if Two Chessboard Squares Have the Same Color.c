#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool checkTwoChessboards(char* s1, char* s2)
{
    return !((((s1[0]-'a')&1)^((s1[1]-'0')&1))^(((s2[0]-'a')&1)^((s2[1]-'0')&1)));
}
