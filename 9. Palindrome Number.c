#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int x)
{
	if(x<0)
	{
		return false;
	}
	else
	{
		int a[10],m=0,f=1,i;
		while(x)
		{
			a[m]=x%10;
            x/=10;
			m++;
		}
		for(i=0;i<m/2;i++)
		{
			if(a[i]!=a[m-1-i])
			{
				f=0;
				break;
			}
		}
		if(f)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

int main(void)
{
    printf("%d\n",isPalindrome(-12321));
}
