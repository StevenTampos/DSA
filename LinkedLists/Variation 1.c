#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct {
    Node *head;
    int count;
} List;

List initialize() {
    List L;
    L.head = NULL;
    L.count = 0;
    return L;
}

// Helper to create a node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

List insertFirst(List L, int data) {
    Node* newNode = createNode(data);
    newNode->next = L.head;
    L.head = newNode;
    L.count++;
    return L;
}

List insertLast(List L, int data) {
    Node* newNode = createNode(data);
    if (L.head == NULL) {
        L.head = newNode;
    } else {
        Node* trav = L.head;
        while (trav->next != NULL) {
            trav = trav->next;
        }
        trav->next = newNode;
    }
    L.count++;
    return L;
}

List deleteFirst(List L) {
    if (L.head != NULL) {
        Node* temp = L.head;
        L.head = temp->next;
        free(temp);
        L.count--;
    }
    return L;
}

List deleteLast(List L) {
    if (L.head == NULL) return L;

    if (L.head->next == NULL) {
        free(L.head);
        L.head = NULL;
    } else {
        Node* trav = L.head;
        while (trav->next->next != NULL) {
            trav = trav->next;
        }
        free(trav->next);
        trav->next = NULL;
    }
    L.count--;
    return L;
}

void display(List L) {
    printf("List (Count %d): ", L.count);
    Node* trav = L.head;
    while (trav != NULL) {
        printf("%d -> ", trav->data);
        trav = trav->next;
    }
    printf("NULL\n");
}

int main() {
    List L = initialize();
    L = insertFirst(L, 10);
    L = insertLast(L, 20);
    L = insertFirst(L, 5); // 5 -> 10 -> 20
    display(L);
    
    L = deleteFirst(L);    // 10 -> 20
    L = deleteLast(L);     // 10
    display(L);
    return 0;
}