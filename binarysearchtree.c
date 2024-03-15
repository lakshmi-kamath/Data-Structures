// Binary Search tree with inorder,preorder,postorder and non recursive inorder traversals which removes duplicate elements in the tree

#include<stdio.h>
#include<stdlib.h>
#define MAX 1000

typedef struct Node{
    struct Node *left;
    struct Node *right;
    int info;
}Node;

typedef struct stack{
    Node* value[MAX];
    int top;
    }Stack;
Node* maketree(int x)
{
    Node *root=(Node*)malloc(sizeof(Node));
    if(root==NULL)
    {
        return NULL;
    }
    root->info=x;
    root->left=NULL;
    root->right=NULL;
    return(root);
}

void setleft(Node *p,int x)
{
    if(p==NULL || p->left!=NULL)
    {
        printf("Insertion not Possible \n");
        return;
    }
    else{
        p->left=maketree(x);
    }
}
void setright(Node *p,int x)
{
    if(p==NULL || p->right!=NULL)
    {
        printf("Insertion not Possible \n");
        return;
    }
    else{
        p->right=maketree(x);
    }
}

void inorder(Node *p)
{
    if(p==NULL)
    {
        return;
    }
    inorder(p->left);
    printf("%d\t",p->info);
    inorder(p->right);
}
void inordertraversal(Node *p)
{
    printf("\n Inorder Traversal :\n ");
    if(p==NULL)
    {
        printf("Tree is empty\n");
        return;
    }
    else
    inorder(p);
}

void preorder(Node *p)
{
    if(p==NULL)
    {
        return;
    }
    printf("%d\t",p->info);
    preorder(p->left);
    preorder(p->right);
}
void preordertraversal(Node *p)
{
    printf("\n Preorder Traversal :\n ");
    if(p==NULL)
    {
        printf("Tree is empty\n");
        return;
    }
    else
    preorder(p);
}
void postorder(Node *p)
{
    if(p==NULL)
    {
        return;
    }
    postorder(p->left);
    postorder(p->right);
    printf("%d\t",p->info);
}
void postordertraversal(Node *p)
{
    printf("\n Postorder Traversal :\n ");
    if(p==NULL)
    {
        printf("Tree is empty\n");
        return;
    }
    else
    postorder(p);
}

void insertnode(Node *p, int n)
{
    if(n<p->info)
    {
        if(p->left==NULL)
        {
            setleft(p,n);
            
        }
        else{
            insertnode(p->left,n);
        }
    }
    else if(n>p->info)
    {
        if(p->right==NULL)
        {
            setright(p,n);
            
        }
        else{
            insertnode(p->right,n);
        }
    }
    else
    {
        return ;
    }
       return ;
}
void initStack(Stack* s) {
    s->top = -1;
}

int push(Node* n, Stack* s) {
    if (s->top == MAX - 1)
        return 0;
    s->top++;
    s->value[s->top] = n;
    return 1;
}

Node* pop(Stack* s) {
    if (s->top == -1)
        return NULL;
    Node* temp = s->value[s->top];
    s->top--;
    return temp;
}

int empty(Stack* s) {
    return (s->top == -1);
}

void nonrecursiveInorder(Node* root) {
    Node* p = root;
    Stack s;
    initStack(&s);

    printf("Non-recursive inorder traversal:\n");
    
    do {
        while (p != NULL) {
            push(p, &s);
            p = p->left;
        }
        
        if (!empty(&s)) {
            p = pop(&s);
            printf("%d\t", p->info);
            p = p->right;
        }
    } while (!empty(&s) || p != NULL);
}

int main()
{
    int n;
    printf("Enter the number of elements in the tree:\t");
    scanf("%d",&n);
    int arr[n];
    printf("Enter %d integers for the tree: \t",n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    Node *root=maketree(arr[0]);
    int i=1;
    int j=0;
    int array[n];
    int x;
    while(i<n)
    {
    insertnode(root,arr[i]);
    i++;
    }
    inordertraversal(root);
    printf("\n\n");
    preordertraversal(root);
    printf("\n\n");
    postordertraversal(root);
    printf("\n\n");
    nonrecursiveInorder(root);
    return 0;
}