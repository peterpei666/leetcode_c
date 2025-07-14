#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

int getDecimalValue(struct ListNode* head)
{
    int ans=0;
    while(head)
    {
        ans<<=1;
        ans+=head->val;
        head=head->next;
    }
    return ans;
}
