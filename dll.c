#include<stdio.h>
#include<stdlib.h>
typedef struct doubly_linked_list
{
    int data;
    struct doubly_linked_list *llink;
    struct doubly_linked_list *rlink;

}node;

node *head= NULL;
static int count=0;
void insert_begining()
{
    int item;
    node *ptr=(node *)malloc(sizeof(node));
    if(ptr == NULL)
    {
        printf("Error");
    }
    else{
        printf("Enter value of first node");
        scanf("%d",&item);
        ptr->data=item;
        ptr->llink=NULL;
        if(head== NULL)
        {
            ptr->rlink=NULL;
            printf("\nNode inserted at begining\n");
            count++;
        }
        else{
            ptr->rlink=head;
            head->llink=ptr;
        
        
            printf("\n Node inserted at begining\n");
            count++;
        }
        head=ptr;
        

    }

}
void display()
 {
    node *temp;
    temp=head;
    if(temp==NULL)
    {
        printf("No data found");
        return;
    }
    while(temp!= NULL)
    {
        printf("%d \t",temp->data);
        temp=temp->rlink;
    }
    printf("\n");
 }

void insert_last()
{
    node *ptr,*temp;
    int item;
    ptr=(node * )malloc(sizeof(node));
    if(ptr==NULL)
    {
        printf("Error");
    }
    else
    {
        printf("Enter the value of last node");
        scanf("%d",&item);
        ptr->rlink=NULL;
         if(head== NULL)
         {
             ptr->data=item;
             ptr->llink=NULL;
             
             head=ptr;
             printf("\nNode inserted at end\n");
             count++;
         }
        else 
        {
            temp=head;
            while(temp->rlink!=NULL)
            {
                temp=temp->rlink;
            }

        
        ptr->data=item;
        ptr->llink=temp;
        temp->rlink = ptr;
        printf("\nNode inserted at end \n");
        count++;

    }

    }

}
void random_insert(int ele , int pos)
{
    node *ptr;
    ptr=(node * )malloc(sizeof(node));
    if (ptr==NULL)
    {
        printf("Error");
    }
    else if(pos> count)
    {
        printf("Position exceeds the length of linked list use insert_last function\n\n");
    }
    else
    {
    ptr->data=ele;
     ptr->llink=NULL;
     ptr->rlink=NULL;
    if(head==NULL)
    {
        head = ptr;
    }
    else if(pos==1)
    {
        ptr->rlink=head;
        head->llink=ptr;
        head=ptr;
    }
    else
    {
    node *temp=head;
    while(pos>1)
    {
        temp=temp->rlink;
        pos--;
    }
    ptr->llink=temp->llink;
    if(temp->llink !=NULL)
    {
    temp->llink->rlink=ptr;
    }
    ptr->rlink=temp;
    temp->llink =ptr;
    
    }
    printf("Node inserted at position %d\n",pos);
    count++;
    }
}

void delete_begining()
{
    node *ptr;
    ptr=head;
    if(head->rlink==NULL)
    {
        free(ptr);
        head=NULL;
        printf("First Node deleted\n");
    }
    else
    {
    head=head->rlink;
    head->llink=NULL;
    free(ptr);
    printf("First Node deleted\n");
    }
    count--;
}

void delete_end()
{
    node *ptr;
    ptr=head;
    if(head->rlink ==NULL)
    {
        free(ptr);
        head=NULL;
        printf("Last Node deleted\n");
    }
    else
    {
        while(ptr->rlink!=NULL)
        {
            ptr=ptr->rlink;
        }
        ptr->llink->rlink=NULL;
        free(ptr);
        printf("Last Node deleted\n");
    }
}
void random_delete(int pos)
{
    if(head==NULL)
    {
        printf("Underflow");
    }
    else if(pos==1)
    {
        delete_begining();
    }
    else if(pos==count)
    {
        delete_end();
    }
    else
    {
        int i=1;
        node *ptr=head;
        while(i<pos-1)
        {
            ptr=ptr->rlink;
            i++;
        }
        node *temp=ptr->rlink;
        ptr->rlink=temp->rlink;
        temp->rlink->llink=ptr;
        free(temp);
        printf("Node deleted\n");
        count--;
    }
}
int main()
 {
    insert_last();
    insert_last();
    random_insert(88,1);
    insert_last();
    insert_begining();
    insert_begining();
    insert_begining();
    random_insert(22,2);
    random_delete(2);
    insert_begining();
    random_insert(22,1);
    delete_end();
    
    display();
    return 0;
 }