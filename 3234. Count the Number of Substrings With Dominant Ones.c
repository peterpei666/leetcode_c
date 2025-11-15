#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static inline int min(int a, int b)
{
    return a < b ? a : b;
}

int numberOfSubstrings(char* s)
{
    int n = (int)strlen(s);
    int pre[40001];
    pre[0] = -1;
    for (int i = 0; i < n; i++)
    {
        if (i == 0 || (i > 0 && s[i - 1] == '0'))
        {
            pre[i + 1] = i;
        }
        else
        {
            pre[i + 1] = pre[i];
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int cnt = (s[i - 1] == '0');
        int j = i;
        while (j > 0 && cnt * cnt <= n)
        {
            int cnt1 = i - pre[j] - cnt;
            if (cnt * cnt <= cnt1)
            {
                ans += min(j - pre[j], cnt1 - cnt * cnt + 1);
            }
            j = pre[j];
            cnt++;
        }
    }
    return ans;
}
