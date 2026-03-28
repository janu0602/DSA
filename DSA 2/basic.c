#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5 // Define the maximum size of the queue

int queue[MAX_SIZE];
int front = -1, rear = -1;

// Function prototypes
int isFull();
int isEmpty();
void enqueue(int data);
int dequeue();
void peek();
void display();

int main() {
    int choice, element;

    while (1) {
        printf("\n****** MENU ******\n");
        printf("1. Enqueue (Insert)\n");
        printf("2. Dequeue (Remove)\n");
        printf("3. Peek (Front Element)\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                enqueue(element);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }
    return 0;
}

// Check if the queue is full
int isFull() {
    return (rear + 1) % MAX_SIZE == front;
}

// Check if the queue is empty
int isEmpty() {
    return front == -1;
}

// Insert an element into the circular queue
void enqueue(int data) {
    if (isFull()) {
        printf("Queue overflow! Cannot insert the element %d.\n", data);
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear = (rear + 1) % MAX_SIZE;
    queue[rear] = data;
    printf("Element %d inserted into the queue.\n", data);
}

// Remove an element from the circular queue
int dequeue() {
    if (isEmpty()) {
        printf("Queue underflow! Cannot delete any element.\n");
        return -1;
    }
    int data = queue[front];
    printf("Element %d deleted from the queue.\n", data);
    if (front == rear) { // If only one element was present
        front = rear = -1;
    } else {
        front = (front + 1) % MAX_SIZE;
    }
    return data;
}

// Display the front element of the queue
void peek() {
    if (isEmpty()) {
        printf("Queue is empty, no front element to peek.\n");
    } else {
        printf("The front element is: %d\n", queue[front]);
    }
}

// Display all elements currently present in the queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    while (i != rear) {
        printf("%d ", queue[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d\n", queue[rear]); // Print the rear element
}