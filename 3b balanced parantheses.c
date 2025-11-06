#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Stack structure
struct Stack {
    int top;
    char items[MAX];
};

// Function to initialize the stack
void initStack(struct Stack *s) {
    s->top = -1;
}

// Function to check if stack is empty
int isEmpty(struct Stack *s) {
    return s->top == -1;
}

// Function to check if stack is full
int isFull(struct Stack *s) {
    return s->top == MAX - 1;
}

// Function to push element to stack
void push(struct Stack *s, char c) {
    if (isFull(s)) {
        printf("Stack overflow!\n");
        exit(1);
    }
    s->items[++(s->top)] = c;
}

// Function to pop element from stack
char pop(struct Stack *s) {
    if (isEmpty(s)) {
        return '\0'; // Return null char if empty
    }
    return s->items[(s->top)--];
}

// Function to check matching pair
int isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

// Function to check for balanced parentheses
int isBalanced(char *exp) {
    struct Stack s;
    initStack(&s);

    for (int i = 0; i < strlen(exp); i++) {
        char ch = exp[i];

        // Push opening brackets
        if (ch == '(' || ch == '{' || ch == '[') {
            push(&s, ch);
        }
        // Check closing brackets
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (isEmpty(&s)) {
                return 0; // No matching opening bracket
            }
            char top = pop(&s);
            if (!isMatchingPair(top, ch)) {
                return 0; // Mismatched pair
            }
        }
    }

    // If stack is empty, parentheses are balanced
    return isEmpty(&s);
}

// Main function
int main() {
    char expression[MAX];

    printf("Enter an expression: ");
    scanf("%s", expression);

    if (isBalanced(expression))
        printf("The expression is balanced.\n");
    else
        printf("The expression is NOT balanced.\n");

    return 0;
}
