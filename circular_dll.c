
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *llink;
    struct node *rlink;
}node;

static int count=0;

node *head=NULL;
node *tail=NULL;

void insertfirst()
{
    int item;
    node *ptr;
    ptr=(node *)malloc(sizeof(node));
    if(ptr==NULL)
    {
        printf("Error");
    }
    else
    {
        printf("Enter the begining node data :");
        scanf("%d",&item);
        ptr->data=item;
        if(head==NULL)
        {
            ptr->llink=ptr;
            ptr->rlink=ptr;
            head=ptr;
            tail=ptr;
            printf("Node inserted\n");
            count++;
        }
        else
        {
            ptr->rlink=head;
            ptr->llink=tail;
            head->llink=ptr;
            tail->rlink=ptr;
            head=ptr;
            printf("Node inserted\n");
            count++;
        }
    }
}

void insertlast()
{
    int item;
    node *ptr;
    ptr=(node *)malloc(sizeof(node));
    if(ptr==NULL)
    {
        printf("Error");
    }
    else
    {
        printf("Enter the last node data :");
        scanf("%d",&item);
        ptr->data=item;
        if(head==NULL)
        {
            ptr->llink=ptr;
            ptr->rlink=ptr;
            head=ptr;
            tail=ptr;
            printf("Node inserted\n");
            count++;
        }
        else
        {
            ptr->llink=tail;
            ptr->rlink=head;
            tail->rlink=ptr;
            head->llink=ptr;
            tail=ptr;
            printf("Node inserted\n");
            count++;
        }
    }

}
void insertbetween(int pos)
{
    if(pos==1)
    {
        insertfirst();
    }
    else if(pos==count+1)
    {
        insertlast();
    }
    else
    {

        if(pos>count)
        {
            printf("Position out of list size");
        }
        else
        {
            node *ptr=head;
            int i=1,item;
            printf("Enter the node data : ");
            scanf("%d",&item);
            while(i<pos-1)
            {
                ptr=ptr->rlink;
                i++;
            }
            node *temp = (node *)malloc(sizeof(node)); 
            temp->data = item;
            temp->llink=ptr;
            temp->rlink = ptr->rlink; 
            ptr->rlink->llink=temp;
            ptr->rlink = temp; 
            
            printf("Node inserted\n");
            count++;


        }
    }
}

void deletefirst()
{
    node *ptr=head;
    head=head->rlink;
    tail->rlink=head;
    head->llink=tail;
    free(ptr);
    printf("Node deleted\n");
    count--;
}

void deletelast()
{
    node *ptr=tail;
    tail=tail->llink;
    head->llink=tail;
    tail->rlink=head;
    free(ptr);
    printf("Node deleted\n");
    count--;

}
void display()
    {
        node *temp;
        temp=head;
        while(temp->rlink!=head)
        {
            printf("%d\t",temp->data);
            temp=temp->rlink;
        }
        printf("%d",temp->data);
    }

 int main() {
    int choice, value, pos, ele;
    while (1) {
        printf("\nLinked List Operations:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at last\n");
        printf("3. Insert at a specific position\n");
        printf("4. Delete first element\n");
        printf("5. Delete last element\n");
        printf("6. Display\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertfirst();
                break;
            case 2:
                insertlast();
                break;
            case 3:
                printf("Enter position to insert: ");
                scanf("%d", &pos);
                insertbetween(pos);
                break;
            case 4:
                deletefirst();
                break;
            case 5:
                deletelast();
                break;
            case 6:
                display();
                break;
            case 7:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid choice.\n");
        }
    }
    return 0;
}
