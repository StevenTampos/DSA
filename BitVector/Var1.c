#include <stdio.h>
#include <stdbool.h>

#define MAX_BITS (8 * sizeof(unsigned char))

void initialize(unsigned char *set) {
    *set = 0;
}

void insert(unsigned char *set, int element) {
    if (element < 0 || element >= MAX_BITS) {
        printf("Error: Element %d out of range (0-%d)\n", element, MAX_BITS - 1);
        return;
    }
    unsigned char mask = 1 << element;
    *set |= mask;
}

void delete(unsigned char *set, int element) {
    if (element < 0 || element >= MAX_BITS) {
        printf("Error: Element %d out of range (0-%d)\n", element, MAX_BITS - 1);
        return;
    }
    unsigned char mask = ~(1 << element);
    *set &= mask;
}

bool find(unsigned char set, int element) {
    if (element < 0 || element >= MAX_BITS) {
        return false;
    }
    unsigned char mask = 1 << element;
    return (set & mask) != 0;
}

unsigned char set_union(unsigned char A, unsigned char B) {
    return A | B;
}

unsigned char intersection(unsigned char A, unsigned char B) {
    return A & B;
}

unsigned char difference(unsigned char A, unsigned char B) {
    return A & (~B);
}

void display(unsigned char set) {
    printf("{");
    int first = 1;
    for (int i = 0; i < MAX_BITS; i++) {
        if (find(set, i)) {
            if (!first) {
                printf(", ");
            }
            printf("%d", i);
            first = 0;
        }
    }
    printf("}\n");
}

int main() {
    unsigned char A, B, C;

    initialize(&A);
    insert(&A, 1);
    insert(&A, 6);
    printf("A = %d ", A);
    display(A);

    delete(&A, 6);
    printf("A after deleting 6 = %d ", A);
    display(A); 

    delete(&A, 1);
    printf("A after deleting 1 = %d ", A);
    display(A);

    A = 66;
    B = 200;
    C = set_union(A, B);
    printf("Union C = %d ", C);
    display(C);

    C = intersection(A, B);
    printf("Intersection C = %d ", C);
    display(C);

    C = difference(A, B);
    printf("Difference C = %d ", C);
    display(C);

    return 0;
}
