#include <stdio.h>
#include <stdlib.h>

void sort(int *a,int size)
{
    int i=0,j=0,temp;
    for(i=0; i<size; i++)
    {
        for(j=0; j<size; j++)
        {
            if(a[j]>a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}
void moreThanKTimes(int k)
{
    int a[] = {1,2,3,4,5,1,1,2,2,3,1};
    int count=0,size=11,i=0,max=0,idx,cost=0;
    sort(a,size);
    for(i=1; i<size-1; i++)
    {
        if(a[i-1]!=a[i])
        {
            if(max < count)
            {
                max = count;
                idx = i-1-count;
            }
            count=0;
        }
        else
            count++;
    }
    if(max >= k)
        printf("\n max number of occurences of a number: %d",max);
    else
    {
        for(i=0; i<size && max<k ; i++)
        {
            if(a[i]!=a[idx])
            {
                cost=cost+a[i]-a[idx];
                a[i]=a[idx];
                max++;
            }
        }
        if(max >= k)
            printf("\n cost : %d\n",cost);
    }
}
int main()
{
    moreThanKTimes(4);
    return 0;
}
