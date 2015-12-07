#include <stdio.h>
#include <stdlib.h>
void base2to8(long long int a)
{
    long long int c=a;
    int q=1,s=0,count=0,result=0,term=1;
    while(c>0)
    {
        s=(c%10)*q+s;
        count++;
        c=c/10;
        q=q*2;
        if(count>=3)
        {
            result = result +s*term;
            term=term*10;
            q=1,s=0,count=0;
        }
    }
    if(count!=0)
    {
        result = result +s*term;
    }
    printf("Base 8 representation is %d\n",result);
}
int main()
{
    base2to8(1111111100000);
    return 0;
}
