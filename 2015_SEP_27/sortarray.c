#include <stdio.h>
#include <stdlib.h>
int s[2],size=2;
void sort(int * a,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(a[i] == 0)
            s[0]++;
        else if(a[i] == 1)
            s[1]++;
    }
    for(i=0;i<size;i++)
        printf(" %d :%d\n",i,s[i]);
}
int main()
{
    int a[] = {1,0,0,0,1,1,1,0,1,0,1};
    sort(a,11);
    return 0;
}
