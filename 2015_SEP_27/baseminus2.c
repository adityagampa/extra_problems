#include <stdio.h>
#include <stdlib.h>
int a[50];
void baseMinusTwo(int n)
{
    int i=-2,flag=1,j=0;
    while( n>1 || -1*n>1)
    {
        if(n%i<0)
        {
            n=n/i;
            n++;
            a[j++]=1;
            continue;
        }
        a[j++]=n%i;
        n=n/i;
        if(n%2 == 0)
            flag=1;
        else
            flag=0;
    }
    if(n == -1)
    {
        if(flag == 1)
        {
            a[j++]=0;
            a[j++]=1;
        }
        else
        {
            a[j++]=1;
            a[j++]=1;
        }
        n=n/i;
    }
    else if(n == 1)
    {
        a[j++]=1;
        n=n/i;
    }
    for(flag=j-1; flag>=0; flag--)
        printf("%d",a[flag]);
}
int main()
{
    baseMinusTwo(11);
    return 0;
}
