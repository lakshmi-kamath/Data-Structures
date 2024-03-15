#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 50

typedef struct Node{
    struct Node *left;
    struct Node *right;
    char info;
}Node;

typedef struct stack
{
    int top;
    Node* value[MAX];
}Stack;

void init_stack(Stack* s)
{
    s->top=-1;
}

typedef struct tree{
    Node *root;
}Tree;

void init_tree(Tree *root)
{
    root->root=NULL;
}
int push(Node *n,Stack *s)
{
    if(s->top==MAX-1)
    return 0;
    s->top++;
    s->value[s->top]=n;
    return 1;
}

Node* pop(Stack *s)
{
    if(s->top==-1)
    return 0;
    Node *temp = s->value[s->top];
    s->top--;
    return temp;
}

float eval(Node *r)
{
    //float result;
    switch(r->info)
    {
        case '+': return(eval(r->left)+eval(r->right));
                  break;
        case '*': return(eval(r->left)*eval(r->right));
                  break;
        case '-': return(eval(r->left)-eval(r->right));
                  break;
        case '/': return(eval(r->left)/eval(r->right));
                  break;
        default:return(r->info-'0');
    }
}

float evaltree(Tree *root)
{
    return eval(root->root);
}
void inorder(Node *p)
{
    if(p==NULL)
    {
        return;
    }
    inorder(p->left);
    printf("%c\t",p->info);
    inorder(p->right);
}
void inordertraversal(Tree *p)
{
    printf("\n Inorder Traversal :\n ");
    if(p==NULL)
    {
        printf("Tree is empty\n");
        return;
    }
    else
    inorder(p->root);
}
int main()
{
    char postfix[MAX];
    Stack obj;
    Tree root;
    Node *temp;
    init_stack(&obj);
    init_tree(&root);
    printf("Enter the Postfix expression : ");
    scanf("%s",postfix);
    int i=0,len=strlen(postfix);
    while(i<len)
    {
        temp = (Node*)malloc(sizeof(Node));
        temp->info=postfix[i];
        temp->left=temp->right=NULL;
        if(isdigit(postfix[i]))
        {
            push(temp,&obj);
        }
        else{
            temp->right=pop(&obj);
            temp->left=pop(&obj);
            push(temp,&obj);
        }
        i++;
    }
    root.root=pop(&obj);
    float res=evaltree(&root);
    printf("Value of expression is : %f",res);
    inordertraversal(&root);
    return 0;

}