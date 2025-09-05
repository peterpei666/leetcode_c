#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{
    int step;
    int i;
    int j;
} state;

typedef struct
{
    state* list;
    int size;
    int capacity;
} heap;
 
heap* initialize(int n)
{
    heap* h = (heap*)malloc(sizeof(heap));
    h->size = 0;
    h->capacity = n;
    h->list = (state*)malloc(sizeof(state)*n);
    return h;
}
 
static inline void swap(state* a, state* b)
{
    state t = *a;
    *a = *b;
    *b = t;
}

static inline state top(heap* h)
{
    return h->list[0];
}
 
static inline void clear(heap* h)
{
    free(h->list);
    free(h);
}

static inline bool empty(heap* h)
{
    return h->size == 0;
}

void heapify_min(heap* minheap, int i)
{
    int smallest = i;
    int l, r;
    while (1)
    {
        l = 2 * i + 1;
        r = 2 * i + 2;
        if (l < minheap->size && minheap->list[l].step < minheap->list[smallest].step)
        {
            smallest = l;
        }
        if (r < minheap->size && minheap->list[r].step < minheap->list[smallest].step)
        {
            smallest = r;
        }
        if (i == smallest)
        {
            break;
        }
        swap(&minheap->list[i], &minheap->list[smallest]);
        i = smallest;
    }
}

void push_min(heap* minheap, state n)
{
    if(minheap->size >= minheap->capacity)
    {
        minheap->capacity *= 2;
        minheap->list = (state*)realloc(minheap->list, sizeof(state) * minheap->capacity);
    }
    int i = minheap->size;
    minheap->size++;
    minheap->list[i] = n;
    while (i && minheap->list[i].step < minheap->list[(i - 1) / 2].step)
    {
        swap(&minheap->list[i], &minheap->list[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

static inline void pop_min(heap* minheap)
{
    minheap->size--;
    minheap->list[0] = minheap->list[minheap->size];
    heapify_min(minheap, 0);
}

static inline int min(int a, int b)
{
    return a < b ? a : b;
}

int findRotateSteps(char* ring, char* key)
{
    int m = (int)strlen(key);
    int n = (int)strlen(ring);
    int mp[26][100];
    int sz[26] = {0};
    for (int i = 0; i < n; i++)
    {
        mp[ring[i] - 'a'][sz[ring[i] - 'a']] = i;
        sz[ring[i] - 'a']++;
    }
    int dist[m + 1][n];
    memset(dist, 0x7f, sizeof(dist));
    dist[0][0] = 0;
    heap* pq = initialize(64);
    push_min(pq, (state){0, 0, 0});
    while (!empty(pq))
    {
        state cur = top(pq);
        pop_min(pq);
        if (cur.i == m)
        {
            clear(pq);
            return cur.step;
        }
        if (dist[cur.i][cur.j] < cur.step)
        {
            continue;
        }
        for (int i = 0; i < sz[key[cur.i] - 'a']; i++)
        {
            int nstep = cur.step + 1 + min(abs(mp[key[cur.i] - 'a'][i] - cur.j), n - abs(mp[key[cur.i] - 'a'][i] - cur.j));
            if (nstep < dist[cur.i + 1][mp[key[cur.i] - 'a'][i]])
            {
                dist[cur.i + 1][mp[key[cur.i] - 'a'][i]] = nstep;
                push_min(pq, (state){nstep, cur.i + 1, mp[key[cur.i] - 'a'][i]});
            }
        }
    }
    return -1;
}
