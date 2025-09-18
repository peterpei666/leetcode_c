#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct
{
    int val;
    int row;
}pair;

typedef struct
{
    pair* list;
    int size;
    int capacity;
} heap;
 
heap* initialize(int n)
{
    heap* h = (heap*)malloc(sizeof(heap));
    h->size = 0;
    h->capacity = n;
    h->list = (pair*)malloc(sizeof(pair)*n);
    return h;
}
 
static inline void swap(pair* a, pair* b)
{
    pair t = *a;
    *a = *b;
    *b = t;
}

static inline pair top(heap* h)
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
        if (l < minheap->size && minheap->list[l].val < minheap->list[smallest].val)
        {
            smallest = l;
        }
        if (r < minheap->size && minheap->list[r].val < minheap->list[smallest].val)
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

void push_min(heap* minheap, pair n)
{
    if(minheap->size >= minheap->capacity)
    {
        minheap->capacity *= 2;
        minheap->list = (pair*)realloc(minheap->list, sizeof(pair) * minheap->capacity);
    }
    int i = minheap->size;
    minheap->size++;
    minheap->list[i] = n;
    while (i && minheap->list[i].val < minheap->list[(i - 1) / 2].val)
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

static inline int max(int a, int b)
{
    return a > b ? a : b;
}

int* smallestRange(int** nums, int n, int* sz, int* returnSize)
{
    heap* pq = initialize(n);
    int col[n];
    int r = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        col[i] = 1;
        push_min(pq, (pair){nums[i][0], i});
        r = max(r, nums[i][0]);
    }
    int ans_l = 0, ans_r = 0;
    int dif = INT_MAX;
    while (pq->size == n)
    {
        pair temp = top(pq);
        int l = temp.val;
        if (r - l < dif)
        {
            dif = r - l;
            ans_l = l;
            ans_r = r;
        }
        pop_min(pq);
        if (col[temp.row] < sz[temp.row])
        {
            r = max(r, nums[temp.row][col[temp.row]]);
            push_min(pq, (pair){nums[temp.row][col[temp.row]], temp.row});
            col[temp.row]++;
        }
    }
    clear(pq);
    int* ans = (int*)malloc(sizeof(int) * 2);
    ans[0] = ans_l;
    ans[1] = ans_r;
    *returnSize = 2;
    return ans;
}
