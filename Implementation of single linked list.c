#include <stdio.h>
#include <stdlib.h>
// Define the structure for a node
struct Node {
    int data;
    struct Node *next;
};
// Function to create a new node
struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
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
}
// Delete a node by value
void deleteNode(struct Node **head, int key) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = *head;
    struct Node *prev = NULL;
    // If head node itself holds the key
    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        printf("Deleted node with value %d\n", key);
        return;
    }
    // Search for the node to be deleted
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node with value %d not found.\n", key);
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("Deleted node with value %d\n", key);
}
// Display the linked list
void displayList(struct Node *head) {
    struct Node *temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
// Main function
int main() {
    struct Node *head = NULL;
    int n, value, del;
    // Insert nodes
    printf("Enter number of nodes to insert: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        insertAtEnd(&head, value);
    }
    // Display list
    printf("\nLinked List after insertion:\n");
    displayList(head);
    // Delete a node
    printf("\nEnter value to delete: ");
    scanf("%d", &del);
    deleteNode(&head, del);
    // Display final list
    printf("\nLinked List after deletion:\n");
    displayList(head);
    return 0;
}
