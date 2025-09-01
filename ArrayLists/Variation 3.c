#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int *elem;  
    int count;  
    int capacity;
} Etype;

Etype initialize(Etype L) {
    L.capacity = 10; 
    L.count = 0;
    L.elem = (int *)malloc(L.capacity * sizeof(int));
    return L;
}

Etype resize(Etype L) {
    L.capacity *= 2;
    L.elem = (int *)realloc(L.elem, L.capacity * sizeof(int));
    return L;
}

Etype insertPos(Etype L, int data, int position) {
    if (position < 0 || position > L.count) {
        return L;
    }

    if (L.count == L.capacity) {
        L = resize(L);
    }

    for (int i = L.count - 1; i >= position; i--) {
        L.elem[i + 1] = L.elem[i];
    }

    L.elem[position] = data;
    L.count++;
    return L;
}

Etype deletePos(Etype L, int position) {
    // return if invalid
    if(position > L.count) {
        return L;
    }
    
    for(int i = position; i < L.count; i++) {
        L.elem[i] = L.elem[i+1];
    }
    L.count -= 1;
    return L;
}

int locate(Etype L, int data) {
    for(int i = 0; i < L.count; i++) {
        if(L.elem[i] == data) {
            return i;
        }
    }
    return -1;
}

Etype insertSorted(Etype L, int data) {
    int pos = L.count;  // default insert at the end

    // find correct position
    for (int i = 0; i < L.count; i++) {
        if (data < L.elem[i]) {
            pos = i;
            break;
        }
    }

    // shift elements to the right
    for (int j = L.count - 1; j >= pos; j--) {
        L.elem[j + 1] = L.elem[j];
    }

    // insert data
    L.elem[pos] = data;
    L.count += 1;
    return L;
}

void display(Etype L) {
    printf("\nList of Elements:\n");
    for(int i = 0; i < L.count; i++) {
        printf("%d ", L.elem[i]);
    }
}

int main() {
    Etype L; // create list
    int found;
    
    L = initialize(L); // set count to 0 or initialize
    L = insertPos(L, 1, 0);
    L = insertPos(L, 3, 1);
    L = insertPos(L, 6, 2);
    L = insertPos(L, 7, 3);
    L = insertPos(L, 4, 1);
    L = deletePos(L, 2);
    L = deletePos(L, 3);
    found = locate(L, 6);
    printf("Location: %d\n", found);
    found = locate(L, 7);
    printf("Location: %d\n", found);
    L = insertSorted(L, 3);
    L = insertSorted(L, 8);
    
    display(L);
}