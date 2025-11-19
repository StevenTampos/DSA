#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *lc;
    struct node *rc;
} Node, *BST;

void insert(BST* B, int value) {
    BST* trav = B;
    while(*trav != NULL && (*trav)->data != value) {
        trav = ((*trav)->data > value ? &(*trav)->lc : &(*trav)->rc);
    }
    
    if(*trav == NULL) {
        Node *newNode = (Node*)malloc(sizeof(Node));
        newNode->lc = NULL;
        newNode->rc = NULL;
        newNode->data = value;
        
        *trav = newNode;
    }
}

void deleteNode(BST* B, int value) {
    BST* trav = B;
    while(*trav != NULL && (*trav)->data != value) {
        trav = ((*trav)->data > value ? &(*trav)->lc : &(*trav)->rc);
    }
    
    if(*trav == NULL) {
        return;
    }
    
    //if no child
    if((*trav)->lc == NULL && (*trav)->rc == NULL) {
        free(*trav);
        *trav = NULL;
    } else if((*trav)->lc == NULL || (*trav)->rc == NULL) { //if only has one child
        if((*trav)->lc != NULL) {
            *trav = (*trav)->lc;
        } else {
            *trav = (*trav)->rc;
        }
    } else if((*trav)->lc != NULL && (*trav)->rc != NULL) { //have both child
        
    }
}

void printTree(BST B) {
    if(B != NULL) {
        printTree(B->lc);
        printf("%d ", B->data);
        printTree(B->rc);
    }
}

int main() {
    BST B = NULL;
    
    insert(&B, 10);
    insert(&B, 4);
    insert(&B, 7);
    insert(&B, 12);
    insert(&B, 1);
    
    //inorder print
    printTree(B);
    
    deleteNode(&B, 12);
    
    
    //inorder print
    printTree(B);
    return 0;
}