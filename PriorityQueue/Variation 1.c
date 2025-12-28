#include <stdio.h>

#define MAX 20

typedef struct {
    int data[MAX];
    int size;
} PriorityQueue;

void init(PriorityQueue *pq) {
    pq->size = 0;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void enqueue(PriorityQueue *pq, int val) {
    if (pq->size >= MAX) return;
    
    pq->data[pq->size] = val;
    int curr = pq->size;
    pq->size++;

    // Bubble up
    while (curr > 0 && pq->data[curr] > pq->data[(curr - 1) / 2]) {
        swap(&pq->data[curr], &pq->data[(curr - 1) / 2]);
        curr = (curr - 1) / 2;
    }
}

int dequeue(PriorityQueue *pq) {
    if (pq->size == 0) return -1;

    int root = pq->data[0];
    pq->size--;
    pq->data[0] = pq->data[pq->size];

    // Bubble down
    int curr = 0;
    while (curr * 2 + 1 < pq->size) {
        int left = curr * 2 + 1;
        int right = curr * 2 + 2;
        int largest = left;

        if (right < pq->size && pq->data[right] > pq->data[left]) {
            largest = right;
        }
        if (pq->data[curr] >= pq->data[largest]) break;

        swap(&pq->data[curr], &pq->data[largest]);
        curr = largest;
    }
    return root;
}

int main() {
    PriorityQueue pq;
    init(&pq);
    enqueue(&pq, 10);
    enqueue(&pq, 30);
    enqueue(&pq, 20);
    printf("Dequeued: %d\n", dequeue(&pq)); // Should be 30
    printf("Dequeued: %d\n", dequeue(&pq)); // Should be 20
    return 0;
}