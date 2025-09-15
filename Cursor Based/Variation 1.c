#include <stdio.h>
#include <stdlib.h>

#define MAX 10 

typedef struct {
    int elem;
    int next;
} Cell, HeapSpace[MAX];

typedef struct {
    HeapSpace H;
    int avail;
} VHeap;

typedef int List;


void initialize(VHeap *V) {
    for(int i = 0; i < MAX; i++) {
        if(i < MAX-1) {
            V->H[i].next = i+1;
        } else {
            V->H[i].next = -1;
        }
    }
    V->avail = 0;
}

int allocSpace(VHeap* V) {
    int ret = V->avail;
    if(ret != -1) {
        V->avail = V->H[ret].next;
    }
    return ret;
}

void deallocSpace(VHeap* V, int index) {
    V->H[index].next = V->avail;
    V->avail = index;
}

void insertFirst(int* L, VHeap* V, int elem) {
    int newCell = allocSpace(V);
    if(newCell != -1) {
        V->H[newCell].elem = elem;
        V->H[newCell].next = *L;
        *L = newCell;
    }
}

void insertLast(int* L, VHeap* V, int elem) {
    int newCell = allocSpace(V);
    if(newCell != -1) {
        V->H[newCell].elem = elem;
        V->H[newCell].next = -1;
        
        int *trav = L;
        while(*trav != -1) {
            trav = &V->H[*trav].next;
        }
        *trav = newCell;
    }
}

void delete(int *L, VHeap *V, int elem) {
    int *trav = L;
    while(*trav != -1 && V->H[*trav].elem != elem) {
        trav = &V->H[*trav].next;
    }
    int temp;
    if(*trav != -1) {
        temp = *trav;
        *trav = V->H[*trav].next;
        deallocSpace(V, temp);
    }
}

void display(int L, VHeap V) {
    int trav = L;
    printf("List:\n");
    while(trav != -1) {
        printf("[%d] [%d]\n", trav, V.H[trav].elem);
        trav = V.H[trav].next;
    }
}


int main() {
    List L = -1;
    VHeap V;
    
    initialize(&V);
    insertFirst(&L, &V, 100);
    insertLast(&L, &V, 60);
    insertLast(&L, &V, 70);
    insertFirst(&L, &V, 80);
    insertFirst(&L, &V, 90);
    insertLast(&L, &V, 50);
    insertLast(&L, &V, 40);
    insertFirst(&L, &V, 10);
    insertFirst(&L, &V, 20);
    insertFirst(&L, &V, 30);
    display(L, V);
    delete(&L, &V, 10);
    delete(&L, &V, 20);
    display(L, V);
    
    
}