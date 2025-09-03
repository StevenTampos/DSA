#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct {
    Node *next; // LINKED LIST
    int count;
} List; // LIST

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
    if(list->next == NULL) {
        list->next = newNode;
        newNode->next = NULL;
    } else {
        Node *temp = list->next;
        newNode->next = temp;
        list->next = newNode;
    }
    
    list->count++;
}

void insertLast(List *list, int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    if(list->next == NULL) {
        list->next = newNode;
        newNode->next = NULL;
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
    if(index >= list->count) {
        return;
    }
    
    if(index == 0) {
        insertFirst(list, data);
    } else if(index == list->count-1) {
        insertLast(list, data);
    } else {
        Node *newNode = (Node*)malloc(sizeof(Node));
        newNode->data = data;
        Node *curr = list->next;
        for(int i = 0; i < index-1; i++) {
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
    }
    
    list->count++;
}

void deleteStart(List *list) {
    if(list->next == NULL) {
        return;
    }
    
    Node *curr = list->next;
    curr = curr->next;
    free(curr);
    list->count--;
}

void deleteLast(List *list) {

    if(list->count == 1) {
        Node *temp = list->next;
        free(temp);
        list->next = NULL;
    } else {
        Node *curr = list->next;
        for(int i = 0; i < list->count-2; i++) {
            curr = curr->next;
        }
        free(curr->next);
        curr->next = NULL;
    }
    
    list->count--;
}

void deletePos(List *list, int index) {
    if(index == 0) {
        deleteStart(&list);
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

}

int locate(List *list, int data) {

}

void display(List *list) {

}



int main() {



}