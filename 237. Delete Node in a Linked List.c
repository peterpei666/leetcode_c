#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

void deleteNode(struct ListNode* node)
{
    *node = *(node->next);
}
