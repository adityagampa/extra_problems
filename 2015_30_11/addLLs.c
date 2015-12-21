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
struct node *addLL(struct node *head,struct node *temp)
{
    struct node *prev=head,*m=head;
    if(!m)
        return temp;
    if(!temp)
        return head;
    while(m && temp)
    {
        m->num=m->num + temp->num;
        if(!m->next)
            prev=m;
        else if(!temp->next)
            prev=temp;
        m=m->next;
        temp=temp->next;
    }
    if(!m)
        prev->next=temp;
    else
        prev->next=m;
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
    int a[]= {0,1,2,3,4,5},b[]={7,8,9};
    int n=6,m=3,i;
    for(i=0; i<n; i++)
    {
        head=insertLast(head,a[i]);
    }
    for(i=0; i<m; i++)
    {
        temp=insertLast(temp,b[i]);
    }
    head=addLL(head,temp);
    display(head);
    return 0;
}
