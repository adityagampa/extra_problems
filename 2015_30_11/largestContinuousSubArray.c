#include <stdio.h>
#include <stdlib.h>
void display(int *a,int e,int sum)
{
    int i=e,s;
    while(i>=0)
    {
        if(sum)
        {
            sum-=a[i];
            i--;
        }
        else
            break;
    }
    s=i+1;
    printf("Sub Array :\t");
    for(; s<=e; s++)
        printf("%d ",a[s]);
}
int largestContinuesSumArray(int *a,int n)
{
    int prev=0,sum=0,i=0,end=0;
    for(i=0; i<n; i++)
    {
        sum=sum+a[i];
        if(sum<0)
        {
            sum=0;
        }
        if(sum>prev)
        {
            end=i;
            prev=sum;
        }
    }
    display(a,end,prev);
    return prev;
}
int main()
{
    int a[]= {1, 2 ,3 ,4 ,5 ,-2, -3, -4, -20, 10, 2};
    int n=sizeof(a)/sizeof(int);
    printf("\nSum :\t%d\n",largestContinuesSumArray(a,n));
    return 0;
}
