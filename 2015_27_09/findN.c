#include <stdio.h>
#include <stdlib.h>

int findN(int *a)
{
    int i=1,j=1;
    if(a[3]==0)
        return 1;
    while(1)
    {
        if(a[i]==0)
        {
            break;
        }
        else
        {
            printf("\na[%d] is %d",i,a[i]);
            j=i;
            i=i*2;
        }
    }

    while(1)
    {
        i=(i+j)/2;

        if(a[i]>a[i+1] && a[i]>a[i-1])
            break;
    }

 //   while(a[i]==0)
   //     i--;
    return i-1;
}
int main()
{
    int a[]={1,2,3,4,5,6,7,8,5,0,0,0,0,0,0,0};
    printf("\nsize of the array is %d",findN(a));
    return 0;
}
