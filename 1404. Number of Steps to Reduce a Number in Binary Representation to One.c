#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void add(char** s)
{
	int f=1,p=(int)strlen(*s);
	char* temp=(char*)malloc(sizeof(char)*(p+2));
	strcpy(temp+1,*s);
	temp[0]='0';
	while(f&&p>=0)
	{
		temp[p]+=1;
		f=0;
		if(temp[p]=='2')
		{
			temp[p]='0';
			f=1;
		}
		p--;
	}
    free(*s);
	if(temp[0]=='0')
	{
        *s=strdup(temp+1);
	}
	else
	{
        *s=strdup(temp);
	}
	free(temp);
}

int numSteps(char* s)
{
	int p;
	int count=0;
    char* str=(char*)malloc(sizeof(char)*(strlen(s)+1));
    strcpy(str,s);
	while(strcmp(str,"1"))
	{
		p=(int)strlen(str)-1;
		if(str[p]=='0')
		{
			str[p]='\0';
			count++;
		}
		else
		{
			add(&str);
			count++;
		}
	}
    free(str);
	return count;
}


int main(void)
{
	char s1[]="1101";
	char s2[]="10";
	char s3[]="1";
	printf("%d %d %d\n",numSteps(s1),numSteps(s2),numSteps(s3));
}
