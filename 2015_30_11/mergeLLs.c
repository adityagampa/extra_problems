#include <stdio.h>
#include <stdlib.h>

struct node
{
    int num;
    struct node *next;
};
struct node *createNode(int data)
{
    struct node *n=malloc(sizeof(struct node));
    n->next=NULL;
    n->num=data;
    return n;
}
struct node *insertLast(struct node *head,int data)
{
    if(!head)
    {
        head=createNode(data);
        return head;
    }
    struct node *temp=head;
    while(temp->next)
        temp=temp->next;
    temp->next=createNode(data);
    return head;
}
struct node *merge(struct node *head,struct node *temp)
{
    struct node *prev=head,*m=head;
    int flag=0;
    if(!temp)
        return head;
    if(!head)
        return temp;
    if(head->num > temp->num)
    {
        m=temp;
        temp=head;
    }
    while(m && temp)
    {
        if(temp->num < m->num && flag==0)
        {
            prev->next=temp;
            prev=temp;
            temp=temp->next;
            flag=1;
        }
        else if(flag==0)
        {
            prev=m;
            m=m->next;
        }
        else if(flag && m->num < temp->num)
        {
            prev->next=m;
            prev=m;
            m=m->next;
            flag=0;
        }
        else if(flag)
        {
            prev=temp;
            temp=temp->next;
        }

    }
    if(m)
    {
        prev->next=m;
    }
    else
        prev->next=temp;

    return head;
}
void display(struct node *head)
{
    struct node *temp=head;
    for(; temp; temp=temp->next)
        printf("%d\t",temp->num);
}
int main()
{
    struct node *head=NULL,*temp=NULL;
    int a[]= {0,3,4,6,7,10,11},b[]= {1,2,5,8,9};
    int n=7,m=5,i;
    for(i=0; i<n; i++)
    {
        head=insertLast(head,a[i]);
    }
    for(i=0; i<m; i++)
    {
        temp=insertLast(temp,b[i]);
    }
    head=merge(head,temp);
    display(head);
    return 0;
}
