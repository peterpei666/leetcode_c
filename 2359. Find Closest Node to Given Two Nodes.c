#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

inline int max(int a,int b)
{
    return a>b?a:b;
}

int closestMeetingNode(int* edges, int n, int node1, int node2)
{
    int i,ans=INT_MAX,p=-1,cnt;
    int list1[n];
    int list2[n];
    memset(list1,-1,sizeof(list1));
    memset(list2,-1,sizeof(list2));
    list1[node1]=0;
    list2[node2]=0;
    cnt=0;
    while(edges[node1]!=-1)
    {
        node1=edges[node1];
        cnt++;
        if(list1[node1]!=-1)
        {
            break;
        }
        list1[node1]=cnt;
    }
    cnt=0;
    while(edges[node2]!=-1)
    {
        node2=edges[node2];
        cnt++;
        if(list2[node2]!=-1)
        {
            break;
        }
        list2[node2]=cnt;
    }
    for(i=0;i<n;i++)
    {
        if(list1[i]==-1||list2[i]==-1)
        {
            continue;
        }
        if(ans>max(list1[i],list2[i]))
        {
            ans=max(list1[i],list2[i]);
            p=i;
        }
    }
    return p;
}
