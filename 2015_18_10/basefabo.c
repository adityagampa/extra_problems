#include <stdio.h>
#include <stdlib.h>
int b[20],size;
void basefabo(int n)
{
    int a[11]={1,1,2,3,5,8,13,21,34,55,89};
    int i,sum=0,red;
    for(i=0;a[i]<=n;i++)
    {
        b[i]=1;
        sum+=a[i];
    }
    size = --i;
    red=sum-n;
    while(red!=0)
    {
        if((red-a[i]) >= 0)
        {
            b[i]=0;
            red=red-a[i];
        }
        else
            i--;
    }
    for(red=size;red>=0;red--)
        printf("%d",b[red]);
}
int main()
{
    basefabo(21);
    return 0;
}
