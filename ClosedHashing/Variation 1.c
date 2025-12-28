#include <stdio.h>
#include <stdbool.h>

#define SIZE 10
#define EMPTY -1
#define DELETED -2

typedef int Dictionary[SIZE];

void init(Dictionary D) {
    for (int i = 0; i < SIZE; i++) {
        D[i] = EMPTY;
    }
}

int hash(int key) {
    return key % SIZE;
}

void insert(Dictionary D, int key) {
    int idx = hash(key);
    int start = idx;

    // Look for an empty or deleted slot
    while (D[idx] != EMPTY && D[idx] != DELETED && D[idx] != key) {
        idx = (idx + 1) % SIZE;
        if (idx == start) {
            printf("Table full\n");
            return;
        }
    }
    D[idx] = key;
}

void delete(Dictionary D, int key) {
    int idx = hash(key);
    int start = idx;

    while (D[idx] != EMPTY) {
        if (D[idx] == key) {
            D[idx] = DELETED;
            return;
        }
        idx = (idx + 1) % SIZE;
        if (idx == start) break;
    }
}

bool isMember(Dictionary D, int key) {
    int idx = hash(key);
    int start = idx;

    while (D[idx] != EMPTY) {
        if (D[idx] == key) return true;
        idx = (idx + 1) % SIZE;
        if (idx == start) break;
    }
    return false;
}

void display(Dictionary D) {
    for (int i = 0; i < SIZE; i++) {
        printf("[%d]: ", i);
        if (D[i] == EMPTY) printf("EMPTY\n");
        else if (D[i] == DELETED) printf("DELETED\n");
        else printf("%d\n", D[i]);
    }
}

int main() {
    Dictionary D;
    init(D);
    insert(D, 15);
    insert(D, 25); // Collision, moves to next slot
    insert(D, 35);
    display(D);
    delete(D, 25);
    printf("Is 25 member? %d\n", isMember(D, 25));
    display(D);
    return 0;
}