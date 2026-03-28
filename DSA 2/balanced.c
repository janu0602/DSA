#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Stack and top pointer initialization
char stack[MAX_SIZE];
int top = -1;

void push(char data) {
    if (top == MAX_SIZE - 1) return; // Overflow
    stack[++top] = data;
}

char pop() {
    if (top == -1) return '\0'; // Underflow
    return stack[top--];
}

// Check for matching parenthesis pairs
int is_matching_pair(char char1, char char2) {
    return (char1 == '(' && char2 == ')') ||
           (char1 == '[' && char2 == ']') ||
           (char1 == '{' && char2 == '}');
}

// Function to check if the expression is balanced
int isBalanced(char* text) {
    for (int i = 0; i < strlen(text); i++) {
        if (text[i] == '(' || text[i] == '[' || text[i] == '{') {
            push(text[i]); // Push opening brackets
        } else if (text[i] == ')' || text[i] == ']' || text[i] == '}') {
            if (top == -1 || !is_matching_pair(pop(), text[i])) {
                return 0; // Unbalanced
            }
        }
    }
    return top == -1; // Balanced if stack is empty
}

int main() {
    char expression[MAX_SIZE] = "(A+B)*(C-D)"; //
    if (isBalanced(expression)) {
        printf("Input: %s\nOutput: Balanced Expression\n", expression);
    } else {
        printf("Input: %s\nOutput: Not Balanced Expression\n", expression);
    }
    return 0;
}