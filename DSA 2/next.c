#include <stdio.h>

// Function to find and print the next greater elements using a stack
void find_next_greater_element(int arr[], int n) {
    int stack[n]; // Stack to store indices
    int top = -1;

    for (int i = 0; i < n; i++) {
        // While stack is not empty and current element is greater than top element
        while (top != -1 && arr[stack[top]] < arr[i]) {
            printf("%d \u2192 %d\n", arr[stack[top]], arr[i]);
            top--;
        }
        // Push current index onto stack
        stack[++top] = i;
    }

    // Remaining elements in stack have no greater element to their right
    while (top != -1) {
        printf("%d \u2192 -1\n", arr[stack[top--]]);
    }
}

int main() {
    int arr[] = {4, 5, 2, 10, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    find_next_greater_element(arr, n);
    return 0;
}
