#include <stdio.h>
#include <stdlib.h>
// Define structure for a binary tree node
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};
// Function to create a new node
struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
// Function to perform Inorder Traversal (Left -> Root -> Right)
void inorder(struct Node *root) {
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
// Function to perform Preorder Traversal (Root -> Left -> Right)
void preorder(struct Node *root) {
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
// Function to perform Postorder Traversal (Left -> Right -> Root)
void postorder(struct Node *root) {
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}
// Main function
int main() {
    // Create nodes manually for demonstration
    struct Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    /*
            1
           / \
          2   3
         / \ / \
        4  5 6  7
    */
    printf("Inorder Traversal: ");
    inorder(root);
    printf("\nPreorder Traversal: ");
    preorder(root);
    printf("\nPostorder Traversal: ");
    postorder(root);
    printf("\n");
    return 0;
}
