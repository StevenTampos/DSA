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
        // Set avail to list beginning and link cells
        V->H[i].next = (i < MAX - 1) ? i + 1 : -1;
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
    if(index != -1 && index < MAX) {
        V->H[index].next = V->avail;
        V->avail = index;
    }
}

void insertFirst(List* L, VHeap* V, int elem) {
    int newCell = allocSpace(V);
    if(newCell != -1) {
        V->H[newCell].elem = elem;
        V->H[newCell].next = *L;
        *L = newCell;
    }
}

void insertLast(List* L, VHeap* V, int elem) {
    int newCell = allocSpace(V);
    if(newCell != -1) {
        V->H[newCell].elem = elem;
        V->H[newCell].next = -1;
        
        if (*L == -1) {
            *L = newCell;
        } else {
            int trav = *L;
            while(V->H[trav].next != -1) {
                trav = V->H[trav].next;
            }
            V->H[trav].next = newCell;
        }
    }
}

void insertPos(List* L, VHeap* V, int elem, int pos) {
    if (pos < 0) return; // Invalid position

    if (pos == 0) {
        insertFirst(L, V, elem);
        return;
    }

    int newCell = allocSpace(V);
    if (newCell != -1) {
        V->H[newCell].elem = elem;
        
        int trav = *L;
        // Traverse to the cell before insertion point (index - 1)
        for (int i = 0; i < pos - 1 && trav != -1; i++) {
            trav = V->H[trav].next;
        }

        if (trav != -1) {
            V->H[newCell].next = V->H[trav].next;
            V->H[trav].next = newCell;
        } else {
            // Position out of bounds, decide to insert last or dealloc
            // For now, let's dealloc to be safe or insertLast
            deallocSpace(V, newCell); 
        }
    }
}

void insertSorted(List* L, VHeap* V, int elem) {
    int newCell = allocSpace(V);
    if(newCell != -1) {
        V->H[newCell].elem = elem;
        
        // If list is empty or new elem is smaller than first
        if (*L == -1 || elem < V->H[*L].elem) {
            V->H[newCell].next = *L;
            *L = newCell;
        } else {
            int trav = *L;
            // Find insertion point
            while (V->H[trav].next != -1 && V->H[V->H[trav].next].elem < elem) {
                trav = V->H[trav].next;
            }
            V->H[newCell].next = V->H[trav].next;
            V->H[trav].next = newCell;
        }
    }
}

void delete(List *L, VHeap *V, int elem) {
    int *trav = L;
    while(*trav != -1 && V->H[*trav].elem != elem) {
        trav = &V->H[*trav].next;
    }
    
    if(*trav != -1) {
        int temp = *trav;
        *trav = V->H[*trav].next;
        deallocSpace(V, temp);
    }
}

void deleteAllOccurrence(List* L, VHeap *V, int elem) {
    int *trav = L;
    while (*trav != -1) {
        if (V->H[*trav].elem == elem) {
            int temp = *trav;
            *trav = V->H[*trav].next;
            deallocSpace(V, temp);
        } else {
            trav = &V->H[*trav].next;
        }
    }
}

void display(List L, VHeap V) {
    int trav = L;
    printf("List: ");
    while(trav != -1) {
        printf("[%d] ", V.H[trav].elem);
        trav = V.H[trav].next;
    }
    printf("\n");
}

int main() {
    VHeap V;
    List L = -1;
    
    initialize(&V);
    insertFirst(&L, &V, 10);
    insertLast(&L, &V, 30);
    insertPos(&L, &V, 20, 1); // 10, 20, 30
    insertSorted(&L, &V, 15); // 10, 15, 20, 30
    insertFirst(&L, &V, 20);  // 20, 10, 15, 20, 30
    
    display(L, V);
    
    printf("Deleting all 20s...\n");
    deleteAllOccurrence(&L, &V, 20);
    
    display(L, V);
    
    return 0;
}