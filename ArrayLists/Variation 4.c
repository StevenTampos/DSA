#include <stdio.h>
#include <stdlib.h>

#define LENGTH 10

typedef struct {
    int *elemPtr;
    int count;
    int max;
} List;

void initialize(List *L) {
    L->elemPtr = (int*)malloc(LENGTH * sizeof(int));
    L->max = LENGTH;
    L->count = 0;
}

void resize(List *L) {
    L->max *= 2;
    L->elemPtr = (int*)realloc(L->elemPtr, L->max * sizeof(int));
}

void insertPos(List *L, int data, int position) {
    if (position < 0 || position > L->count) return;
    
    if (L->count >= L->max) {
        resize(L);
    }
    
    for (int i = L->count; i > position; i--) {
        L->elemPtr[i] = L->elemPtr[i-1];
    }
    
    L->elemPtr[position] = data;
    L->count++;
}

void deletePos(List *L, int position) {
    if (position < 0 || position >= L->count) return;
    
    for (int i = position; i < L->count - 1; i++) {
        L->elemPtr[i] = L->elemPtr[i+1];
    }
    L->count--;
}

int locate(List *L, int data) {
    for(int i = 0; i < L->count; i++) {
        if(L->elemPtr[i] == data) return i;
    }
    return -1;
}

int retrieve(List *L, int position) {
    if (position < 0 || position >= L->count) return -1;
    return L->elemPtr[position];
}

void display(List *L) {
    printf("List (Max %d): ", L->max);
    for (int i = 0; i < L->count; i++) {
        printf("%d ", L->elemPtr[i]);
    }
    printf("\n");
}

void makeNULL(List *L) {
    free(L->elemPtr);
    L->elemPtr = NULL;
    L->count = 0;
}

int main() {
    List L;
    initialize(&L);
    
    insertPos(&L, 5, 0);
    insertPos(&L, 10, 1);
    insertPos(&L, 7, 1); // 5, 7, 10
    display(&L);
    
    deletePos(&L, 0); // 7, 10
    display(&L);
    
    makeNULL(&L);
    return 0;
}