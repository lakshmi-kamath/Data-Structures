#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;

node *head=NULL;
node *tail=NULL;
static int count=0;

void insertbegining()
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
        printf("Enter node data :");
        scanf("%d",&item);
        ptr->data=item;
        if(head==NULL)
        {
            ptr->next = ptr;
            head=ptr;
            tail=ptr;
            printf("Node inserted\n");
            count++;
        }
        else
        {
         ptr->next=head;
         head=ptr; 
         tail->next=ptr;
         printf("Node inserted \n");
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
        printf("Enter node data :");
        scanf("%d",&item);
        ptr->data=item;
        if(head==NULL)
        {
            ptr->next = ptr;
            head=ptr;
            tail=ptr;
            printf("Node inserted\n");
            count++;
        }
        else
        {
            tail->next=ptr;
            tail=ptr;
            ptr->next=head;
            printf("Node inserted\n" );
            count++;
        }
    }

}

void insertbetween(int pos)
{

    if(pos==1)
    {
        insertbegining();
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
                ptr=ptr->next;
                i++;
            }
            node *temp = (node *)malloc(sizeof(node)); 
            temp->data = item;
            temp->next = ptr->next; 
            ptr->next = temp; 
            printf("Node inserted\n");
            count++;


        }

    }
}

void deletefirst()
{
    if(head==NULL)
    {
        printf("Error:No node present to delete\n");
    }
    else
    {
        node *ptr=head;
        head=head->next;
        tail->next=head;
        free(ptr);
        printf("Node deleted\n");
        count--;

    }
}
void deletelast()
{
    if(head==NULL)
    {
        printf("Error:No node present to delete\n");
    }
    else
    {
        node*temp;
        temp=head;
        while(temp->next !=tail)
        {
            temp=temp->next;
        }
        tail=temp;
        temp=temp->next;
        tail->next=head;
        printf("Node deleted\n");
        count--;
    }

}
void search(int n)
{
    int i=0,pos;
    node *temp=head;
    if(head==NULL)
    {
        printf("No nodes to search from\n");
    }
    while(temp->next !=head)
    {
        i++;
        if(temp->data==n)
        {
             pos=i;
            temp=tail;
        }
        else{
        temp=temp->next;

    }
    }
    if(pos !=0)
    {
        printf("The elements %d is found at %d\n",n,pos);
    }

    else
    {
        printf("Element not found\n");
    }
    
}
void display()
    {
        node *temp;
        temp=head;
        while(temp->next!=head)
        {
            printf("%d\t",temp->data);
            temp=temp->next;
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
        printf("6. Recursive search for an element\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertbeginning();
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
                printf("Enter element to search: ");
                scanf("%d", &ele);
                Search(ele);
                break;
            case 7:
                display();
                break;
            case 8:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid choice.\n");
        }
    }
    return 0;
}
