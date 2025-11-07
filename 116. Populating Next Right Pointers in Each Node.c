#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Node
{
    int val;
    struct Node *left;
    struct Node *right;
    struct Node *next;
};

int cnt[12];
struct Node* layer[12][2048];

void dfs(struct Node* node, int depth)
{
    if (node)
    {
        layer[depth][cnt[depth]] = node;
        cnt[depth]++;
        dfs(node->left, depth + 1);
        dfs(node->right, depth + 1);
    }
}

struct Node* connect(struct Node* root)
{
    memset(cnt, 0, sizeof(cnt));
    dfs(root, 0);
    for (int i = 1; i < 12; i++)
    {
        for (int j = 1; j < cnt[i]; j++)
        {
            layer[i][j - 1]->next = layer[i][j];
        }
    }
    return root;
}
