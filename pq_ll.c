
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int info;
    int priority;
    struct node *next;
} NODE;

// typedef struct queue {
//     NODE *head;
// } QUEUE;

NODE *head = NULL; // Declare head as a global variable

void enqueue(int ele, int pri){
    NODE *newNode = malloc(sizeof(NODE));
    newNode->info = ele;
    newNode->priority = pri;
    newNode->next = NULL;

    NODE *current = head;
    NODE *prev = NULL;

    while (current != NULL && current->priority < newNode->priority) {
        prev = current;
        current = current->next;
    }

    if (prev == NULL) {  // Insert at the beginning
        newNode->next = head;
        head = newNode;
    } else {  // Insert in the middle or end
        newNode->next = current;
        prev->next = newNode;
    }
}
int dequeue()
{
    if (head == NULL) {
        fprintf(stderr, "Queue is empty\n");
        exit(1);
    }

    NODE *front = head;
    int ele = front->info;
    head = head->next;
    free(front);
    return ele;
}
void destroyQueue()
 {
    while (head != NULL) {
        NODE *front = head;
        head = head->next;
        free(front);
    }
}

int main() {
    enqueue(10, 10);
    enqueue(20, 20);
    enqueue(15, 15);
    enqueue(5, 5);
    enqueue(25, 25);
   //destroyQueue();
    
    int ele = dequeue();
    printf("Dequeued info: %d\n", ele);
    

 
    return 0;
}