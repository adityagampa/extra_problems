#include <stdio.h>
#include <stdlib.h>
int numberlength;
int lengthOfNumber(int num1,int num2)
{
    int c=num1,d=num2;
    while(c>0 || d>0)
    {
        c=c/10;
        d=d/10;
        numberlength++;
    }
    return numberlength;
}
void addFromLeft(int num1,int num2)
{
    int i,k;
    lengthOfNumber(num1,num2);
    char a[numberlength],b[numberlength],result[numberlength];
    for(i=numberlength-1; num1>0 && i>=0; i--)
    {
        a[i]=num1%10;
        b[i]=num2%10;
        result[i]='-';
        num1=num1/10;
        num2=num2/10;
    }

    for(i=0; i<numberlength; i++)
    {
        if( (a[i]+b[i])<9 )
        {
            result[i]= a[i]+b[i];
        }
        else if( (a[i]+b[i])>9 )
        {
            result[i]=(a[i]+b[i])%10;
            k=1;
            do
            {
                if(result[i-k]=='-')
                {
                    result[i-k]=0;
                    k++;
                }
                if(result[i-k]!='-')
                    result[i-k]=result[i-k]+1;

            }
            while(result[i-k]=='-');
        }
    }

    for(i=0; i<numberlength; i++)
    {
        if(result[i]=='-')
            result[i]=9;
        printf("%d",result[i]);
    }
}
int main()
{
    addFromLeft(12345,67890);
    return 0;
}
