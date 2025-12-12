#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5

typedef struct {
    int items[MAX];
    int top;
} Stack;

Stack initialize() {
    Stack newStack;
    newStack.top = MAX; // Starts at the "end" of the array
    return newStack;
}

bool isFull(Stack *S) {
    // If top reaches 0, the next decrement would be -1 (out of bounds), so it's full.
    if(S->top == 0)
        return true;
    return false;
}

bool isEmpty(Stack *S) {
    // If top is at MAX, no items have been pushed (items are at indices 0 to MAX-1)
    if(S->top == MAX)
        return true;
    return false;
}

void push(Stack *S, int value) {
    if(isFull(S)) {
        printf("Stack Overflow\n");
        return;
    }
    
    S->top--;
    S->items[S->top] = value;
}

int pop(Stack *S) {
    if(isEmpty(S)) {
        printf("Stack Underflow\n");
        return -1; // Return error value
    }
    
    int removed = S->items[S->top];
    S->top++; // "Remove" by moving top back up
    return removed;
}

int peek(Stack *S) {
    if(isEmpty(S)) {
        return -1;
    }
    
    return S->items[S->top];
}


void display(Stack *S) {
    if(isEmpty(S)) {
        printf("Stack is empty.\n");
        return;
    }
    // Iterate from the current top up to MAX-1
    for(int i = S->top; i < MAX; i++) {
        printf("%d\n", S->items[i]);
    }
}


int main() {
   int value = 0;
   
   Stack S = initialize();
   push(&S, 1);
   push(&S, 3);
   push(&S, 2);
   push(&S, 5);
   push(&S, 4);
   
   printf("Stack after pushes:\n");
   display(&S);

   value = pop(&S);
   printf("Popped: %d\n", value);
   
   value = peek(&S);
   printf("Current top value: %d\n", value);
   
   printf("Final Stack: \n");
   display(&S);
   
   return 0;
}