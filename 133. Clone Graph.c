#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int val;
    int numNeighbors;
    struct Node** neighbors;
};

struct Node* memo[101];

struct Node* dfs(struct Node* node)
{
    if (memo[node->val])
    {
        return memo[node->val];
    }
    memo[node->val] = (struct Node*)malloc(sizeof(struct Node));
    memo[node->val]->val = node->val;
    memo[node->val]->numNeighbors = node->numNeighbors;
    memo[node->val]->neighbors = (struct Node**)malloc(node->numNeighbors * sizeof(struct Node*));
    for (int i = 0; i < node->numNeighbors; i++)
    {
        memo[node->val]->neighbors[i] = dfs(node->neighbors[i]);
    }
    return memo[node->val];
}

struct Node* cloneGraph(struct Node* node)
{
    if (!node)
    {
        return NULL;
    }
    memset(memo, 0, sizeof(memo));
    return dfs(node);
}
