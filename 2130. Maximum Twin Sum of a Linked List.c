#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

static inline int max(int a, int b)
{
    return a > b ? a : b;
}

int pairSum(struct ListNode* head)
{
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    struct ListNode* prev = NULL;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        struct ListNode* temp = slow->next;
        slow->next = prev;
        prev = temp;
        temp = slow;
        slow = prev;
        prev = temp;
    }
    int ans = 0;
    while (slow)
    {
        ans = max(ans, prev->val + slow->val);
        prev = prev->next;
        slow = slow->next;
    }
    return ans;
}
