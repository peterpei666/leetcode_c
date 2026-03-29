#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool canBeEqual(char* s1, char* s2)
{
    int n = (int)strlen(s1);
    int cnt[2][26] = {0};
    for (int i = 0; i < n; i++)
    {
        cnt[i & 1][s1[i] - 'a']++;
        cnt[i & 1][s2[i] - 'a']--;
    }
    int target[26] = {0};
    return memcmp(cnt[0], target, sizeof(target)) == 0 && memcmp(cnt[1], target, sizeof(target)) == 0;
}
