#include <stdio.h>

#define SIZE 100   // Maximum size of the queue

// Define the queue structure
typedef struct queue {
    int items[SIZE];  // Array to store queue elements
    int front;        // Index of the front element
    int rear;         // Index of the rear element
} queue;

// Initialize queue with front and rear set to -1 (empty state)
void init_queue(queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Check if queue is empty
int isEmpty(queue *q) {
    return q->front == -1;  // (fixed bug: should be ==, not =)
}

// Check if queue is full
int isFull(queue *q) {
    return q->rear == SIZE - 1;
}

// Add an element to the queue (enqueue operation)
void enqueue(queue *q, int data) {
    if (isFull(q)) {
        printf("\nQueue is full!");
        return;
    }

    // If queue is empty, move front to 0
    if (isEmpty(q))
        q->front = 0; 

    // Increment rear and insert new element
    q->rear++;
    q->items[q->rear] = data;
}

// Remove and return the front element (dequeue operation)
int dequeue(queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1; // Indicate failure
    }

    int value = q->items[q->front]; // Store the front value

    // If queue has only one element, reset it to empty state
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        // Move front to the next element
        q->front++;
    }

    return value;
}

// Get the front element without removing it
int peek(queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->items[q->front];
}

// Display all elements in the queue
void display(queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

// Test the queue implementation
int main() {
    queue q;
    init_queue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    display(&q);

    printf("Dequeued: %d\n", dequeue(&q));
    display(&q);

    printf("Front item: %d\n", peek(&q));

    return 0;
}

