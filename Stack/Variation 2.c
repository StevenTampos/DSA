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
    newStack.top = MAX;
    return newStack;
}

bool isFull(Stack *S) {
    if(S->top == 0)
        return true;
    return false;
}

bool isEmpty(Stack *S) {
    if(S->top == MAX-1)
        return true;
    return false;
}

void push(Stack *S, int value) {
    if(isFull(S)) {
        return;
    }
    
    S->top--;
    S->items[S->top] = value;
}

int pop(Stack *S) {
    if(isEmpty(S)) {
        return 0;
    }
    
    int removed = S->items[S->top];
    S->top++;
    return removed;
}

int peek(Stack *S) {
    if(isEmpty(S)) {
        return 0;
    }
    
    return S->items[S->top];
}


void display(Stack *S) {
    if(isEmpty(S)) {
        return;
    }
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
   value = pop(&S);
   printf("Popped: %d\n", value);
   value = pop(&S);
   printf("Popped: %d\n", value);
   
   value = peek(&S);
   printf("Current top value: %d\n", value);
   
   printf("Stack: \n");
   display(&S);
}