#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct {
    int items[MAX];
    int top;
} Stack;

Stack initialize() {
    Stack s;
    s.top = -1;
    return s;
}

bool isEmpty(Stack *s) {
    return (s->top == -1);
}

bool isFull(Stack *s) {
    return (s->top == MAX - 1);
}

void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->top++;
    s->items[s->top] = value;
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1;
    }
    int removed = s->items[s->top];
    s->top--;
    return removed;
}

int peek(Stack *s) {
    if (isEmpty(s)) return -1;
    return s->items[s->top];
}

void display(Stack *s) {
    printf("Stack (Top to Bottom): ");
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->items[i]);
    }
    printf("\n");
}

int main() {
    Stack s = initialize();
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    display(&s);
    printf("Popped: %d\n", pop(&s));
    display(&s);
    return 0;
}