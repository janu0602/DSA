#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5
#define NAME_SIZE 50

typedef struct {
    char doc_name[NAME_SIZE];
} Document;

typedef struct {
    Document items[MAX];
    int front;
    int rear;
} PrinterQueue;

// Initialize the queue to an empty state
void initQueue(PrinterQueue *q) {
    q->front = -1;
    q->rear = -1;
}

// Check if the queue is full
int isFull(PrinterQueue *q) {
    return (q->rear == MAX - 1);
}

// Check if the queue is empty
int isEmpty(PrinterQueue *q) {
    return (q->front == -1 || q->front > q->rear);
}

// Add document to queue (Enqueue)
void addDocument(PrinterQueue *q) {
    if (isFull(q)) {
        printf("Queue Full! Cannot add more documents.\n");
        return;
    }
    if (q->front == -1) q->front = 0;
    q->rear++;
    printf("Enter document name: ");
    scanf("%s", q->items[q->rear].doc_name);
    printf("Document '%s' added to queue.\n", q->items[q->rear].doc_name);
}

// Print document (Dequeue)
void printDocument(PrinterQueue *q) {
    if (isEmpty(q)) {
        printf("Queue Empty! No documents to print.\n");
        return;
    }
    printf("Printing: %s... Done.\n", q->items[q->front].doc_name);
    q->front++;
}

// Display pending documents
void displayQueue(PrinterQueue *q) {
    if (isEmpty(q)) {
        printf("No documents in the printer queue.\n");
        return;
    }
    printf("\nCurrent Printer Queue:\n");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d. %s\n", i - q->front + 1, q->items[i].doc_name);
    }
}

int main() {
    PrinterQueue q;
    initQueue(&q);
    int choice;

    while (1) {
        printf("\n--- Printer Queue System ---\n");
        printf("1. Add Document\n");
        printf("2. Print Document\n");
        printf("3. Display Pending Documents\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addDocument(&q); break;
            case 2: printDocument(&q); break;
            case 3: displayQueue(&q); break;
            case 4: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}