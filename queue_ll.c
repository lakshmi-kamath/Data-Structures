#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
   int data;
   struct node *next;
}node;

node *front=NULL;
node *rear =NULL;

void display()
{
   struct node *temp;
   temp=front;
   while(temp!=NULL)
   {
       printf("%d\t",temp->data);
       temp=temp->next;
   }
   printf("\n");
}
void dequeue()
{
   struct node *ptr;
   if(front==NULL)
   {
       printf("Underflow\n");
   }
   else{
       ptr=front;
       front=ptr->next;
       free(ptr);
       printf("Node deleted\n");
   }
}

void enqueue(int n)
{
   node *ptr= (node *)malloc (sizeof(node));
   if(ptr==NULL)
   {
       printf("Error memory not allocated\n");
   }
   else{
       ptr->data=n;
       ptr->next=NULL;
       if(front==NULL && rear ==NULL)
       {
           front =ptr;
           rear=ptr;
           printf("Node inserted\n");
       }
       else
       {
           rear->next=ptr;
           rear=ptr;
           printf("Node inserted\n");

       }
   }
}
int main()
{
   enqueue(1);
   enqueue(2);
   enqueue(3);
   display();
   dequeue();
   dequeue();
   display();
}

 