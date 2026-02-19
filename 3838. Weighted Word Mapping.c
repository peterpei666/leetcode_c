#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* mapWordWeights(char** words, int n, int* weights, int weightsSize)
{
    char* ans = (char*)malloc((n + 1) * sizeof(char));
    ans[n] = '\0';
    for (int i = 0; i < n; i++)
    {
        int val = 0;
        int sz = (int)strlen(words[i]);
        for (int j = 0; j < sz; j++)
        {
            val += weights[words[i][j] - 'a'];
        }
        ans[i] = 'z' - val % 26;
    }
    return ans;
}
