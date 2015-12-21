#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
bool b[10];
void reset()
{
    int i=0;
    while(i<10)
    {
        b[i]=0;
        i++;
    }
}
void set(long int i)
{
    while(i>0)
    {
        b[i%10]+=1;
        i=i/10;

    }
}
int fn2(long int i)
{
    int c;
    while(i>0)
    {
        c=i%10;
        if(b[c]==0)
            return 0;
        b[c]--;
        i=i/10;
    }
    return 1;
}
void fn()
{
    int j=2;
    long int i=100000;
    int q;
    int count=0;
    while(i<500000)
    {
        count=0;
        while(j<=6)
        {
            set(i);
            if((i*j)>999999)
            {
                j++;
                break;
            }

            q=fn2(i*j);
            if(q==1)
            {
                count++;
                j++;
            }
            else
                break;
            reset();
        }
        j=2;
        if(count==5)
            printf("%ld",i);
        i++;
    }
}
int main()
{
    fn();
    return 0;
}
