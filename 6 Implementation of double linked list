#include <stdio.h>
#include <stdlib.h>
// Define structure for doubly linked list node
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};
// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
// Insert a node at the end
void insertAtEnd(struct Node **head, int data) {
    struct Node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}
// Delete a node by value
void deleteNode(struct Node **head, int key) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = *head;
    // If head node is to be deleted
    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        if (*head != NULL)
            (*head)->prev = NULL;
        free(temp);
        printf("Node with value %d deleted.\n", key);
        return;
    }
    // Search for the node to delete
    while (temp != NULL && temp->data != key)
        temp = temp->next;
    if (temp == NULL) {
        printf("Node with value %d not found.\n", key);
        return;
    }
    // Unlink the node
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    free(temp);
    printf("Node with value %d deleted.\n", key);
}
// Display list forward
void displayForward(struct Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    printf("List (forward): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
// Display list backward
void displayBackward(struct Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next; // Move to last node
    printf("List (backward): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}
// Main function
int main() {
    struct Node *head = NULL;
    int n, value, del;
    printf("Enter number of nodes to insert: ");
    scanf("%d", &n);
    // Insert nodes
    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        insertAtEnd(&head, value);
    }
    // Display list forward
    printf("\nDoubly Linked List (forward):\n");
    displayForward(head);
    // Display list backward
    printf("Doubly Linked List (backward):\n");
    displayBackward(head);
    // Delete a node
    printf("\nEnter value to delete: ");
    scanf("%d", &del);
    deleteNode(&head, del);
    // Display updated list
    printf("\nAfter deletion:\n");
    displayForward(head);
    displayBackward(head);
    return 0;
}
