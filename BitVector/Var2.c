#include <stdio.h>
#include <stdbool.h>

typedef struct {
    unsigned int field : 8; // 8 bits wide
} Set;

void initialize(Set *set) {
    set->field = 0;
}

void insert(Set *set, int element) {
    if (element < 0 || element >= 8) return;
    unsigned int mask = 1 << element;
    set->field |= mask;
}

void delete(Set *set, int element) {
    if (element < 0 || element >= 8) return;
    unsigned int mask = ~(1 << element);
    set->field &= mask;
}

bool find(Set set, int element) {
    if (element < 0 || element >= 8) return false;
    unsigned int mask = 1 << element;
    return (set.field & mask) != 0;
}

Set set_union(Set A, Set B) {
    Set C;
    C.field = A.field | B.field;
    return C;
}

Set intersection(Set A, Set B) {
    Set C;
    C.field = A.field & B.field;
    return C;
}

Set difference(Set A, Set B) {
    Set C;
    C.field = A.field & (~B.field);
    return C;
}

void display(Set set) {
    printf("{ ");
    for(int i = 0; i < 8; i++) {
        if(find(set, i)) {
            printf("%d ", i);
        }
    }
    printf("}\n");
}

int main() {
    Set A, B, C;
    initialize(&A);
    initialize(&B);
    
    insert(&A, 1); insert(&A, 4); insert(&A, 5);
    insert(&B, 2); insert(&B, 5);
    
    printf("A: "); display(A);
    printf("B: "); display(B);
    
    C = set_union(A, B);
    printf("Union: "); display(C);
    
    C = intersection(A, B);
    printf("Intersection: "); display(C);
    
    return 0;
}