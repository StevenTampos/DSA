#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct {
    int items[MAX];
    int count;
} List;

typedef struct {
    List list;
    int front;
    int rear;
} Queue;

Queue* initialize() {
    Queue *Q = (Queue*)malloc(sizeof(Queue));
    Q->list.count = 0;
    Q->front = 0;  // NOTE: PDF Example shows front=0, rear=MAX-1 or similar start logic
    Q->rear = MAX - 1; // Initial state so first enqueue sets rear to 0
    return Q;
}

bool isFull(Queue* q) {
    return (q->list.count == MAX);
}

bool isEmpty(Queue* q) {
    return (q->list.count == 0);
}

void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow\n");
        return;
    }
    
    // Circular increment of rear
    q->rear = (q->rear + 1) % MAX;
    q->list.items[q->rear] = value;
    q->list.count++;
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue Underflow\n");
        return -1;
    }
    
    int removed = q->list.items[q->front];
    // Circular increment of front
    q->front = (q->front + 1) % MAX;
    q->list.count--;
    return removed;
}

int front(Queue *q) {
    if (isEmpty(q)) return -1;
    return q->list.items[q->front];
}

void display(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    int curr = q->front;
    for (int i = 0; i < q->list.count; i++) {
        printf("%d ", q->list.items[curr]);
        curr = (curr + 1) % MAX;
    }
    printf("\n");
}

int main() {
    Queue *Q = initialize();
    enqueue(Q, 10);
    enqueue(Q, 20);
    enqueue(Q, 30);
    display(Q);
    
    printf("Dequeued: %d\n", dequeue(Q));
    display(Q);
    return 0;
}