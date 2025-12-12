#include <stdio.h>
#include <stdbool.h>

#define ARRAY_SIZE 8

typedef bool Set[ARRAY_SIZE];

void initialize(Set set) {
    for(int i = 0; i < ARRAY_SIZE; i++) {
        set[i] = false;
    }
}

void insert(Set set, int element) {
    if(element >= 0 && element < ARRAY_SIZE) {
        set[element] = true;
    }
}

void delete(Set set, int element) {
    if(element >= 0 && element < ARRAY_SIZE) {
        set[element] = false;
    }
}

bool find(Set set, int element) {
    if(element >= 0 && element < ARRAY_SIZE) {
        return set[element];
    }
    return false;
}

void set_union(Set A, Set B, Set C) {
    for(int i = 0; i < ARRAY_SIZE; i++) {
        C[i] = A[i] || B[i];
    }
}

void intersection(Set A, Set B, Set C) {
    for(int i = 0; i < ARRAY_SIZE; i++) {
        C[i] = A[i] && B[i];
    }
}

void difference(Set A, Set B, Set C) {
    for(int i = 0; i < ARRAY_SIZE; i++) {
        C[i] = A[i] && !B[i];
    }
}

void display(Set set) {
    printf("{ ");
    for(int i = 0; i < ARRAY_SIZE; i++) {
        if(set[i]) {
            printf("%d ", i);
        }
    }
    printf("}\n");
}

int main() {
    Set A, B, C;
    initialize(A); initialize(B);
    
    insert(A, 0); insert(A, 2); insert(A, 7);
    insert(B, 2); insert(B, 4); insert(B, 5);
    
    printf("A: "); display(A);
    printf("B: "); display(B);
    
    set_union(A, B, C);
    printf("Union: "); display(C);
    
    return 0;
}