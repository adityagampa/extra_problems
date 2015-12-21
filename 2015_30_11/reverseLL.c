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
struct node *RreverseLL(struct node *head,struct node *m,struct node *n,struct node *p)
{
    if(!p)
    {
        n->next=m;
        head->next=NULL;
        head=n;
        return head;
    }
    n->next=m;
    return RreverseLL(head,n,p,p->next);
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
void display(struct node *head)
{
    struct node *temp=head;
    for(; temp; temp=temp->next)
        printf("%d\t",temp->num);
}
int main()
{
    struct node *head=NULL;
    int a[]= {1,2,3,4,5};
    int n=5,i;
    for(i=0; i<n; i++)
    {
        head=insertLast(head,a[i]);
    }
    head=reverseLL(head);
    printf("reversing LL using iterative approach:\n");
    display(head);
    if(head->next)
        head=RreverseLL(head,head,head->next,head->next->next);
    printf("\nAgain reversing LL using recursive approach:\n");
    display(head);
    return 0;
}
