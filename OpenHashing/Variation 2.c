#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DICT_SIZE 10

// --- Linked List Node Definition ---
typedef struct node {
    int data;
    struct node* next;
} Node, *List;

typedef List Dictionary[DICT_SIZE]; // Array of List Pointers

// --- Operations ---

void initDictionary(Dictionary D) {
    for (int i = 0; i < DICT_SIZE; i++) {
        D[i] = NULL; // Initialize all headers to NULL
    }
}

int hash(int value) {
    return value % DICT_SIZE;
}

void insert(Dictionary D, int value) {
    int idx = hash(value);
    
    // Check if value exists (Sorted insertion or simple insert front)
    // Let's do Insert at Beginning (simplest O(1))
    
    // First check for duplicate
    Node* trav = D[idx];
    while(trav != NULL) {
        if (trav->data == value) return; // Already exists
        trav = trav->next;
    }
    
    // Create new node
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = D[idx];
    D[idx] = newNode;
}

void delete(Dictionary D, int value) {
    int idx = hash(value);
    Node* trav = D[idx];
    Node* prev = NULL;
    
    while (trav != NULL) {
        if (trav->data == value) {
            if (prev == NULL) {
                // Deleting first node
                D[idx] = trav->next;
            } else {
                // Deleting middle/last node
                prev->next = trav->next;
            }
            free(trav);
            return;
        }
        prev = trav;
        trav = trav->next;
    }
}

bool member(Dictionary D, int value) {
    int idx = hash(value);
    Node* trav = D[idx];
    while (trav != NULL) {
        if (trav->data == value) return true;
        trav = trav->next;
    }
    return false;
}

void display(Dictionary D) {
    printf("\n--- Dictionary Content ---\n");
    for (int i = 0; i < DICT_SIZE; i++) {
        printf("[%d]: ", i);
        Node* trav = D[i];
        while (trav != NULL) {
            printf("%d -> ", trav->data);
            trav = trav->next;
        }
        printf("NULL\n");
    }
}

int main() {
    Dictionary D;
    initDictionary(D);
    
    insert(D, 15); // Hash: 5
    insert(D, 25); // Hash: 5 (Collision -> 25 -> 15)
    insert(D, 35); // Hash: 5 (Collision -> 35 -> 25 -> 15)
    insert(D, 7);  // Hash: 7
    insert(D, 10); // Hash: 0
    
    display(D);
    
    printf("\nIs 25 a member? %s\n", member(D, 25) ? "Yes" : "No");
    
    printf("\nDeleting 25...\n");
    delete(D, 25);
    display(D);
    
    return 0;
}