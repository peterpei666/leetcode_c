#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

unsigned char visited[1250];

inline bool test(int a)
{
    return visited[a>>3]&(1<<(a&7))?true:false;
}

inline void set(int a)
{
    visited[a>>3]|=1<<(a&7);
}

inline void reset(int a)
{
    visited[a>>3]&=~(1<<(a&7));
}

int numComponents(struct ListNode* head, int* nums, int n)
{
    int ans=0,i;
    memset(visited,0,sizeof(visited));
    for(i=0;i<n;i++)
    {
        set(nums[i]);
    }
    while(head)
    {
        if(test(head->val)&&(head->next==NULL||test(head->next->val)==false))
        {
            ans++;
        }
        head=head->next;
    }
    return ans;
}
