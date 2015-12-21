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
struct node *sortLLPositionsChanged(struct node *head)
{
    struct node *t1=head,*t2=head;
    while(1)
    {
        if(!t1)
            return head;
        if(t1->next && t1->num>t1->next->num)
        {
            break;
        }
        t1=t1->next;
    }
    t2=t1->next;
    if(t2->next && t2->num < t2->next->num && t2->num < t1->num)
    {
        swap(t1,t2);
        return head;
    }
    while(1)
    {
        if(t2->next && t2->num>t2->next->num)
            break;
        t2=t2->next;
    }
    t2=t2->next;
    swap(t1,t2);
    return head;
}
int main()
{
    struct node *head=NULL;
    int a[]= {1,2,3,10,4,15,20};
    int n=sizeof(a)/sizeof(int),i;
    for(i=0; i<n; i++)
    {
        head=insertLast(head,a[i]);
    }
    head=sortLLPositionsChanged(head);
    display(head);
    return 0;
}
