#include<stdlib.h>
#include<stdio.h>
typedef struct node{
    int info;
    struct node *left;
    struct node *right;
    int rthread;
}Node;

Node* getnode()
{
    Node *p=(Node *)malloc(sizeof(Node));
    return p;
}

Node* maketree(int x)
{
    Node *p=getnode();
    p->info=x;
    p->left=NULL;
    p->right=NULL;
    p->rthread=1;
    return p;
}

void non_recursive_traversal(Node *ptr)
{
    Node *p=ptr;
    Node *q;
    do{
        q=NULL;
        while(p!=NULL)
        {
            q=p;
            p=p->left;
        }
        if(q!=NULL)
        {
            printf("%d\t",q->info);
            p=q->right;
            while(q->rthread && p!=NULL)
            {
                printf("%d\t",p->info);
                q=p;
                p=p->right;
            }
        }
    }while(q!=NULL);
}

void setleft(Node *p, int x) {
    Node *q;
    if (p == NULL) {
        printf("Failed Execution\n");
        return;
    } else if (p->left != NULL) {
        return;
    }
    else
    {
        q=maketree(x);
        p->left =q;
        q->right=p;
        q->rthread=1;
    }
}

void setright(Node *p, int x) {
    if (p == NULL) {
        printf("Invalid execution\n");
        return;
    } else if (!p->rthread) {
        printf("Invalid execution\n");
        return;
    }
    Node *q,*r;
    q=maketree(x);
    r=p->right;
    p->right=q;
    p->rthread=1;
    q->right=r;
}

void insertnode(Node *p, int n) {
    if (n < p->info) {
        if (p->left == NULL) {
            setleft(p, n);
        } else {
            insertnode(p->left, n);
        }
    } else if (n > p->info) {
        if (p->rthread || p->right == NULL) {
            setright(p, n);
        } else {
            insertnode(p->right, n);
        }
    } else {
        return;
    }
}

int main() {
    int n;
    printf("Enter the number of elements in the tree:\t");
    scanf("%d", &n);
    
    int arr[n];
    
    printf("Enter %d integers for the tree: \t", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    Node *root = maketree(arr[0]);

    for (int i = 1; i < n; i++) {
        insertnode(root, arr[i]);
    }

    printf("\n\nNon recursive traversal:\n");
    non_recursive_traversal(root);

    return 0;
}
