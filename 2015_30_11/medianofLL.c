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
    for(;head;head=head->next)
        printf("\t%d",head->num);
    printf("\n");
}
int count;
struct node *median(struct node* head)
{
    struct node *temp=head,*s=head;
    count=1;
    while(temp!=NULL)
    {
        if(temp->next && !temp->next->next)
        {
            count++;
            return s;
        }
        if(!temp->next)
            return s;
        temp=temp->next->next;
        s=s->next;
        count=count+2;
    }
    return s;
}
int main()
{
    struct node *head=NULL,*temp=NULL;
    int a[]={1,2,3,4,5};
    int n=sizeof(a)/sizeof(int),i;
    for(i=0;i<n;i++)
    {
        head=insertLast(head,a[i]);
    }
    temp=median(head);
    printf("Linked List:");
    display(head);
    if(count%2!=0 && temp)
        printf("\nMedian(Odd length LL) :\t%d",temp->num);
    else if(count>=2)
        printf("\nTwo Medians(Even length LL) :\t%d\t%d",temp->num,temp->next->num);
    else if(count==1)
        printf("\nNo nodes in Linked List ->  No median\n");
    return 0;
}
