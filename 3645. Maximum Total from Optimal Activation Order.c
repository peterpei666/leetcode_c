#include <stdio.h>
#include <stdlib.h>

int cmp(const void* p1, const void* p2)
{
    return *(int*)p2 - *(int*)p1;
}

long long maxTotal(int* value, int n, int* limit, int limitSize)
{
    int* vec[100001];
    int sz[100001] = {0};
    int capa[100001] = {0};
    for (int i = 0; i < n; i++)
    {
        if (capa[limit[i]] == 0)
        {
            vec[limit[i]] = (int*)malloc(16 * sizeof(int));
            capa[limit[i]] = 16;
        }
        if (sz[limit[i]] == capa[limit[i]])
        {
            capa[limit[i]] *= 2;
            vec[limit[i]] = (int*)realloc(vec[limit[i]], sizeof(int) * capa[limit[i]]);
        }
        vec[limit[i]][sz[limit[i]]] = value[i];
        sz[limit[i]]++;
    }
    long long ans = 0;
    for (int i = 0; i < 100001; i++)
    {
        if (capa[i] == 0)
        {
            continue;
        }
        qsort(vec[i], sz[i], sizeof(int), cmp);
        for (int j = 0; j < i && j < sz[i]; j++)
        {
            ans += vec[i][j];
        }
        free(vec[i]);
    }
    return ans;
}
