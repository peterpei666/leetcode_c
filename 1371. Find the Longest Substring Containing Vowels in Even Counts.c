#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char v[5]={'a','e','i','o','u'};

inline int vowel(char c)
{
	int i;
	for(i=0;i<5;i++)
	{
		if(c==v[i])
		{
			return i;
		}
	}
	return -1;
}

inline int max(int a,int b)
{
	return a>b?a:b;
}

inline int min(int a,int b)
{
	return a<b?a:b;
}

int findTheLongestSubstring(char* s)
{
	int i,mask,temp,ans=0;
	int list[1<<5];
	int n=(int)strlen(s);
	memset(list,0x7f,sizeof(list));
	list[0]=-1;
	mask=0;
	for(i=0;i<n;i++)
	{
		temp=vowel(s[i]);
		if(temp==-1)
		{
			ans=max(ans,i-list[mask]);
			continue;
		}
		mask^=1<<temp;
		list[mask]=min(list[mask],i);
		ans=max(ans,i-list[mask]);
	}
	return ans;
}