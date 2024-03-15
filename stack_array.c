
#include<stdio.h>
#include<stdlib.h>
#define STACKSIZE 100


struct stack
{
    int top;
    int items[STACKSIZE];
};

struct stack s; 

void push(int item)
{
    if(s.top == (STACKSIZE - 1))
    {
        printf("Overflow\n");
    }
    else
    {
        s.top = s.top + 1; 
        s.items[s.top] = item; 
    }
}
void pop()
{
    s.top= s.top-1;

}
void display()
{
     printf("\nStack elements: ");
    for (int i = 0; i <= s.top; i++) 
    {
        printf("%d\t", s.items[i]);
    }

}
void peek()
{
    int i=s.top;
    printf("\nThe element at top is %d",s.items[i]);
}


int main()
{
    s.top=-1;
    int n,item;
    printf("Enter  number of elements");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&item);
        push(item);
    }
    display();
    pop();
    display();
    peek();
    push(33);
    display();
}