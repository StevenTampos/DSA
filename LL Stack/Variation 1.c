#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct {
    Node* top;
} Stack;

Stack* initialize() {
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->top = NULL;
    return s;
}

bool isEmpty(Stack* s) {
    return (s->top == NULL);
}

bool isFull(Stack* s) {
    return false; // Linked List typically effectively infinite
}

void push(Stack* s, int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) return; // Malloc fail check
    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
}

int pop(Stack* s) {
    if (isEmpty(s)) return -1;
    
    Node *temp = s->top;
    int data = temp->data;
    s->top = temp->next;
    free(temp);
    return data;
}

int peek(Stack* s) {
    if (isEmpty(s)) return -1;
    return s->top->data;
}

void display(Stack* s) {
    printf("Stack: ");
    Node *trav = s->top;
    while(trav != NULL) {
        printf("%d -> ", trav->data);
        trav = trav->next;
    }
    printf("NULL\n");
}

int main() {
    Stack *S = initialize();
    push(S, 10);
    push(S, 20);
    push(S, 30);
    display(S);
    
    printf("Popped: %d\n", pop(S));
    display(S);
    return 0;
}