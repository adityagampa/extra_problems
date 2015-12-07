#include <stdio.h>
#include <stdlib.h>
char numbers[50][20] = {"","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
char nums[50][20]= {"","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety","Hundred","Thousand"};
char months[13][20] = {"","January","February","March","April","May","June","July","August","September","October","November","December"};
int reverse(int y,int *count)
{
    int rev=0;
    while(y>0)
    {
        rev = rev*10 +y%10;
        y=y/10;
        (*count)++;
    }
    return rev;
}
void date(int d)
{
    int z=0;
    if(d>=20 && d<=31)
    {
        d=reverse(d,&z);
        printf("%s ",nums[d%10-1]);
        d=d/10;
        if(d!=0)
            printf("%s ",numbers[d%100]);
    }
    else if(d>=1 && d<=19)
    {
        printf("%s ",numbers[d]);
        return;
    }
    else
        return;
}
void month(int m)
{
    printf("%s, ",months[m]);
}
void year(int y)
{
    int count=0,flag=1;
    y=reverse(y,&count);
    while(y>0)
    {
        if(count==4 && flag==1)
        {
            printf("%s Thousand ",numbers[y%10]);
            count=1;
            flag=0;
        }
        else if(y>100 && y<1000)
        {
            if(y%10!=0)
            {
                printf("%s Hundred and ",numbers[y%10]);
            }
            else
                printf("and ");
            y=y/10;
            y=reverse(y,&count);
            continue;
        }
        else if(y>20 && y<100)
        {
            y=reverse(y,&count);
            printf("%d ",y);
            printf("%s ",nums[y%10-1]);
        }
        else if(y>0 && y<=20)
        {
            printf("%s ",numbers[y]);
            break;
        }
        y=y/10;
    }
}
void dateInWords(int d,int m,int y)
{
    date(d);
    month(m);
    year(y);
}
int main()
{
    dateInWords(28,10,2015);
    return 0;
}
