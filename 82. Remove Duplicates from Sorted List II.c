#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head)
{
    struct ListNode dummy;
    struct ListNode* tail = &dummy;
    while (head != NULL)
    {
        int val = head->val;
        struct ListNode* node = head->next;
        int cnt = 1;
        while (node != NULL && node->val == val)
        {
            cnt++;
            node = node->next;
        }
        if (cnt == 1)
        {
            tail->next = head;
            tail = head;
        }
        head = node;
    }
    tail->next = NULL;
    return dummy.next;
}
