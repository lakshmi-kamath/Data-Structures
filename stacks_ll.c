#include<stdio.h>
#include<stdlib.h>
struct node
{
    int Data;
    struct node *next;
};
struct node *head;

void push()
{
    struct node *ptr,*temp;
    ptr=(struct node *)malloc(sizeof(struct node));
    if(ptr==NULL)

    {
        printf("Error");
    }
    printf("Enter the value \n");
    scanf("%d",&ptr->Data);
    if(head==NULL)
    {
    ptr->next = NULL;
    head=ptr;
    printf("Node inserted\n");
    }
    else
    {
        ptr->next=head;
        head=ptr;
    }
}
void pop()
{
    struct node *ptr;
    if(head==NULL)
    {
        printf("Underflow\n");
    }
    else{
        ptr=head;
        head=ptr->next;
        free(ptr);
        printf("Node deleted\n");
    }
}

void display()
 {
    struct node *temp;
    temp=head;
    while(temp!=NULL)
    {
        printf("%d\t",temp->Data);
        temp=temp->next;
    }
}

void peek()
{
    if(head==NULL)
    {
        printf("Underflow\n");
    }
    else{
        printf("\nThe top element is %d\n",head->Data);
    }
}

int main()
{
    push();
    push();
    push();
    pop();
    display();
    peek();
    
}
