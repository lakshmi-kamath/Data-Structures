#include<stdio.h>
#include<stdlib.h>
 typedef struct node
 {
    int data ;
    struct node *next;
 }node;
int count=0;

 node *head=NULL;

void begininsert()
{
    node *ptr= (node *)malloc(sizeof(node));
    if(ptr==NULL)
    {
        printf("Error");
    }
    int item;
    printf("Enter node data:");
    scanf("%d",&item);
    ptr->data=item;
    if(head==NULL)
    {
        ptr->next=NULL;
        head=ptr;
        printf("NOde inserted\n");
        count++;
    }
    else
    {
        ptr->next=head;
        head=ptr;
        printf("Node inserted\n");
        count++;
    }

}
void display()
{
    if(head==NULL)
    {
        printf("List is empty");
    }
    else
    {
        node *temp=head;
        while(temp!=NULL)
        {
            printf("%d\t",temp->data);
            temp=temp->next;
        }
    }
}
void insertlast()
{
    node *ptr= (node *)malloc(sizeof(node));
    if(ptr==NULL)
    {
        printf("Error");
    }
    int item;
    printf("Enter node data:");
    scanf("%d",&item);
    ptr->data=item;
    if(head==NULL)
    {
        ptr->next=NULL;
        head=ptr;
        printf("NOde inserted\n");
        count++;
    }
    else{
        node *temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=ptr;
        ptr->next=NULL;
        printf("Node inserted\n");
        count++;
    }
}
void randominsert()
{
    int pos,item;
    printf("Enter position :");
    scanf("%d",&pos);
    if(head==NULL || pos>count+1)
    {
        printf("POSITION value is greater than list length\n");
    }
    else if (pos==1)
    {
        begininsert();
    }
    else if(pos==(count+1))
    {
        insertlast();
    }
    else{
        printf("Enter node data:");
        scanf("%d",&item);
        node *ptr=(node *)malloc(sizeof(node));
        if(ptr==NULL)
        {
            printf("Error");
        }
        else{
            ptr->data=item;
            node *temp=head;
            int i=1;
            while(i<pos-1){
                temp=temp->next;
                i++;
            }
            node *a=temp->next;
            temp->next=ptr;
            ptr->next=a;
            printf("Node inserted\n");
            count++;
        }
    }
}
void deletebegining()
{
    if(head==NULL)
    {
        printf("List is empty\n");
    }
    else if(head->next==NULL)
    {
        head=NULL;
        printf("Node deleted\n");
        count--;
    }
    else{
        node *ptr=head;
        head=head->next;
        free(ptr);
        count--;
        printf("Node deleted\n");
    }
}

void deleteend()
{if(head==NULL)
    {
        printf("List is empty\n");
    }
    else if(head->next==NULL)
    {
        head=NULL;
        printf("Node deleted\n");
        count--;
    }
    else{
        node *temp=head;
        node *prev;
        while(temp->next!=NULL)
        {
            prev=temp;
            temp=temp->next;
        }
        node *ptr=temp;
        temp=prev;
        temp->next=NULL;
        free(ptr);
        printf("Node deleted\n");
        count--;
    }

}
void randomdelete()
{
    int pos;
    printf("Enter position(starts from 1 ) :");
    scanf("%d",&pos);
    if(head==NULL || pos>count+1)
    {
        printf("POSITION value is greater than list length\n");
    }
    else if (pos==1)
    {
        deletebegining();
    }
    else if(pos==(count))
    {
        deleteend();
    }
    else{
        node *temp=head;
        int i=1;
        while(i<pos-1)
        {
            temp=temp->next;
            i++;
        }
        node *ptr=temp->next;
        temp->next=ptr->next;
        free(ptr);
        printf("Node deleted\n");
        count--;
}
}

int main() {
    int choice;
    while (1) {
        printf("\n1. Begin Insert\n2. Insert Last\n3. Random Insert\n4. Delete Beginning\n5. Delete End\n6. Random Delete\n7. Display\n8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                begininsert();
                break;
            case 2:
                insertlast();
                break;
            case 3:
                randominsert();
                break;
            case 4:
                deletebegining();
                break;
            case 5:
                deleteend();
                break;
            case 6:
                randomdelete();
                break;
            case 7:
                display();
                break;
            case 8:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a number between 1 and 8.\n");
        }
    }

    return 0;
}