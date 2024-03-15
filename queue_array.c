#include<stdio.h>
#include<stdlib.h>
#define SIZE 100


typedef struct NODE
{
    int queue[SIZE];
    int front,rear;
}node;

node n;
void enqueue(int n,node *ptr)
{
    if(ptr->rear==(SIZE-1))
    {
        printf("Overflow");
    }
    else if (ptr->front == -1 && ptr->rear == -1)
    {
        ptr->front=ptr->rear=0;
        ptr->queue[ptr->front]=n;
    }
    else{
        ptr->rear++;
        ptr->queue[ptr->rear]=n;
    }
}

void display(node *ptr)
{
    if (ptr->front == -1 || ptr->rear == -1)
    {
        printf("No element present\n");
    }
    else{
    for (int i=ptr->front;i<=ptr->rear;i++)
    {
        printf("%d\t",ptr->queue[i]);
    }
     printf("\n");
    }

}
void dequeue(node *ptr)
{
    if(ptr->front==-1 && ptr->rear==-1)
    {
        printf("\nNo element to delete UNDERFLOW");
    }
    else if(ptr->front == ptr->rear)
    {
        printf("\nThe deleted element is --> %d\n",ptr->queue[ptr->front]);
        ptr->front = ptr->rear =-1;
    }
    else{
    printf("\nThe deleted element is --> %d\n",ptr->queue[ptr->front]);
    ptr->front ++;
    }
}

int main()
{
n.front=-1;
n.rear=-1;
enqueue(1,&n);
enqueue(2,&n);
enqueue(3,&n);
display(&n);
dequeue(&n);
dequeue(&n);
display(&n);
}