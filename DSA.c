//CIRCULAR QUEUE--->>ARRAY IMPLEMENTATION


// #include<stdio.h>
// #define MAX 3
// typedef struct queue
// {
// 	int q[MAX];
// 	int front;
// 	int rear;
// }QUEUE;

// void initQueue(QUEUE *pq);
// int isEmpty(QUEUE *pq);
// int isFull(QUEUE *pq);
// //Precondition: Queue is not full
// void enqueue(QUEUE *pq,int ele);
// //Precondition: Queue is not empty
// int dequeue(QUEUE *pq);
// void display(QUEUE *pq);

// int main()
// {
// 	QUEUE qobj;
// 	initQueue(&qobj);
	
// 	int choice,ele;
	
// 	printf("1.Enqueue 2.Dequeue 3.Display\n");
// 	scanf("%d",&choice);
	
// 	do
// 	{
// 		switch(choice)
// 		{
// 			case 1://if(isFull(&qobj))
// 			// 			printf("Queue is already full\n");
// 			// 		else
// 					{
// 						printf("Enter an integer\n");
// 						scanf("%d",&ele);
// 						enqueue(&qobj,ele);
// 					}
// 					break;
// 			case 2:if(isEmpty(&qobj))
// 					printf("Queue is already empty\n");
// 					else
// 					{
// 						ele=dequeue(&qobj);
// 						printf("Dequed %d\n",ele);
// 					}
// 					break;
// 			case 3:display(&qobj);
// 					break;
// 		}
// 		printf("1.Enqueue 2.Dequeue 3.Display\n");
// 		scanf("%d",&choice);
// 	}while(choice<4);
// }

// void initQueue(QUEUE *pq)
// {
// 	pq->front=-1;
// 	pq->rear=-1;
// }

// int isEmpty(QUEUE *pq)
// {
// 	return pq->front==-1;		//return pq->rear==-1;
// }

// int isFull(QUEUE *pq)
// {
// 	return (pq->rear+1)%MAX == pq->front;
// }

// //Precondition: Queue is not full
// void enqueue(QUEUE *pq,int ele)
// {
// 	if(isEmpty(pq))
// 	{
// 		pq->front=0;
// 		pq->rear=0;
// 		pq->q[0]=ele;	//pq->q[pq->rear]=ele
// 	}
// 	else
// 	{
// 		pq->rear=(pq->rear+1)%MAX;
// 		pq->q[pq->rear]=ele;
// 	}
// }
// //Precondition: Queue is not empty
// int dequeue(QUEUE *pq)
// {
// 	int ele=pq->q[pq->front];
// 	if(pq->front == pq->rear)	//Single element case
// 	{
// 		initQueue(pq);
// 	}
// 	else
// 	{
// 		pq->front=(pq->front+1)%MAX;
// 	}
// 	return ele;
// }
// void display(QUEUE *pq)
// {
// 	if(isEmpty(pq))
// 		printf("Empty Queue\n");
// 	else
// 	{
// 		int i;
// 		for(i=pq->front;i!=pq->rear;i=(i+1)%MAX)
// 			printf("%d ",pq->q[i]);
// 		printf("%d\n",pq->q[i]);
// 	}
// }

//---------------------------------------------------------------------------------------------------------------------------------------------------


//CIRCULAR QUEUE---->>>LINKED LIST IMPLEMENTATION

// #include <stdio.h>
// #include <stdlib.h>

// typedef struct node
// {
//     int info;
//     struct node *next;
// } NODE;

// NODE *front = NULL; // Global front pointer
// NODE *rear = NULL;  // Global rear pointer

// void initQueue();
// int isEmpty();
// void enqueue(int ele);
// // Precondition: queue is not empty
// int dequeue();
// void display();
// void destroyQueue();

// int main()
// {
//     initQueue();

//     int choice, ele;

//     printf("1.Enqueue 2.Dequeue 3.display\n");
//     scanf("%d", &choice);

//     do
//     {
//         switch (choice)
//         {
//         case 1:
//             printf("Enter an integer\n");
//             scanf("%d", &ele);
//             enqueue(ele);
//             break;
//         case 2:
//             if (isEmpty())
//                 printf("Queue is already empty\n");
//             else
//             {
//                 ele = dequeue();
//                 printf("Dequeued %d\n", ele);
//             }
//             break;
//         case 3:
//             display();
//             break;
//         case 4:
//             destroyQueue();
//         }
//         printf("1.Enqueue 2.Dequeue 3.display 4.Destroy\n");
//         scanf("%d", &choice);
//     } while (choice < 4);
//     destroyQueue();
// }

// void initQueue()
// {
//     front = NULL;
//     rear = NULL;
// }

// int isEmpty()
// {
//     return front == NULL; // return rear == NULL
// }

// void enqueue(int ele)
// {
//     NODE *newNode = malloc(sizeof(NODE));
//     newNode->info = ele;

//     if (isEmpty())
//     {
//         newNode->next = newNode;
//         front = newNode;
//         rear = newNode;
//     }
//     else
//     {
//         rear->next = newNode;
//         rear = newNode; 
//         rear->next=front;
//     }
// }
// // Precondition: queue is not empty
// int dequeue()
// {
//     int ele = front->info;
//     if (front == rear) // Single node case//if(front->next==NULL)
//     {
//         free(front);
//         front = NULL;
//         rear = NULL;
//     }
//     else
//     {
//         NODE *p = front;
//         front = front->next;
//         rear->next=front;
//         free(p);
//     }
//     return ele;
// }

// void display()
// {
//     if (front == NULL) // rear == NULL
//         printf("Empty Queue\n");
//     else
//     {
//         NODE *p = front;

//         while (p->next != front)
//         {
//             printf("%d ", p->info);
//             p = p->next;
        
//         }
//         printf("\n");
//     }
// }

// void destroyQueue()
// {
//     NODE *p = front;

//     while (front != rear)
//     {
//         front = front->next;
//         printf("%d freed\n", p->info);
//         free(p);
//         p = front;
//     }
//     printf("%d freed\n", p->info);
//     free(p);
//     front = NULL;
//     rear = NULL;
// }



// #include<stdio.h>
// #define MAX 5
// typedef struct queue
// {
// 	int q[MAX];
// 	int front;
// 	int rear;
// }QUEUE;

// void initQueue(QUEUE *pq);
// int isEmpty(QUEUE *pq);
// int isFull(QUEUE *pq);
// //Precondition: Queue is not full
// void enqueRear(QUEUE *pq,int ele);
// //Precondition: Queue is not empty
// int dequeueFront(QUEUE *pq);
// void display(QUEUE *pq);
// //Precondition: Queue is not full
// void enqueFront(QUEUE *pq,int ele);
// //Precondition: Queue is not empty
// int dequeueRear(QUEUE *pq);

// int main()
// {
// 	QUEUE qobj;
// 	initQueue(&qobj);
	
// 	int choice,ele;
	
// 	printf("1.EnqRear 2.DeqFront 3.Display 4.EnqFront 5.DeqRear\n");
// 	scanf("%d",&choice);
	
// 	do
// 	{
// 		switch(choice)
// 		{
// 			case 1:if(isFull(&qobj))
// 						printf("Queue is already full\n");
// 					else
// 					{
// 						printf("Enter an integer\n");
// 						scanf("%d",&ele);
// 						enqueRear(&qobj,ele);
// 					}
// 					break;
// 			case 2:if(isEmpty(&qobj))
// 					printf("Queue is already empty\n");
// 					else
// 					{
// 						ele=dequeueFront(&qobj);
// 						printf("Dequed %d\n",ele);
// 					}
// 					break;
// 			case 3:display(&qobj);
// 					break;
// 			case 4://if(isFull(&qobj))
// 			// 			printf("Queue is already full\n");
// 					//else
// 					{
// 						printf("Enter an integer\n");
// 						scanf("%d",&ele);
// 						enqueFront(&qobj,ele);
// 					}
// 					break;
// 			case 5:if(isEmpty(&qobj))
// 					printf("Queue is already empty\n");
// 					else
// 					{
// 						ele=dequeueRear(&qobj);
// 						printf("Dequed %d\n",ele);
// 					}
// 					break;
// 		}
// 		printf("1.EnqRear 2.DeqFront 3.Display 4.EnqFront 5.DeqRear\n");
// 		scanf("%d",&choice);
// 	}while(choice<6);
// }

// void initQueue(QUEUE *pq)
// {
// 	pq->front=-1;
// 	pq->rear=-1;
// }

// int isEmpty(QUEUE *pq)
// {
// 	return pq->front==-1;		//return pq->rear==-1;
// }

// int isFull(QUEUE *pq)
// {
// 	return (pq->rear+1)%MAX == pq->front;
// }

// //Precondition: Queue is not full
// void enqueRear(QUEUE *pq,int ele)
// {
// 	if(isEmpty(pq))
// 	{
// 		pq->front=0;
// 		pq->rear=0;
// 		pq->q[0]=ele;	//pq->q[pq->rear]=ele
// 	}
// 	else
// 	{
// 		pq->rear=(pq->rear+1)%MAX;
// 		pq->q[pq->rear]=ele;
// 	}
// }
// //Precondition: Queue is not empty
// int dequeueFront(QUEUE *pq)
// {
// 	int ele=pq->q[pq->front];
// 	if(pq->front == pq->rear)	//Single element case
// 	{
// 		initQueue(pq);
// 	}
// 	else
// 	{
// 		pq->front=(pq->front+1)%MAX;
// 	}
// 	return ele;
// }
// void display(QUEUE *pq)
// {
// 	if(isEmpty(pq))
// 		printf("Empty Queue\n");
// 	else
// 	{
// 		int i;
// 		for(i=pq->front;i!=pq->rear;i=(i+1)%MAX)
// 			printf("%d ",pq->q[i]);
// 		printf("%d\n",pq->q[i]);
// 	}
// }

// //Precondition: Queue is not full
// void enqueFront(QUEUE *pq,int ele)
// {
// 	if(isEmpty(pq))
// 	{
// 		pq->front=0;
// 		pq->rear=0;
// 		pq->q[0]=ele;
// 	}
// 	else
// 	{
// 		pq->front=(pq->front-1+MAX)%MAX;
// 		pq->q[pq->front]=ele;
// 	}
// }
// //Precondition: Queue is not empty
// int dequeueRear(QUEUE *pq)
// {
// 	int ele=pq->q[pq->rear];
// 	if(pq->front==pq->rear)
// 	{
// 		initQueue(pq);
// 	}
// 	else
// 	{
// 		pq->rear=(pq->rear-1+MAX)%MAX;
// 	}
// 	return ele;
// }


//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


//The parental node keys will be in the first (floor(n/2)) positions of the array while the leaf keys will occupy the last (roof(n/2)) positions
//The children of a key in the array's parental position i()
// 
// 

//--------------------------------------------------------------------------------------------------------------------------------------------------
//Implementation of DESCENDING heap and heap sort

// #include<stdio.h>
// #include<stdlib.h>
// #define MAX 50
// int main()
// {
//     int a[MAX];
//     int i,c,p,n,elt;
//     printf ("Enter the number of elements");
//     scanf("%d",&n);
//     printf("Enter the elements: ");
//     for(i=0;i<n;i++)
//     {
//         scanf("%d",&a[i]);
//     }
//     //heapify
//     for(i=1;i<n;i++)
//     {
//          elt= a[i];
//         c=i;
//         p=(c-1)/2;
//         while(c>0 && a[p]<elt)
//         {
//             a[c]=a[p];
//             c=p;
//             p=(c-1)/2;
//         }
//         a[c]=elt;
//     }

//     //display
//     for(i=0;i<n;i++)
//     {
//         printf("%d\t",a[i]);
//     }

//     //heap sort
//     for(i=n-1;i>0;i--)
//     {
//         elt =a[i];
//         a[i]=a[0];
//         p=0;
//         if(i==1)
//            c=-1;
//         else
//             c=1;
//         if(i>2 && a[2]>a[1])
//         c=2;
//         while(c>=0 && elt<a[c])
//         {
//             a[p]=a[c];
//             p=c;
//             c=2*p+1;
//             if(c+1<=i-1 && a[c]<a[c+1])
//             c=c+1;
//             if(c>i-1)
//             c=-1;
//         }
//         a[p]=elt;
// }
//  printf("\nElements after Heap sort are\n :");
//         for(i=0;i<n;i++)
//     {
//         printf("%d\t",a[i]);
//     }

//     }

//----------------------------------------------------------------------------------------------------------------------------------------

// //Implementation of priority queue using heap

// #include<stdio.h>
// #define MAX 50
// typedef struct NODE
// {
//     int pq[MAX];
//     int n;
// }Node;

// void init( Node *pq)
// {
//     pq->n=0;
// }
// void display( Node *pt)
// {
//     int i=0;
//     for(i=0;i<pt->n;i++)
//     printf("%d\t",pt->pq[i]);
// }

// int enqueue(Node *pt,int e)
// {
//     int p,c;
//     if(pt->n==MAX-1)
//     return 0;
//     pt->pq[pt->n]=e;
//     c=pt->n;
//     p=(c-1)/2;
//     while(c >0 && pt->pq[p]<e)
//     {
//         pt->pq[c]=pt->pq[p];
//         c=p;
//         p=(c-1)/2;
//     }
//     pt->pq[c]=e;
//     pt->n=pt->n+1;
//     return 1;
// }

// int dequeue(Node *pt,int *ele)
// {
//     int p,c;
//     *ele=pt->pq[0];
//     int elt =pt->pq[pt->n-1];
//     p=0;
//     if(pt->n==1)
//     c=-1;
//     else 
//     c=1;
//     if(pt->n<2 && pt->pq[2]>pt->pq[1])
//         c=c+1;  

// }
 
// int main()
// {
//     Node pobj;
//     int choice,ele;
//     init(&pobj);
//     do{
//     printf("1.Enqueue 2.Dequeue 3.Display\n");
//     scanf("%d",&choice);
//     switch(choice)
//     {
//         case 1:printf("Enter the information");
//                 scanf("%d",ele);
//                 enqueue(&pobj,ele);
//                 break;
//         case 2:int k=dequeue(&pobj,&ele);
//                 printf("Dequeued element is %d",k);
//                 break;
//         case 3:
//                     }


// }while(choice<4);
// }
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------


//BINARY EXPRESSION TREE

// #include<stdio.h>
// #include<stdlib.h>
// #include<ctype.h>

// struct node
// {
// 	char data;
// 	struct node *left;
// 	struct node *right;
// };
// int eval(struct node *t);
// struct node *pop(struct node **stk, int *t);
// struct node* create(char *expr);
// void push(struct node **stk, int *t, struct node *temp);
// int isoper(char ch);
// void postorder(struct node *t);
// void inorder(struct node *t);
// void preorder(struct node *t);

// int main()
// {
// 	struct node *root;
// 	root=NULL;

// 	char expr[100];
// 	printf("Enter the postfix expr\n");
// 	scanf("%s", expr);
	
// 	root=create(expr);

// 	printf("\nPrefix expr is - Pre order...\n");
// 	preorder(root);

// 	printf("\nInfix expr is - In Order...\n");
// 	inorder(root);
	
// 	printf("\npostfix expr is - Post order..\n");
// 	postorder(root);

// 	int result=eval(root);
// 	printf("\nAfter eval, result is..%d\n", result);
// 	return 0;
// }

// int eval(struct node *t) {
//     if (isdigit(t->data)) {
//         return t->data - '0'; // Convert char to integer value
//     }

//     int left = eval(t->left);
//     int right = eval(t->right);

//     switch(t->data) { 
//         case '+' : return left + right;
//         case '-' : return left - right;
//         case '*' : return left * right;
//         case '/' : 
//             if (right != 0) {
//                 return left / right;
//             } else {
//                 printf("\nError: Division by zero\n");
//                 exit(EXIT_FAILURE);
//             }
//         default  : 
//             printf("\nUnknown operator encountered: %c\n", t->data);
//             exit(EXIT_FAILURE); // Exit the program for unknown operators
//     }
// }


// void preorder(struct node *t)
// {
// 	if(t!=NULL)
// 	{
// 		printf("%c ",t->data);
// 		preorder(t->left);
// 		preorder(t->right);
// 	}
// }
// void inorder(struct node *t)
// {
// 	if(t!=NULL)
// 	{
		
// 		inorder(t->left);
// 		printf("%c ",t->data);
// 		inorder(t->right);
// 	}
// }
// void postorder(struct node *t)
// {
// 	if(t!=NULL)
// 	{
		
// 		postorder(t->left);
// 		postorder(t->right);
// 		printf("%c ",t->data);
// 	}
// }
// struct node* create(char *expr)
// {
// 	struct node *temp;
// 	struct node *stk[100];
// 	int top=-1;
// 	int i=0;
// 	char ch;
// 	while(expr[i]!='\0')
// 	{
// 		ch=expr[i];
// 		temp=(struct node*)malloc(sizeof(struct node));
// 		temp->data=ch;
// 		temp->left=temp->right=NULL;

// 		if(isoper(ch))
// 		{
// 			temp->right=pop(stk,&top);
// 			temp->left=pop(stk,&top);
// 			push(stk,&top,temp);
// 		}
// 		else
// 		push(stk,&top,temp);
// 		i++;
// 	}
// 	return pop(stk,&top);
// }
// void push(struct node **stk, int *t, struct node *temp)
// {
// 	++*t;
// 	stk[*t]=temp;
// }
// struct node *pop(struct node **stk, int *t)
// {
// 	struct node *x;
// 	x=stk[*t];
// 	--*t;
// 	return x;
// }

// int isoper(char ch)
// {
// 	switch(ch)
// 	{
// 		case '+':
// 		case '-':
// 		case '*':
// 		case '/': return 1;
// 		default : return 0;
		
// 	}
// }

//------------------------------------------------------------------------------------------------------------------------------------

//THREADED BINARY TREE

// #include<stdio.h>
// #include<stdlib.h>
// #include<stdbool.h>

// struct node
// {
//     int data;
//     struct node *left;
//     struct node *right;
//     bool lthread;
//     bool rthread;
// };

// struct node* insert(struct node *t, int x);
// struct node *succ(struct node *t);
// void inorder(struct node *t);

// int main()
// {
//     struct node *root;
//     int ch, x;
//     root = NULL;

//     while(1)
//     {
//         printf("\n1:Insert\n2:Inorder traversal\n");
//         printf("Enter your choice\n");
//         scanf("%d", &ch);

//         switch(ch)
//         {
//             case 1:
//                 printf("Enter the num\n");
//                 scanf("%d", &x);
//                 root = insert(root, x);
//                 break;
//             case 2:
//                 printf("INORDER TRAVERSAL..\n");
//                 inorder(root);
//                 break;
//         }
//     }

//     return 0;
// }

// void inorder(struct node *t)
// {
//     struct node *cur;
//     cur = t;

//     if (t == NULL)
//     {
//         printf("EMPTY..\n");
//         return;
//     }

//     while (cur->lthread == false)
//     {
//         cur = cur->left;
//     }

//     while (cur != NULL)
//     {
//         printf("%d ", cur->data);

//         if (cur->rthread == true)
//         {
//             cur = cur->right;
//         }
//         else
//         {
//             cur = succ(cur);
//         }
//     }
// }

// struct node *succ(struct node *t)
// {
//     if (t->rthread == true)
//     {
//         return t->right;
//     }

//     t = t->right;
//     while (t->lthread == false)
//     {
//         t = t->left;
//     }

//     return t;
// }

// struct node* insert(struct node *t, int x)
// {
//     struct node *temp, *cur;
//     cur = t;
//     temp = (struct node*)malloc(sizeof(struct node));
//     temp->data = x;
//     temp->left = temp->right = NULL;
//     temp->lthread = temp->rthread = true;

//     if (t == NULL)
//     {
//         return temp;
//     }

//     while (1)
//     {
//         if (x < cur->data)
//         {
//             if (cur->lthread == false)
//             {
//                 cur = cur->left;
//             }
//             else
//             {
//                 temp->left = cur->left;
//                 temp->right = cur;
//                 cur->left = temp;
//                 cur->lthread = false;
//                 break;
//             }
//         }
//         else
//         {
//             if (cur->rthread == false)
//             {
//                 cur = cur->right;
//             }
//             else
//             {
//                 temp->right = cur->right;
//                 temp->left = cur;
//                 cur->right = temp;
//                 cur->rthread = false;
//                 break;
//             }
//         }
//     }

//     return t;
//}

//--------------------------------------------------------------------------------------------------

//PRIORITY QUEUE
// 



//HASHING - SEPERATE CHAINING

// #include<stdio.h>
// #include<stdlib.h>
// #include<string.h>
// struct node
// {
// 	int key;
// 	char name[100];
// 	struct node *next;
// };
// struct hash
// {
// 	struct node *head;
// 	int count;
// };
// void delete(struct hash *ht, int sz, int key);
// void insert(struct hash *ht, int sz, int key, char *name);
// void display(struct hash *ht, int sz);
// int main()
// {
// 	struct hash *ht;
// 	int tablesz,i,ch,key;
// 	char name[100];

// 	printf("Enter the size of the hash table..\n");
// 	scanf("%d",&tablesz);
// 	ht=(struct hash*)malloc(tablesz * sizeof(struct hash));
// 	for(i=0;i<tablesz;i++)
// 	{
// 		ht[i].head=NULL;
// 		ht[i].count=0;
// 	}
// 	while(1)
// 	{
// 		display(ht,tablesz);
// 		printf("\n1:insert\n2:delete\n");
// 		scanf("%d",&ch);
// 		switch(ch)
// 		{
// 			case 1:printf("enter the key\n");
// 				scanf("%d",&key);
// 				printf("Enter the name\n");
// 				scanf("%s",name);
// 				insert(ht,tablesz,key,name);
// 				break;
// 			case 2:printf("enter the key for deletion\n");
// 				scanf("%d",&key);
				
// 				delete(ht,tablesz,key);
// 				break;
// 		}
// 	}
// }
// void delete(struct hash *ht, int sz, int key)
// {
// 	struct node *prev, *temp;
// 	int index;

// 	index=key %sz;

// 	prev=NULL;
// 	temp=ht[index].head;
	
// 	while(temp!=NULL && temp->key != key)
// 	{
// 		prev=temp;
// 		temp=temp->next;
// 	}
// 	if(temp==NULL)
// 	{
// 		printf("Nor found..\n");

// 	}
// 	else
// 	{
// 		if(prev==NULL)
// 		{
// 			ht[index].head=temp->next;
// 		}
// 		else
// 		{
// 			prev->next=temp->next;
// 		}
// 		free(temp);
// 		ht[index].count--;
// 	}
// }
// void insert(struct hash *ht, int sz, int key, char *name)
// {
// 	struct node *temp;
// 	int index;
// 	temp=(struct node*)malloc(sizeof(struct node));
// 	temp->key=key;
// 	strcpy(temp->name,name);
// 	temp->next=NULL;
// 	index=key%sz;
// 	temp->next=ht[index].head;
// 	ht[index].head=temp;
// 	ht[index].count++;
// }
	
// void display(struct hash *ht, int sz)
// {
// 	int i;
// 	struct node *temp;
// 	printf("\n");
// 	for(i=0;i<sz;i++)
// 	{
// 		printf("%d :",i);
// 		if(ht[i].head!=NULL)
// 		{
// 		temp=ht[i].head;
// 		while(temp!=NULL)
// 		{
// 			printf("%d : ",temp->key);
// 			printf("%s ->",temp->name);
// 			temp=temp->next;
// 		}
// 		}
// 	printf("\n");
// 	}
	
// }

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct element
{
	int key;
	char name[100];
	int mark;
};
void display(struct element *ht, int size);
 void insert(struct element *ht, int sz, int key, char *name, int *count);
  void delete(struct element *ht, int sz, int key, int *count);

int main()
{
  struct element *ht;
  int i,n,ch,key,no_elements;
  char name[100];
  int tablesz;
  printf("Enter the table size..");
  scanf("%d",&tablesz);
  //create hash table
  ht=(struct element*)malloc(tablesz* sizeof(struct element));
   for(i=0;i<tablesz;i++)
     ht[i].mark=0;
   no_elements=0;
  
  while(1)
  {
    display(ht,tablesz);
    printf("\n1. Insert..");
    printf("\n2. Delete..");
    printf("\n3. Search..");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1: printf("Enter key..\n");
              scanf("%d",&key);
              printf("Enter name..\n");
              scanf("%s",name);
              insert(ht,tablesz,key,name,&no_elements);
              break;
       case 2: printf("Enter the key for deletion..\n");
               scanf("%d",&key);
               delete(ht,tablesz,key,&no_elements);
               break;
    
    }
  }
 
}// Renamed the delete function to delete_key
void delete_key(struct element *ht, int sz, int key, int *count) {
    int index, i, j = 1;
    if (*count == 0) {
        printf("Empty..\n");
        return;
    }
    index = key % sz;
    i = index;
    while (ht[index].key != key && j < sz) {
        index = (i + (j * j)) % sz;
        j++;
    }

    if (ht[index].key == key) {
        ht[index].mark = 0;
        (*count)--;
    } else {
        printf("Not found..\n");
    }
    return;
}

  void display(struct element *ht, int size)
  {
    int i;
    for(i=0;i<size;i++)
    {
      printf("%d :", i);
      if (ht[i].mark!=0)
         printf("Key = %d, name = %s",ht[i].key,ht[i].name);
      printf("\n");
    }
  }  
void delete(struct element *ht, int sz, int key, int *count)
{
	int index,i,j=1;
	if(*count==0)
	{
		printf("Empty..\n");
		return;
	}
	index=key%sz;
    i=index;
	while(ht[index].key!=key&&j<sz)
	{
		index=(i+(j*j))%sz;
		j++;
	}

	if(ht[index].key==key)
	{
		ht[index].mark=0;
		(*count)--;
	}
	else
	printf("Not found..\n");
	return;
}