#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* belowTen[]={"","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
char* tenToTwenty[]={"Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
char* ten[]={"","Ten","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};

void dfs(char* s,int num)
{
    if(num<10)
    {
        strcat(s,belowTen[num]);
    }
    else if(num<20)
    {
        strcat(s,tenToTwenty[num-10]);
    }
    else if(num<100)
    {
        strcat(s,ten[num/10]);
        if(num%10)
        {
            strcat(s," ");
            strcat(s,belowTen[num%10]);
        }
    }
    else if(num<1000)
    {
        dfs(s,num/100);
        strcat(s," Hundred");
        if(num%100)
        {
            strcat(s," ");
            dfs(s,num%100);
        }
    }
    else if(num<1000000)
    {
        dfs(s,num/1000);
        strcat(s," Thousand");
        if(num%1000)
        {
            strcat(s," ");
            dfs(s,num%1000);
        }
    }
    else if(num<1000000000)
    {
        dfs(s,num/1000000);
        strcat(s," Million");
        if(num%1000000)
        {
            strcat(s," ");
            dfs(s,num%1000000);
        }
    }
    else
    {
        dfs(s,num/1000000000);
        strcat(s," Billion");
        if(num%1000000000)
        {
            strcat(s," ");
            dfs(s,num%1000000000);
        }
    }
}

char* numberToWords(int num)
{
    char* s=(char*)malloc(500);
    s[0]='\0';
    if(num==0)
    {
        strcat(s,"Zero");
        return s;
    }
    dfs(s,num);
    return s;
}
