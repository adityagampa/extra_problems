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
struct node *addNodetoCircularLL(struct node *head,int num)
{
    struct node *s=head,*f=head,*start=head;
    while(1)
    {
        s=s->next;
        f=f->next->next;
        if(s==f)
            break;
    }
    while(1)
    {
        f=s;
        start=start->next->next;
        s=s->next;
        if(start==s)
            break;
    }
    s=createNode(num);
    f->next=s;
    s->next=start;
    return head;
}
void displayCLL(struct node *head)
{
    struct node *temp=head;
    do
    {
        if(!temp)
            break;
        printf("%d\t",temp->num);
        temp=temp->next;
    }
    while(temp!=head);
    printf("\n");
}
struct node *makeCycle(struct node *head)
{
    struct node *temp=head;
    while(temp->next)
    {
        temp=temp->next;
    }
    temp->next=head;
    return head;
}
int main()
{
    struct node *head=NULL;
    int a[]= {1,2,3,4,5,6};
    int n=sizeof(a)/sizeof(int),i;
    for(i=0; i<n; i++)
    {
        head=insertLast(head,a[i]);
    }
    printf("Linked List Before adding Cycle :\n");
    displayCLL(head);
    head=makeCycle(head);
    printf("Linked List After adding Cycle :\n");
    displayCLL(head);
    head=addNodetoCircularLL(head,7);
    printf("Linked List After adding a new Node '7' at the end :\n");
    displayCLL(head);
    return 0;
}
