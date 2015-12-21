#include <stdio.h>
#include <stdlib.h>
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void sort01Array(int *a,int n)
{
    int i=0,j=n-1;
    while(1)
    {
        if(a[i]==0)
        {
            i++;
            continue;
        }
        else if(a[j]==1)
        {
            j--;
            continue;
        }
        if(i>j)
            return;
        swap(&a[i],&a[j]);
    }
}
void display(int *a,int n)
{
    int i=0;
    for(;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}
int main()
{
    int a[] = {1,0,0,0,1,1,1,0,1,0,1};
    int n=sizeof(a)/sizeof(int);
    sort01Array(a,n);
    display(a,n);
    return 0;
}
