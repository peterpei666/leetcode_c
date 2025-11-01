#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* partition(struct ListNode* head, int x)
{
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode ans;
    struct ListNode* pre = &dummy;
    struct ListNode* cur = head;
    struct ListNode* temp = &ans;
    while (cur != NULL)
    {
        if (cur->val < x)
        {
            pre->next = cur->next;
            temp->next = cur;
            temp = cur;
        }
        else
        {
            pre = cur;
        }
        cur = cur->next;
    }
    temp->next = dummy.next;
    return ans.next;
}
