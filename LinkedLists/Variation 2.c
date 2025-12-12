#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct {
    Node *next; // Head pointer (often a dummy header or just the first node pointer)
    int count;
} List; 

List* initialize() {
    List *list = (List*)malloc(sizeof(List));
    if(list == NULL) {
        return NULL;
    }
    list->next = NULL;
    list->count = 0;
    return list;
}

void empty(List *list) {
    if(list->next == NULL) {
        return;
    }
    Node *current = list->next;
    Node *temp;
    while(current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }
    list->next = NULL;
    list->count = 0;
}

void insertFirst(List *list, int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    // Since list->next acts as the "Head", we insert before it
    newNode->next = list->next;
    list->next = newNode;
    list->count++;
}

void insertLast(List *list, int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    
    if(list->next == NULL) {
        list->next = newNode;
    } else {
        Node *temp = list->next;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    list->count++;
}

void insertPos(List *list, int data, int index) {
    if(index > list->count || index < 0) { // Check bounds
        return;
    }
    
    if(index == 0) {
        insertFirst(list, data);
    } else {
        Node *newNode = (Node*)malloc(sizeof(Node));
        newNode->data = data;
        Node *curr = list->next;
        // Stop one node before the target index
        for(int i = 0; i < index-1; i++) {
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
        list->count++;
    }
}

void deleteStart(List *list) {
    if(list->next == NULL) {
        return;
    }
    
    Node *curr = list->next;
    list->next = curr->next;
    free(curr);
    list->count--;
}

void deleteLast(List *list) {
    if(list->next == NULL) return;

    if(list->next->next == NULL) { // Only one element
        free(list->next);
        list->next = NULL;
    } else {
        Node *curr = list->next;
        while(curr->next->next != NULL) { // Stop at second to last
            curr = curr->next;
        }
        free(curr->next);
        curr->next = NULL;
    }
    list->count--;
}

void deletePos(List *list, int index) {
    if(index >= list->count || index < 0) return;

    if(index == 0) {
        deleteStart(list);
    } else {
        Node *curr = list->next;
        for(int i = 0; i < index-1; i++) {
            curr = curr->next;
        }
        Node *temp = curr->next;
        curr->next = temp->next;
        free(temp);
        list->count--;
    }
}

int retrieve(List *list, int index) {
    if (index < 0 || index >= list->count) return -1; // Error value
    
    Node *curr = list->next;
    for (int i = 0; i < index; i++) {
        curr = curr->next;
    }
    return curr->data;
}

int locate(List *list, int data) {
    Node *curr = list->next;
    int index = 0;
    while (curr != NULL) {
        if (curr->data == data) {
            return index;
        }
        curr = curr->next;
        index++;
    }
    return -1; // Not found
}

void display(List *list) {
    printf("List (Count: %d): ", list->count);
    Node *curr = list->next;
    while (curr != NULL) {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

int main() {
    List *myList = initialize();
    
    insertFirst(myList, 10);
    insertLast(myList, 20);
    insertPos(myList, 15, 1); // Should be 10 -> 15 -> 20
    
    display(myList);
    
    printf("Locate 15: Index %d\n", locate(myList, 15));
    printf("Retrieve at 2: %d\n", retrieve(myList, 2));
    
    deletePos(myList, 1);
    printf("After deleting index 1:\n");
    display(myList);
    
    empty(myList);
    printf("After empty:\n");
    display(myList);
    
    return 0;
}