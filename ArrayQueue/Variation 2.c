#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct {
    int items[MAX];
    int front;
    int rear;
} Queue;

Queue* initialize() {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    // Guide specific initialization:
    q->front = 1;
    q->rear = 0;
    return q;
}

bool isEmpty(Queue* q) {
    return (q->front == (q->rear + 1) % MAX);
}

bool isFull(Queue* q) {
    return (q->front == (q->rear + 2) % MAX);
}

void enqueue(Queue* q, int value) {
    if(isFull(q)) {
        printf("Queue Overflow\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX;
    q->items[q->rear] = value;
}

int dequeue(Queue* q) {
    if(isEmpty(q)) {
        printf("Queue Underflow\n");
        return -1;
    }
    int value = q->items[q->front];
    q->front = (q->front + 1) % MAX;
    return value;
}

int front(Queue* q) {
    if(isEmpty(q)) return -1;
    return q->items[q->front];
}

void display(Queue* q) {
    if(isEmpty(q)) {
        printf("Queue Empty\n");
        return;
    }
    printf("Queue: ");
    int curr = q->front;
    // Iterate circularly until we hit the position after rear
    while (curr != (q->rear + 1) % MAX) {
        printf("%d ", q->items[curr]);
        curr = (curr + 1) % MAX;
    }
    printf("\n");
}

int main() {
    Queue *Q = initialize();
    enqueue(Q, 5);
    enqueue(Q, 10);
    enqueue(Q, 15);
    display(Q);
    
    printf("Dequeued: %d\n", dequeue(Q));
    display(Q);
    return 0;
}