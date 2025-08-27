#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int elem[MAX];
    int count;
} Etype ,*EPtr;

void initialize (EPtr L) {
    L->count = 0;
}

void insertPos(EPtr L, int data, int position) {
    // return if invalid
    if(position > L->count) {
        return;
    }
    
    // insert directly to the position if no number
    if(position >= L->count) {
        L->elem[position] = data;
        L->count += 1;
    } else if(position <= L->count) { // shift first before inserting the number
        for(int i = L->count - 1; i >= position; i--) {
            int temp = L->elem[i];
            L->elem[i+1] = temp;
        }
        L->elem[position] = data;
        L->count += 1;
    }
}

void deletePos(EPtr L, int position) {
    // return if invalid
    if(position > L->count) {
        return;
    }
    
    for(int i = position; i < L->count; i++) {
        L->elem[i] = L->elem[i+1];
    }
    L->count -= 1;
}

int locate(EPtr L, int data) {
    int found = -1;
    for(int i = 0; i < L->count; i++) {
        if(L->elem[i] == data) {
            found = i;
        }
    }
    return found;
}

void insertSorted(EPtr L, int data) {
    int pos = L->count;  // default insert at the end

    // find correct position
    for (int i = 0; i < L->count; i++) {
        if (data < L->elem[i]) {
            pos = i;
            break;
        }
    }

    // shift elements to the right
    for (int j = L->count - 1; j >= pos; j--) {
        L->elem[j + 1] = L->elem[j];
    }

    // insert data
    L->elem[pos] = data;
    L->count += 1;
}

void display(EPtr L) {
    printf("\nList of Elements:\n");
    for(int i = 0; i < L->count; i++) {
        printf("%d ", L->elem[i]);
    }
}

int main() {
    Etype L; // create list
    int found;
    
    initialize(&L); // set count to 0 or initialize
    insertPos(&L, 1, 0);
    insertPos(&L, 3, 1);
    insertPos(&L, 6, 2);
    insertPos(&L, 7, 3);
    insertPos(&L, 4, 1);
    deletePos(&L, 2);
    deletePos(&L, 3);
    found = locate(&L, 6);
    printf("Location: %d\n", found);
    found = locate(&L, 7);
    printf("Location: %d\n", found);
    insertSorted(&L, 3);
    insertSorted(&L, 8);
    
    display(&L);
}