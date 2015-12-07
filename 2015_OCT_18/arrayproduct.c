#include <stdio.h>
#include <stdlib.h>
void arrayProduct(int *a,int size,int idx)
{
    int i=0,prod=1;
    for(;i<size;i++)
    {
        if(i!=idx)
        {
            prod = prod*a[i];
        }
    }
    if(prod == a[idx])
        printf("Yes");
    else
        printf("No");
}
int main()
{
    int a[]={1,2,3,6};
    int size=4,idx=3;
    arrayProduct(a,size,idx);
    return 0;
}
