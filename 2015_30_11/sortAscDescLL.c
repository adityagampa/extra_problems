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
void display(struct node *head)
{
    struct node *temp=head;
    for(; temp; temp=temp->next)
        printf("%d\t",temp->num);
}
void swap(struct node *t1,struct node *t2)
{
    int data=t1->num;
    t1->num=t2->num;
    t2->num=data;
}
struct node *reverseLL(struct node *head)
{
    if(!head->next)
        return head;
    struct node *m=head,*n=head->next,*p=head->next->next;
    while(p)
    {
        n->next=m;
        m=n;
        n=p;
        p=p->next;
    }
    n->next=m;
    head->next=NULL;
    head=n;
    return head;
}
struct node *sortLLAscDescNums(struct node *head)
{
    struct node *temp=head,*prev=head;
    while(temp)
    {
        if(temp->num > temp->next->num)
            break;
        prev=temp;
        temp=temp->next;
    }
    temp=reverseLL(temp);
    prev->next=temp;
    return head;
}
int main()
{
    struct node *head=NULL;
    int a[]={1,2,7,20,15,10};
    int n=sizeof(a)/sizeof(int),i;
    for(i=0; i<n; i++)
    {
        head=insertLast(head,a[i]);
    }
    head=sortLLAscDescNums(head);
    display(head);
    return 0;
}
