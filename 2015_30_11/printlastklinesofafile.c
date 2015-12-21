#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
void fn(int k)
{
    int fp=open("C:\\Users\\CCS\\Desktop\\sample.txt",O_RDONLY);
    lseek(fp,1L,2);
    char ch;
    int n;
    while(k)
    {
        n=read(fp,&ch,1);
        if(ch == '\n')
        {
            k--;
            lseek(fp,-3L,1);
            continue;
        }
        lseek(fp,-2L,1);
    }
    lseek(fp,3l,1);
    while(n=read(fp,&ch,1)!=0)
    {
        printf("%c",ch);
    }

    close(fp);
}
int main()
{
    fn(3);
    return 0;
}
