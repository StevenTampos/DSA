#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int elem[MAX];
    int count;
} List;

List initialize (List L) {
    L.count = 0;
    return L;
}

List insertPos(List L, int data, int position) {
    // return if invalid
    if(position > L.count) {
        return L;
    }
    
    // insert directly to the position if no number
    if(position >= L.count) {
        L.elem[position] = data;
        L.count += 1;
        return L;
    } else if(position <= L.count) { // shift first before inserting the number
        for(int i = L.count - 1; i >= position; i--) {
            int temp = L.elem[i];
            L.elem[i+1] = temp;
        }
        L.elem[position] = data;
        L.count += 1;
        return L;
    }
}

List deletePos(List L, int position) {
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

int locate(List L, int data) {
    int found = -1;
    for(int i = 0; i < L.count; i++) {
        if(L.elem[i] == data) {
            found = i;
        }
    }
    return found;
}

List insertSorted(List L, int data) {
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

void display(List L) {
    printf("\nList of Elements:\n");
    for(int i = 0; i < L.count; i++) {
        printf("%d ", L.elem[i]);
    }
}

int main() {
    List L; // create list
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