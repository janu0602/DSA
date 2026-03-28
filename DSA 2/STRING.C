#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

// Define the stack structure
struct Stack {
    int top;
    char arr[MAX_SIZE];
};

// Function to initialize the stack
void initStack(struct Stack* stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
int isFull(struct Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

// Function to push a character onto the stack
void push(struct Stack* stack, char c) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack->arr[++stack->top] = c;
}

// Function to pop a character from the stack
char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        // Return null character or handle error appropriately
        return '\0'; 
    }
    return stack->arr[stack->top--];
}

// Function to reverse a string using a stack
void reverseString(char str[]) {
    int n = strlen(str);
    struct Stack stack;
    initStack(&stack);

    // Push all characters of the string onto the stack
    for (int i = 0; i < n; i++) {
        push(&stack, str[i]);
    }

    // Pop characters from the stack back into the original string
    for (int i = 0; i < n; i++) {
        str[i] = pop(&stack);
    }
}

// Driver code
int main() {
    char str[MAX_SIZE] = "DATA"; 

    printf("Original string: %s\n", str);

    // Reverse the string
    reverseString(str);

    // Print the reversed string
    printf("Reversed string: %s\n", str);

    return 0;
}