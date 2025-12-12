#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct {
    Node* front; // Points to the LAST node (Tail)
    Node* rear;  // Points to the FIRST node (Head)
} Queue;

Queue* initialize() {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

bool isEmpty(Queue* q) {
    return (q->rear == NULL); // Use rear (head) to check empty easily
}

// Insert at Rear (which is the HEAD of the list in this variation)
void enqueue(Queue* q, int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = q->rear; // New node points to current head
    
    q->rear = newNode; // Update Rear to new head
    
    // If list was empty, Front must also point to this new node
    if (q->front == NULL) {
        q->front = newNode;
    }
}

// Remove from Front (which is the TAIL of the list in this variation)
int dequeue(Queue* q) {
    if (isEmpty(q)) return -1;
    
    int data;
    
    // Case 1: Only one node
    if (q->rear == q->front) {
        data = q->front->data;
        free(q->front);
        q->front = NULL;
        q->rear = NULL;
    } 
    // Case 2: More than one node
    else {
        // We must traverse to find the node BEFORE front
        Node *trav = q->rear;
        while (trav->next != q->front) {
            trav = trav->next;
        }
        
        data = q->front->data;
        free(q->front);
        
        q->front = trav; // Update Front to the second-to-last node
        q->front->next = NULL;
    }
    
    return data;
}

void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue Empty\n");
        return;
    }
    
    // Traversal goes from Rear (Head) to Front (Tail)
    printf("Queue (Rear/Head to Front/Tail): ");
    Node *trav = q->rear;
    while (trav != NULL) {
        printf("%d -> ", trav->data);
        trav = trav->next;
    }
    printf("NULL\n");
}

int main() {
    Queue *Q = initialize();
    
    printf("Enqueue 10, 20, 30...\n");
    enqueue(Q, 10); // List: 10 (F,R)
    enqueue(Q, 20); // List: 20(R) -> 10(F)
    enqueue(Q, 30); // List: 30(R) -> 20 -> 10(F)
    
    // Note: Since we enqueue at Head and dequeue at Tail,
    // The "First In" (10) is at the tail (Front).
    // The "Last In" (30) is at the head (Rear).
    display(Q);
    
    printf("Dequeued: %d\n", dequeue(Q)); // Should remove 10
    display(Q);
    
    printf("Dequeued: %d\n", dequeue(Q)); // Should remove 20
    display(Q);
    
    return 0;
}