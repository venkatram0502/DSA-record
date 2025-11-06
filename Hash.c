#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 10
#define EMPTY -1
int hashTable[TABLE_SIZE];

void initialize() {
    for (int i = 0; i < TABLE_SIZE; i++)
        hashTable[i] = EMPTY;
}
// Hash function (simple modulo)
int hash(int key) {
    return key % TABLE_SIZE;
}
// Insert a key into the hash table using linear probing
void insert(int key) {
    int index = hash(key);
    int originalIndex = index;
        while (hashTable[index] != EMPTY) {
        index = (index + 1) % TABLE_SIZE;
        if (index == originalIndex) {
            printf("Hash table is full! Cannot insert %d\n", key);
            return;
        }
    }
    hashTable[index] = key;
    printf("Inserted %d at index %d\n", key, index);
}

// Search for a key in the hash table
int search(int key) {
    int index = hash(key);
    int originalIndex = index;
    while (hashTable[index] != EMPTY) {
        if (hashTable[index] == key)
            return index;
        index = (index + 1) % TABLE_SIZE;
        if (index == originalIndex)
            break;
    }
    return -1; // Not found
}
// Display the hash table
void display() {
    printf("Hash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] != EMPTY)
            printf("[%d] -> %d\n", i, hashTable[i]);
        else
            printf("[%d] -> \n", i);
    }
}
// Main function
int main() {
    initialize();
    int n, key;
    printf("Enter number of elements to insert: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &key);
        insert(key);
    }
    display();
    printf("Enter a key to search: ");
    scanf("%d", &key);
    int idx = search(key);
    if (idx != -1)
        printf("Key %d found at index %d\n", key, idx);
    else
        printf("Key %d not found\n", key);

    return 0;
}
