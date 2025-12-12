#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

Queue* initialize() {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

bool isEmpty(Queue* q) {
    return (q->front == NULL);
}

bool isFull(Queue* q) {
    return false;
}

void enqueue(Queue* q, int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    
    if (isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeue(Queue* q) {
    if (isEmpty(q)) return -1;
    
    Node *temp = q->front;
    int data = temp->data;
    
    q->front = temp->next;
    if (q->front == NULL) {
        q->rear = NULL; // Queue became empty
    }
    
    free(temp);
    return data;
}

int front(Queue* q) {
    if (isEmpty(q)) return -1;
    return q->front->data;
}

void display(Queue* q) {
    printf("Queue: ");
    Node *trav = q->front;
    while(trav != NULL) {
        printf("%d -> ", trav->data);
        trav = trav->next;
    }
    printf("NULL\n");
}

int main() {
    Queue *Q = initialize();
    enqueue(Q, 100);
    enqueue(Q, 200);
    display(Q);
    
    printf("Dequeued: %d\n", dequeue(Q));
    display(Q);
    return 0;
}